import cv2
import mediapipe as mp
from time import sleep
import math
import numpy as np
mp_face_mesh=mp.solutions.face_mesh
face_mesh=mp_face_mesh.FaceMesh()

cap=cv2.VideoCapture(0)
while True :
    ret, img =cap.read()
    img=cv2.resize(img,(320, 240))
    img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    result = face_mesh.process(img)
    try:
        i=0
        for facial_landmarks in result.multi_face_landmarks:
            landmark=facial_landmarks.landmark[159]
            x1=landmark.x*320
            y1=landmark.y*240
            cv2.circle(img,(int(x1),int(y1)),1,(0,0,255),3)
            landmark=facial_landmarks.landmark[145]
            x2=landmark.x*320
            y2=landmark.y*240
            cv2.circle(img,(int(x2),int(y2)),1,(0,0,255),3)
            print(y2-y1)
    except Exception as e:
        print(e)
        
    cv2.imshow("img", img)
    if cv2.waitKey(1)&0xFF ==27 :
        break
cap.release()
cv2.destroyAllWindows()