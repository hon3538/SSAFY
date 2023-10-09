import cv2
import mediapipe as mp
from time import sleep
import math
import numpy as np

cap=cv2.VideoCapture(0)

height=480
width=480

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
    refine_landmarks=True,
    max_num_faces=2,
    min_detection_confidence=0.5
)

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
while True :    
    ret, img = cap.read()
    img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results=face_mesh.process(img)
    #resize_and_show(img)
    
    if not results.multi_face_landmarks:
        continue
    
    annotated_image =img.copy()
    for face_landmarks in results.multi_face_landmarks:
        mp_drawing.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks,
            connections=mp_face_mesh.FACEMESH_TESSELATION,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp_drawing_styles
            .get_default_face_mesh_tesselation_style())
        mp_drawing.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks,
            connections=mp_face_mesh.FACEMESH_CONTOURS,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp_drawing_styles
            .get_default_face_mesh_contours_style())
        mp_drawing.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks,
            connections=mp_face_mesh.FACEMESH_IRISES,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp_drawing_styles
            .get_default_face_mesh_iris_connections_style())
        print(mp_face_mesh)
    resize_and_show(annotated_image)
    if cv2.waitKey(1) & 0xFF == ord('q'):
            break
cap.release()
cv2.destroyAllWindows()