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
from stepper import gohome,takesteps,ismanualmode,manualpositionleft,initIO,cleanupIO,goFarRightPostion,goFarLeftPostion



# setup file watcher
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
        
  


current_tray_position = 0 

HEADLESS = False
TX_DATA = True  # set to enable/disable tranmsion of data.
# TARGET_IP_ADDR = '192.168.1.73'
TARGET_IP_ADDR = 'localhost'

# flag to reload config
reload_config = True

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
    observer.schedule(event_handler, path='/home/pi/A_localGit/FlightScopeEyeball', recursive=False)
    observer.start()

    initIO()
    # main loop
    modeswitch_debounce = 0
    positionswitch_debounce = 0

    gohome()

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
                gohome()
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
                        goFarLeftPostion()
                        print("Moved manual left position")
                    else:
                        goFarRightPostion()
                        print("Moved manual right position")

        else: # IF AUTO MODE ***********************************************
            # temp = ismanualmode()  # check if we are in manual mode 
           
            if reload_config == True:
                print("loading config")
                reload_config = False
                f = open('/home/pi/A_localGit/FlightScopeEyeball/config.json')
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
            
            (B, G, R) = cv2.split(cropped)

            detector = cv2.SimpleBlobDetector_create(params)
            # Detect blobs.
            keypoints = detector.detect(B)
            # if more than 0 points detected.       
            if len(keypoints) > 0:

                holder = []  # array of objects 

                for i in keypoints:
                    obj = {};
                    obj['x'] = format(i.pt[0],".2f")
                    obj['y'] = format(i.pt[1],".2f")
                    obj['size'] = format(i.size,".2f")
                    holder.append(obj)
                    # print(format(i.pt[0],".2f"))
                    
                #print(data)
                # print(len(keypoints))
                

                # send over data to node ##############################################
                if TX_DATA == True:
                    try:
                        api_url = "http://"+TARGET_IP_ADDR+":3000/setkeypoints"
                        response = requests.post(api_url, json=holder, timeout=1)      
                    except requests.exceptions.RequestException as e: 
                        print("http error" ) 
                
            
                #  office cord .  535  ... 345 .... 175
                # 300 is dead center... +- 200 to each side. range = 100 : 300: 500
                # 
                # forward() # step forward... fixed ammount for now. 
            #  move = False
                """
                STEP_FACTOR = 100  # how many steps per pixel... 
                delta = 0
                # its inverted..  increase in pixel position.. move revers(ccw) .. 
                # map home(step = 0) to 535 x ball position.. 
                # take position and sub 535. 
                offset = 37
                temp = int(500+offset - i.pt[0])   # calc target position 
                direction = "R"
                
                if current_tray_position != temp:
                    print("target position %d" % temp) 
                
                if temp > current_tray_position:
                    delta = int(temp - current_tray_position)
                    direction = "F"
                elif temp < current_tray_position:   
                    delta = int(current_tray_position - temp)
                    direction = "R"
                else:
                    print("No need to move")
                
                
                if delta > 0:
                    print("delta: "+format(delta,".2f") + "   dir: " + direction) 
                    if direction == "R":
                        stepreverse(delta*STEP_FACTOR)
                        print("moved backward: ")
                        current_tray_position -= delta
                        print("current tray pos: %d" % (current_tray_position))
                    elif direction == "F":
                        stepforward(delta*STEP_FACTOR)
                        print("moved forward: ")
                        current_tray_position += delta
                        print("current tray pos: %d" % (current_tray_position))
                """               

            # Draw detected blobs as red circles.
            # cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS ensures the size of the circle corresponds to the size of blob
            if HEADLESS == False:
                im_with_keypoints = cv2.drawKeypoints(cropped, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
                cv2.imshow("Keypoints", im_with_keypoints)    # Show keypoints
        
            key = cv2.waitKey(1) & 0xFF
            # if the 'q' key is pressed, stop the loop
            if key == ord("q"):
                break
    
            
        
    # cleanup the camera and close any open windows
    # observer.join()
    cleanupIO()
    observer.stop()
    camera.release()
    cv2.destroyAllWindows()
