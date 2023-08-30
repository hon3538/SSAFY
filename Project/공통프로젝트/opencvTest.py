import cv2
import dlib
#from imutils import face_utils, resize
import numpy as np

#cam설정, 0번 웹캠
cam=cv2.VideoCapture(0)

if not cam.isOpened() :
    print("Could not open webcam")
    exit()

#iamge frame 설정
width=320
height=240

while cam.isOpened():
    ret, img = cam.read()

    if ret:
        cv2.imshow("test", img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cam.release()
cv2.destroyAllWindows()