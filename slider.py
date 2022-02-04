from collections import deque
import numpy as np
import argparse

from numpy.core.numeric import True_
import imutils
import cv2
import requests
import json
import time
import sys
import select
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

sys.path.insert(0,'/home/pi/A_localGit/FlightScopeSlider/trinamic')
# sys.path.insert(0, './trinamic')  # create path to trinamic driver
import trinamic_pg as pg
import RPi.GPIO as GPIO

# PIN DEFINITIONS 
MODE = 27 # toggle switch for manual / auto mode
MANUAL_DIR = 22  # manual mode side   left/ right
LED_1 = 26  # led for indicating how many balls are present in view. 

# current_tray_position = 0 

HEADLESS = True
TX_DATA = True  # set to enable/disable tranmsion of data.
# TARGET_IP_ADDR = '192.168.1.73'
TARGET_IP_ADDR = 'localhost'

# flag to reload config
reload_config = True
led1_checkcnt = 0 # counter to check led state
global_keypoint_count = 0  # global keypoint counter updaed on every capture.
led1_time_index = 0  # where in the array we are at.. 

current_slide_region = 0
#led1_check_threshold = 100000
#led1_state = False



class MyHandler(FileSystemEventHandler):
    
    def __init__(self, callback):
        self.callback = callback
        
    def on_modified(self, event):
        if 'config.json' in event.src_path: #   == "./config.json":
            self.callback()

        print(f'event type: {event.event_type}  path : {event.src_path}')


def callback():
    global reload_config
    reload_config = True
    print("config.json file was modified*************************")
        

def initIO():
    print('IO Initialization Start')
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(MODE, GPIO.IN)
    GPIO.setup(MANUAL_DIR, GPIO.IN)
    GPIO.setup(LED_1, GPIO.OUT)
    print('IO Initialization Complete')

    #
#
def cleanupIO(): 
    print('IO Cleanup started')
    GPIO.cleanup() # run this just to make sure 
#
#
def ismanualmode():
    ismanual = GPIO.input(MODE)
    return not ismanual
#
def manualpositionleft():
    posleft = GPIO.input(MANUAL_DIR)
    return not posleft  

def blinkLED1():
    led1_keyppoint_0 = [False,False,False,False,False,False,False,False,False,False]
    led1_keyppoint_1 = [False,False,False,False,False,False,False,False,False,True]
    led1_keyppoint_2 = [False,False,False,False,False,False,False,True,False,True]
    led1_keyppoint_other = [False,False,False,False,False,True,False,True,False,True]

    # global led1_state
    global led1_checkcnt
    # global led1_check_threshold
    global led1_time_index

    led1_checkcnt = led1_checkcnt + 1
    if led1_checkcnt > 20000:
        led1_checkcnt = 0
        # move to next time index 
        led1_time_index = led1_time_index + 1
        if led1_time_index > 9:  
            led1_time_index = 0
        
        state = False
        if global_keypoint_count == 0:
            state = led1_keyppoint_0[led1_time_index]   
        elif global_keypoint_count == 1:
            state = led1_keyppoint_1[led1_time_index]   
        elif global_keypoint_count == 2:
            state = led1_keyppoint_2[led1_time_index]
        elif global_keypoint_count > 2:
            state = led1_keyppoint_other[led1_time_index]   
        
        GPIO.output(LED_1, state)

def keypointMatches(lastpoint, thispoint):
    # bounderies
    # format(i.pt[0],".2f")
    min_x = lastpoint.pt[0] - 2
   #  min_x = lastpoint['x'] - 2.0
    max_x = lastpoint.pt[0] + 2.0
    min_y = lastpoint.pt[1] - 2
    max_y = lastpoint.pt[1] + 2
    min_size = lastpoint.size - 2
    max_size = lastpoint.size + 2
 
    if thispoint.pt[0] <= max_x and thispoint.pt[0] >= min_x:  #x location 
        if thispoint.pt[1] <= max_y and thispoint.pt[1] >= min_y:  # Y location
            if thispoint.size <= max_size and thispoint.size >= min_size:  # Y location
                return True

    return False



def goToManualPosition(posleft):
    global current_slide_region

    if posleft == True:
        pg.gotoRegion(2) 
        current_slide_region = 2     
        print("Moved manual left position")
    else:
        pg.gotoRegion(0)
        current_slide_region = 0
        print("Moved manual right position")


# # construct the argument parse and parse the arguments
#ap = argparse.ArgumentParser()
#ap.add_argument("-v", "--video",
# 	help="path to the (optional) video file")
#ap.add_argument("-b", "--buffer", type=int, default=64,
# 	help="max buffer size")
# args = vars(ap.parse_args())

# def dump(obj):
#  for attr in dir(obj):
#    print("obj.%s = %r" % (attr, getattr(obj, attr)))

# if a video path was not supplied, grab the reference
# to the webcam
#if not args.get("video", False):
camera = cv2.VideoCapture(0)
 
# otherwise, grab a reference to the video file
#else:
#camera = cv2.VideoCapture(args["video"])

   
if __name__ == "__main__":

    event_handler = MyHandler(callback)
    observer = Observer()
    observer.schedule(event_handler, path='/home/pi/A_localGit/FlightScopeSlider', recursive=False)
    observer.start()

    # init hardware
    initIO()
    pg.initDriver()
    pg.findHome()
    pg.setNormalRunModeParams()
    # pg.gotoRegion(2)

    # main loop
    
    modeswitch_debounce = 0
    positionswitch_debounce = 0

    MANUAL_MODE = ismanualmode()
    POSITION_LEFT = manualpositionleft()
    
    print("Mode: %s" % ("Auto", "Manual")[MANUAL_MODE])
    print("MM Position: %s" % ("Right", "Left")[POSITION_LEFT])

    # the slide is now at home (right), 
    # if mm pos is left, move it to the left on boot. 

    if MANUAL_MODE == True and POSITION_LEFT == True:
         goToManualPosition(POSITION_LEFT)

    xstart=0
    xend=600
    ystart=120
    yend=280
    params = {}
    mycfg = {}
    loopcount = 0

    capture_img_interval = 0

    last_single_keypoint = None  # storepoint to compare the last keypoint to.
    single_keypoint_match_count = 0 # count how many time we have a close match on a point,
    settle_counter = 0   # used to create time between single kp measurments. 
    
    while True:

        blinkLED1()

        loopcount += 1
        if loopcount > 500000:
            loopcount = 0
            # print("manual/auto :  %s " % MANUAL_MODE)
        # check for mode switch (manual vs auto) 
        if modeswitch_debounce > 0:
            modeswitch_debounce -= 1

        temp = ismanualmode()  # check if we are in manual mode 
        # print("temp = %s" % temp)
        # print("msd = %s" % modeswitch_debounce)

        if temp != MANUAL_MODE and modeswitch_debounce <= 0: # if its changed... 
            MANUAL_MODE = temp
            if MANUAL_MODE == False:
                modeswitch_debounce = 2
            else:
                 # Go to switch position when going to manual. 
                goToManualPosition(POSITION_LEFT)
                modeswitch_debounce = 1000

                if HEADLESS == False:
                    cv2.destroyAllWindows() # added to close show window, may need headless. 

            print("Mode Switched To: %s" % ("Auto", "Manual")[MANUAL_MODE])
           #  print("manual/auto  switched to:  %s " % modename)

        # check for manual postion change 
        if MANUAL_MODE == True: # if in manual mode, 
            if modeswitch_debounce <= 0: # if in manual and past debounce.. 

                if positionswitch_debounce > 0:
                    positionswitch_debounce-=1

                temppos = manualpositionleft()
                if temppos != POSITION_LEFT and positionswitch_debounce <= 0:
                    positionswitch_debounce = 1000
                    POSITION_LEFT = temppos
                    goToManualPosition(POSITION_LEFT)

        else: # IF AUTO MODE ***********************************************
            POSITION_LEFT = manualpositionleft()  # added 1/28,  always update this when in auto in case we switch back to manual 
           

            # ALGO
            # take framecapture, divide by 3...
            # if single object in region  and is still, move slide to that region...start countdown..
            # after countdown (5 sec) start over.. if region has changed,  move slide. ..
            # repeate... 
            if reload_config == True:
                print("loading config")
                reload_config = False
                f = open('/home/pi/A_localGit/FlightScopeSlider/config.json')
                mycfg = json.load(f)
                f.close()
                xstart=mycfg['crop_x_start']
                xend=mycfg['crop_x_end']
                ystart=mycfg['crop_y_start']
                yend=mycfg['crop_y_end']
                # create params object now. 
                params = cv2.SimpleBlobDetector_Params()

                params.filterByColor = mycfg['filterByColor']
                params.blobColor = mycfg['blobColor']
                params.minThreshold = mycfg['minColor']
                params.maxThreshold = mycfg['maxColor']
                
                params.filterByArea = mycfg['filterByArea']
                params.maxArea = mycfg['maxArea']
                params.minArea = mycfg['minArea']
                params.filterByCircularity = mycfg['filterByCircularity']
                params.minCircularity = mycfg['minCircularity']
                params.maxCircularity = 1

                params.filterByConvexity = mycfg['filterByConvexity']
                params.minConvexity = mycfg['minConvexity']
                params.maxConvexity = mycfg['maxConvexity']
                params.filterByInertia = mycfg['filterByInertia']
                params.minInertiaRatio = mycfg['minInertiaRatio']
                # added 1/1/21 cleanup 
                if HEADLESS == False:
                    cv2.destroyAllWindows()


            # grab the current frame
            (grabbed, frame) = camera.read()
            # frame = imutils.rotate(frame, angle=180)
            orig = frame

            width = 640
            height = 480
            dim = (width, height)
            resized = cv2.resize(orig, dim, interpolation = cv2.INTER_AREA)

            cropped = resized[ystart:yend, xstart:xend]
            
           
            (B, G, R) = cv2.split(cropped)

            detector = cv2.SimpleBlobDetector_create(params)
            # Detect blobs.,  only on Blue channel 
            gray = cv2.cvtColor(cropped, cv2.COLOR_BGR2GRAY)
            # keypoints = detector.detect(gray)
            keypoints = detector.detect(B)
            # if more than 0 points detected.  
            global_keypoint_count = len(keypoints)  # set global count 

            # calc regions now 
            frame_width = xend-xstart
            region_size = int(frame_width/3)
            r0_start = 0
            r0_end = r0_start + region_size
            r1_start = r0_end + 1
            r1_end = r1_start + region_size
            r2_start = r1_end + 1
            r2_end = r2_start + region_size

            capture_image = False

            if len(keypoints) > 0:

                holder = []  # array of objects 

                for i in keypoints:
                    obj = {};
                    obj['x'] = format(i.pt[0],".2f")
                    obj['y'] = format(i.pt[1],".2f")
                    obj['size'] = format(i.size,".2f")
                    holder.append(obj)
                   
                  # Questions
                  # has kp shown up on the last x number of samples.. in a row,  
                  # is the kp moving,  if its the same kp... 

                    # average number of points.. 
                # keypoint_counts.pop(0)
                # keypoint_counts.append(len(keypoints))    
                # keypoint_loopcnt = keypoint_loopcnt + 1
                # if keypoint_loopcnt > 20:
                #     keypoint_loopcnt = 0
                #     print("keypoint count avg: %d" % (sum(keypoint_counts)/len(keypoint_counts)))        
                #print(data)
                # print(len(keypoints))
                
            
                # MAIN LOGIC #############################################
                if settle_counter > 0:  # dec settle counter 
                    settle_counter = settle_counter - 1

                if len(keypoints) == 1:
                    # y = json.dumps(holder[0])
                    # print(y)
                    # compare to last one, if clode inc counter. 
                    if last_single_keypoint == None:
                        last_single_keypoint = keypoints[0]
                        single_keypoint_match_count = 0
                    else: 
                        if keypointMatches(last_single_keypoint, keypoints[0]) == True:
                            single_keypoint_match_count = single_keypoint_match_count + 1  # inc match count 
                        else:
                            single_keypoint_match_count = 0

                    last_single_keypoint = keypoints[0] # store this single point.. as the last.. 

                else:
                    single_keypoint_match_count = 0
                    last_single_keypoint = None     


                if len(keypoints) == 1 and settle_counter <= 0 and single_keypoint_match_count >= 3:  
                    print("got 1 kp, 3+ in a row processing cycle logic")
                    print("spkm: %d "% single_keypoint_match_count)
                    single_keypoint_match_count = 0 # reset counter,,, 
                    
                    settle_counter = 40 # set settle counter 
                    ball_x_position = keypoints[0].pt[0]
                    ball_region = 0
                    

                    #what region is the keypoint in? 
                    if ball_x_position >= r0_start and ball_x_position <= r0_end:
                        ball_region = 0
                    elif ball_x_position >= r1_start and ball_x_position <= r1_end:
                        ball_region = 1
                    elif ball_x_position >= r2_start and ball_x_position <= r2_end:
                        ball_region = 2


                    if current_slide_region != ball_region:  # if region has changed.. 
                        # need to move the slide... 
                        print("ball has moved to region  %d " % ball_region)
                        pg.gotoRegion(ball_region) 
                        capture_image = True
                        current_slide_region = ball_region
                        settle_counter = 80
                        

                # END region LOGIC ##############################################

                # send over data to node ##############################################
                if TX_DATA == True:
                    try:
                        api_url = "http://"+TARGET_IP_ADDR+":3000/setkeypoints"
                        response = requests.post(api_url, json=holder, timeout=1)      
                    except requests.exceptions.RequestException as e: 
                        print("http error" ) 
                
            
            # Draw detected blobs as red circles.
            # cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS ensures the size of the circle corresponds to the size of blob
            
            im_with_keypoints = cv2.drawKeypoints(cropped, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS) 
            im_with_keypoints = cv2.line(im_with_keypoints, (r0_start, 10), (r0_start, 40), (0, 255, 0), thickness=1)
            im_with_keypoints = cv2.line(im_with_keypoints, (r1_start, 10), (r1_start, 40), (0, 255, 0), thickness=1)
            im_with_keypoints = cv2.line(im_with_keypoints, (r2_start, 10), (r2_start, 40), (0, 255, 0), thickness=1)
            im_with_keypoints = cv2.line(im_with_keypoints, (r2_end, 10), (r2_end, 40), (0, 255, 0), thickness=1)

  
            if HEADLESS == False:
                cv2.imshow("Keypoints", im_with_keypoints)   
    
            if capture_image == True:  
                capture_img_interval = 0
                cv2.imwrite('/home/pi/A_localGit/FlightScopeSlider/Configurator/public/images/calimage1.jpg', im_with_keypoints)
  
            capture_img_interval = capture_img_interval + 1
            if capture_img_interval > 750:
                capture_img_interval = 0
                cv2.imwrite('/home/pi/A_localGit/FlightScopeSlider/Configurator/public/images/calimage2.jpg', im_with_keypoints)
  




            key = cv2.waitKey(1) & 0xFF
            # if the 'q' key is pressed, stop the loop
            if key == ord("q"):
                break
    
            
    # cleanup the camera and close any open windows
    # observer.join()
    pg.cleanupDriver()
    
    cleanupIO()
    observer.stop()
    camera.release()
    cv2.destroyAllWindows()
