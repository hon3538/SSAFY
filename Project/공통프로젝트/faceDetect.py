import cv2
import numpy as np
import mediapipe as mp
import matplotlib.pyplot as plt
import time
from mediapipe import solutions
from mediapipe.framework.formats import landmark_pb2
from mediapipe.tasks import python
from mediapipe.tasks.python import vision

class FaceDetect:
    _RIGHT_EYE_TOP=159
    _RIGHT_EYE_BOTTOM=145
    _RIGHT_IRIS_TOP=470
    _RIGHT_IRIS_BOTTOM=472
    _LEFT_EYE_TOP=386
    _LEFT_EYE_BOTTOM=374
    _LEFT_IRIS_TOP=475
    _LEFT_IRIS_BOTTOM=477
    _LEFT_EYE_BLINK=9
    _RIGHT_EYE_BLINK=10
    _SLEEP_STANDARD_SCORE=0.9
     
def __init__(self):
    self.interval=0.1
    #mediapipe face landmark setting
    self.model_path = 'face_landmarker.task'
    self.BaseOptions = mp.tasks.BaseOptions
    self.FaceLandmarker = mp.tasks.vision.FaceLandmarker
    self.FaceLandmarkerOptions = mp.tasks.vision.FaceLandmarkerOptions
    self.VisionRunningMode = mp.tasks.vision.RunningMode
    self.options = self.FaceLandmarkerOptions(
        base_options = self.BaseOptions(model_asset_path=self.model_path),
        running_mode = self.VisionRunningMode.IMAGE,
        output_face_blendshapes=True
    )
    self.landmarker = vision.FaceLandmarker.create_from_options(self.options)

def isStudying(self,img) :
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=img)
    #Face landmarking
    face_landmarker_result = self.landmarker.detect(mp_image)
    #Visualize
    annotated_image = self._draw_landmarks_on_image(mp_image.numpy_view(), face_landmarker_result)
    cv2.cvtColor(annotated_image, cv2.COLOR_RGB2BGR)
    cv2.imshow('',annotated_image)
    time.sleep(self.interval)
    #감지되는 얼굴이 없으면 자리비움
    if(len(face_landmarker_result.face_landmarks)==0): 
        return False
    blendshape = face_landmarker_result.face_blendshapes[0]
    left_score= blendshape[self._LEFT_EYE_BLINK].score
    right_score = blendshape[self._RIGHT_EYE_BLINK].score
    #양쪽 눈 감고 있으면 자는 중
    if left_score + right_score> FaceDetect._SLEEP_STANDARD_SCORE :
        return False
    return True

def  _draw_landmarks_on_image(self, rgb_image, detection_result):
    face_landmarks_list = detection_result.face_landmarks
    annotated_image = np.copy(rgb_image)
    # Loop through the detected faces to visualize.
    for idx in range(len(face_landmarks_list)):
        face_landmarks = face_landmarks_list[idx]
        # Draw the face landmarks.
        face_landmarks_proto = landmark_pb2.NormalizedLandmarkList()
        face_landmarks_proto.landmark.extend([
            landmark_pb2.NormalizedLandmark(x=landmark.x, y=landmark.y, z=landmark.z) for landmark in face_landmarks
        ])
        solutions.drawing_utils.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks_proto,
            connections=mp.solutions.face_mesh.FACEMESH_TESSELATION,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp.solutions.drawing_styles
            .get_default_face_mesh_tesselation_style())
        solutions.drawing_utils.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks_proto,
            connections=mp.solutions.face_mesh.FACEMESH_CONTOURS,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp.solutions.drawing_styles
            .get_default_face_mesh_contours_style())
        solutions.drawing_utils.draw_landmarks(
            image=annotated_image,
            landmark_list=face_landmarks_proto,
            connections=mp.solutions.face_mesh.FACEMESH_IRISES,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp.solutions.drawing_styles
            .get_default_face_mesh_iris_connections_style())
    return annotated_image
    def faceTracking() :
        return 0
#lop
def main():
    cam=cv2.VideoCapture(0)

    if not cam.isOpened() :
        print("Could not open webcam")
        exit()

    width=1280
    height=1048
    cam.set(cv2.CAP_PROP_FRAME_WIDTH,width)
    cam.set(cv2.CAP_PROP_FRAME_HEIGHT,height)

    fd=FaceDetect()
    while cam.isOpened() :
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        
        ret, img = cam.read()
        if not ret:
            break
        
        result=fd.isStudying(img)
        if result :
            print("공부중")
        else :
            print("공부 안 하는중")


    #캠끄기  
    cam.release()
    cv2.destroyAllWindows()

if __name__=='__main__' :
    main()