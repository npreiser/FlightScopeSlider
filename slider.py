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
sys.path.insert(0, './trinamic')  # create path to trinamic driver
import trinamic_pg as pg
import RPi.GPIO as GPIO

# PIN DEFINITIONS 
MODE = 27 # toggle switch for manual / auto mode
MANUAL_DIR = 22  # manual mode side   left/ right
LED_1 = 26  # led for indicating how many balls are present in view. 

# current_tray_position = 0 

HEADLESS = False
TX_DATA = False  # set to enable/disable tranmsion of data.
# TARGET_IP_ADDR = '192.168.1.73'
TARGET_IP_ADDR = 'localhost'

# flag to reload config
reload_config = True
led1_checkcnt = 0 # counter to check led state
global_keypoint_count = 2  # global keypoint counter updaed on every capture.
led1_time_index = 0  # where in the array we are at.. 

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
    current_slide_region = 0
    pg.setNormalRunModeParams()
    # pg.gotoRegion(2)

    # main loop
    
    modeswitch_debounce = 0
    positionswitch_debounce = 0

    
    MANUAL_MODE = ismanualmode()
    POSITION_LEFT = manualpositionleft()
    print("Manual Mode: %s" % MANUAL_MODE)
    print("MM Position Left: %s" % POSITION_LEFT)


    xstart=0
    xend=600
    ystart=120
    yend=280
    params = {}
    mycfg = {}
    loopcount = 0

    # keypoint_loopcnt = 0
    # keypoint_counts = [0,0,0,0,0,0,0,0,0,0]

    settle_counter = 0   # used to create time between single kp measurments. 
    

    while True:

        # if select.select([sys.stdin,],[],[],0.0)[0]:
            # print("Have data!")
        #     cnt = 0
            # for line in sys.stdin:
            #     cnt += 1
            #     print("got line : %s "% line)
            #     print(cnt)
            #     line = str(line)
            #     if 'config' in line:
            #         reload_config = True

        # else:
            # print ("No data")
        blinkLED1()

        loopcount += 1
        if loopcount > 500000:
            loopcount = 0
            print("manual/auto :  %s " % MANUAL_MODE)
        # check for mode switch (manual vs auto) 
        if modeswitch_debounce > 0:
            modeswitch_debounce -= 1

        temp = ismanualmode()  # check if we are in manual mode 
        # print("temp = %s" % temp)
        # print("msd = %s" % modeswitch_debounce)

        if temp != MANUAL_MODE and modeswitch_debounce <= 0: # if its changed... 
            MANUAL_MODE = temp
            modename = "Manual"
            if MANUAL_MODE == False:
                modeswitch_debounce = 2
                modename = "Auto"
            else:
                pg.findHome()  # GO HOME when switched to manual mode
                current_slide_region = 0
                pg.setNormalRunModeParams() 
                modeswitch_debounce = 1000

            print("manual/auto  switched to:  %s " % modename)

        # check for manual postion change 
        if MANUAL_MODE == True: # if in manual mode, 
            if modeswitch_debounce <= 0: # if in manual and past debounce.. 

                if positionswitch_debounce > 0:
                    positionswitch_debounce-=1

                temppos = manualpositionleft()
                if temppos != POSITION_LEFT and positionswitch_debounce <= 0:
                    positionswitch_debounce = 1000
                    POSITION_LEFT = temppos
                    if POSITION_LEFT == True:
                        pg.gotoRegion(2) 
                        current_slide_region = 2     
                        print("Moved manual left position")
                    else:
                        pg.gotoRegion(0)
                        current_slide_region = 0
                        print("Moved manual right position")

        else: # IF AUTO MODE ***********************************************
            # temp = ismanualmode()  # check if we are in manual mode 
           

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
            
            # brt = -40
            # cropped[cropped < 255-brt] += brt
            #  hough circles ###################################################################
            
            # gray = cv2.cvtColor(cropped, cv2.COLOR_BGR2GRAY)
            # img = cv2.medianBlur(gray, 5)
            # cimg = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
            #                               #  img,  method    dp,  min Dist,   p1/p2 canny function params,    
            # circles = cv2.HoughCircles(img, cv2.HOUGH_GRADIENT,1, 100, param1=100,param2=300,minRadius=1,maxRadius=50)

            # if circles is not None:
            #     # print("got hough circles : ")             

            #     circles = np.uint16(np.around(circles))
            #     for i in circles[0, :]:
            #         cv2.circle(cropped, (i[0], i[1]), i[2], (0,255,0), 2)

            # END HOUGH CIRCLES ###################################################
            
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

            if len(keypoints) > 0:

                holder = []  # array of objects 

                for i in keypoints:
                    obj = {};
                    obj['x'] = format(i.pt[0],".2f")
                    obj['y'] = format(i.pt[1],".2f")
                    obj['size'] = format(i.size,".2f")
                    holder.append(obj)
                    # print(format(i.pt[0],".2f"))
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

                if len(keypoints) == 1 and settle_counter <= 0:  
                    print("got 1 kp, processing cycle logic")
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
            if HEADLESS == False:
                im_with_keypoints = cv2.drawKeypoints(cropped, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
                
                im_with_keypoints = cv2.line(im_with_keypoints, (r0_start, 10), (r0_start, 40), (0, 255, 0), thickness=1)
                im_with_keypoints = cv2.line(im_with_keypoints, (r1_start, 10), (r1_start, 40), (0, 255, 0), thickness=1)
                im_with_keypoints = cv2.line(im_with_keypoints, (r2_start, 10), (r2_start, 40), (0, 255, 0), thickness=1)
                im_with_keypoints = cv2.line(im_with_keypoints, (r2_end, 10), (r2_end, 40), (0, 255, 0), thickness=1)
               
                
                cv2.imshow("Keypoints", im_with_keypoints)   
              #   cv2.imshow("Keypoints", im_with_keypoints)    # Show keypoints
        
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
