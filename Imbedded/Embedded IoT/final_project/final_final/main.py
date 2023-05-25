from threading import Thread
from time import sleep

# lane detection
limit_left = 0
limit_right = 0

import cv2
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import math

cam=cv2.VideoCapture(0)

# camera frame
height=240
width=320
center=(width-5)/2 # -5는 왼쪽 영상 잡음 제거

# image crop
region_of_interest_vertices=[
    (0, height),
    (0, height*0.5),
    ((width-5)/2,0),
    (width-5, height*0.5),
    (width-5, height),

]

def processImage(img):
    img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    img = cv2.Canny(img,200,300)
    return img

# time thread를 만들어서 주기적으로 영상 캡쳐 
def thread_camera():
    ret, img= cam.read()
    #img = cv2.rotate(img, cv2.ROTATE_180)
    #print("thread_camera")
    cv2.imshow("test1",img)
    if ret :
        res=pipeline(img)
        #print("camera!!!")
        #sleep(1)
        cv2.imshow("test5", res)
        return True
    if cv2.waitKey(1) & 0xFF == ord('q'):
        return False
    
# 원하는 부분만 image 자름 
def region_of_interest(img, vertices):
    mask = np.zeros_like(img)
    match_mask_color =255 # this line altered for grayscale

    cv2.fillPoly(mask, vertices, match_mask_color)
    masked_image =cv2.bitwise_and(img,mask)
    return masked_image

# line 그리기 
def draw_lines(img, lines, color=[255, 0, 0], thickness=3):
    # If there are no lines to draw, exit.
    if lines is None :
        return img
    # Make a copy of the original image
    temp_img = np.copy(img)
    # Create a blank image that matches the original in size
    line_image=np.zeros(
        (
            img.shape[0],
            img.shape[1],
            3
        ),
        dtype=np.uint8,
    )
    # Loop over all lines and draw them on the blank image
    cnt = 0
    for line in lines:
        cnt+=1
        print(line)
        for x1, y1, x2, y2 in line:
            cv2.line(line_image, (x1, y1), (x2,int(y2)), color, thickness)
    # Merge the image with the lines onto the original
    temp_img = cv2.addWeighted(img, 0.8, line_image,1.0, 0.0)

    # Return the modified image.
    return temp_img

def pipeline(image):
    cannyed_image=processImage(image)
    cropped_image = region_of_interest(cannyed_image, np.array([region_of_interest_vertices], np.int32))
    #cannyed_image=processImage(cropped_image
    #cv2.imshow("test3",cannyed_image)
    '''
    lines=cv2.HoughLinesP(
        cropped_image,
        rho=6,
        theta=np.pi /60,
        threshold=160,
        lines=np.array([]),
        minLineLength=40,
        maxLineGap=25
    )
    '''
    lines=cv2.HoughLinesP(
        cropped_image,
        rho=2,
        theta=np.pi/60,
        threshold=30,
        lines=np.array([]),
        minLineLength=10,
        maxLineGap=10
    )
    
    left_line_x=[]
    left_line_y=[]
    right_line_x= []
    right_line_y= []
    if lines is None:
        return image
    for line in lines:
        for x1, y1, x2, y2 in line:
            slope =(y2-y1)/(x2-x1) # calculating the slope
            if math.fabs(slope) <0.5: # only consiger extreme slope
                print("extreme slope")
                #continue
                return image
            if slope <= 0 and x1<=width/2: # If the slope is negative, left group
                left_line_x.extend([x1,x2])
                left_line_y.extend([y1,y2])
            elif slope >0 and x1 > width/2: #otherwise,m right group
                right_line_x.extend([x1, x2])
                right_line_y.extend([y1, y2])
    
    
    #if len(left_line_x)==0 or len(left_line_y)==0 or len(right_line_x)==0 or len(right_line_y)==0:
    #    return image

    min_y = image.shape[0] * (2/5) # just below the horizon
    max_y = image.shape[0] # the bottom of the image
    
    
    poly_left=None
    poly_right=None
    line_image=image
    if len(left_line_x)!=0 and len(left_line_y)!=0:
        #print("left lines")
        poly_left =np.poly1d(np.polyfit(
            left_line_y,
            left_line_x,
            deg=1
        ))
        left_x_start = int(poly_left(max_y))
        left_x_end = int(poly_left(min_y))
        #print('left_x_start', left_x_start)
    if len(right_line_x)!=0 and len(right_line_y)!=0 :
        #print("right lines")
        poly_right = np.poly1d(np.polyfit(
            right_line_y,
            right_line_x,
            deg=1
        ))
        right_x_start = int(poly_right(max_y))
        right_x_end = int(poly_right(min_y))
    
    if poly_left!=None and poly_right!=None :
        #print("both")
        line_image = draw_lines(
            image,
        [[
            [left_x_start, max_y, left_x_end, min_y],
            [right_x_start, max_y, right_x_end, min_y],
        ]],
        
        thickness=5,
        )
        
        getPos([left_x_start, max_y, left_x_end, min_y], [right_x_start, max_y, right_x_end, min_y])

    elif poly_left!=None :
        #print("left")
        line_image=draw_lines(
            image,
        [[
            [left_x_start, max_y, left_x_end, min_y]
        ]],
        thickness=5,
        )
        getPos([left_x_start,max_y, left_x_end, min_y],[width,height,0,0])
    elif poly_right!=None :
        #print("right")
        line_image=draw_lines(
            image,
        [[
            [right_x_start, max_y, right_x_end, min_y],
        ]],
        thickness=5,
        )
        getPos([0,height,width,0],[right_x_start, max_y, right_x_end, min_y])
    else :
        #print("no222")
        return image

    print("success")
    return line_image

def getPos(lline, rline):
    lx1, ly1, lx2, ly2 = lline
    rx1, ry1, rx2, ry2 = rline
    lslope = (lx2 - lx1) / (ly2 - ly1)
    rslope = (rx2 - rx1) / (ry2 - ry1)

    global limit_left, limit_right
    limit_left = height * lslope
    limit_right = height * rslope
    print("limit_left:", limit_left)
    print("limit_right:", limit_right)

def lane_detect():
    if not cam.isOpened():
        print("Could not open cam")
        exit()
    #print('success')
    cam.set(cv2.CAP_PROP_FRAME_WIDTH,width)
    cam.set(cv2.CAP_PROP_FRAME_HEIGHT,height)
    while thread_camera():
        #print('thread')
        #sleep(3)        
        continue

    cam.release()

# Manual drive
from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor
from Raspi_PWM_Servo_Driver import PWM

mh = Raspi_MotorHAT(addr=0x6f) 
myMotor = mh.getMotor(2) #핀번호

servo = PWM(0x6F)
servo.setPWMFreq(60)  # Set frequency to 60 Hz

from bluetooth import *
MAC = "8C:CE:4E:9A:38:CA"
socket = BluetoothSocket(RFCOMM)

def getSpeed(x):
    if 1840 <= x <= 1880:
        speed = 0
        direction = Raspi_MotorHAT.RELEASE
    elif x < 1840:
        speed = 1840 - x * 100 / 1840
        direction = Raspi_MotorHAT.BACKWARD
    else:
        speed = (x - 1880) * 100 / (4095 - 1880)
        direction = Raspi_MotorHAT.FORWARD

    return speed, direction   

def getAngle(y):
    global limit_left, limit_right

    if limit_left > -90:
        if y < 500:
            angle = 200
        elif y > 3800:
            angle = (y - 1930) * 100 / (4095 - 1930) + 340
        else:
            angle = 430
    elif limit_right < 90:
        if y > 3800:
            angle = (y - 1930) * 100 / (4095 - 1930) + 340
        elif y < 500:
            angle = y * 150 / 1890
        else:
            angle = 200
    elif 1890 <= y <= 1930:
            angle = 340
    elif y < 1890:
        if y < 500:
            angle = y * 150 / 1890
        elif y > 3800:
            angle = (y - 1930) * 100 / (4095 - 1930) + 340
        else:
            angle = y * 150 / 1890
    else:
        if y < 500:
            angle = y * 150 / 1890
        elif y > 3800:
            angle = (y - 1930) * 100 / (4095 - 1930) + 340
        else:
            angle = (y - 1930) * 100 / (4095 - 1930) + 340

    return angle


def drive():

    try:
        while True:
            try:
                data = socket.recv(1024).decode('utf-8')
                x, y, b = map(int, data.split())
                #print("x:", x)
                #print("y:", y)
                #print("b:", b)

                speed, direction = getSpeed(x)
                angle = getAngle(y)

                #print("speed:", speed)
                #print("direction:", direction)
                #print("angle:", angle)
                #print()

                myMotor.setSpeed(int(speed))
                myMotor.run(int(direction))
                servo.setPWM(0, 0, int(angle))
            except KeyboardInterrupt:
                break

            except:
                continue

    finally:
        socket.close()
        myMotor.run(Raspi_MotorHAT.RELEASE)

def main():
    print('drive thread start...')
    thread_drive = Thread(target=drive)
    print('lane_detect start...')
    thread_lane_detect = Thread(target=lane_detect)
    global socket,MAC
    print('bluethooth conecting....')
    socket.connect((MAC, 1))
    print("bluetooth connected!")

    thread_drive.start()
    thread_lane_detect.start()

    thread_drive.join()
    thread_lane_detect.join()
    socket.close()
    print("end...")
    
if __name__ == '__main__':
    print("start...")
    main()

