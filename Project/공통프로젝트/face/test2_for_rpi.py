import cv2
import mediapipe as mp
from time import sleep
import math
import numpy as np

cap=cv2.VideoCapture(0)

height=240
width=320
cap.set(cv2.CAP_PROP_FRAME_WIDTH,width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT,height)
def resize_and_show(img):
    h, w = img.shape[:2]
    if h < w :
        img = cv2.resize(img,(width, math.floor(h/(w/width))))
    else:
        img = cv2.resize(img, (math.floor(w/(h/height)), height))
    cv2.imshow("img",img)

mp_face_mesh=mp.solutions.face_mesh
face_mesh=mp_face_mesh.FaceMesh(
    static_image_mode=True,
   #refine_landmarks=True,
    max_num_faces=2,
    min_detection_confidence=0.5
)

while True :
    ret, img = cap.read()
    img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results=face_mesh.process(img)
    #resize_and_show(img)

    if not results.multi_face_landmarks:
        continue

    for face_landmarks in results.multi_face_landmarks:
        landmark=face_landmarks.landmark[159]
        x=landmark.x*width
        y=landmark.y*height
        cv2.circle(img,(int(x),int(y)),1,(0,0,255),3)
        landmark=face_landmarks.landmark[145]
        x=landmark.x*width
        y=landmark.y*height
        cv2.circle(img,(int(x),int(y)),1,(0,0,255),3)
    #resize_and_show(img)
    cv2.imshow("img",img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
            break
cap.release()
cv2.destroyAllWindows()
