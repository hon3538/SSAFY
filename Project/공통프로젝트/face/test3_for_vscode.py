import cv2
import mediapipe as mp
from time import sleep
import math
import numpy as np
from datetime import datetime

cap=cv2.VideoCapture(0)
height=240
width=320
cap.set(cv2.CAP_PROP_FRAME_WIDTH,width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT,height)

class Face:
    RIGHT_TOP=159
    RIGHT_BOT=145
    RIGHT_IN=133
    RIGHT_OUT=33
    LEFT_TOP=386
    LEFT_BOT=374
    LEFT_IN=362
    LEFT_OUT=263
    STATUS =["자는중","공부중","자리비움"]
    def __init__(self):
        self.mp_face_mesh=mp.solutions.face_mesh
        self.face_mesh=self.mp_face_mesh.FaceMesh(
            static_image_mode=True,
        #refine_landmarks=True,
            max_num_faces=2,
            min_detection_confidence=0.5
        )
        # sleep 판단 -> sliding window
        # 최근 30번 중 15번 이상 studying 이면 공부하고 있다고 판단
        
        # 0:sleep, 1:study, 2:not study
        self._times_length=30 # sliding window frame 크기
        self.status = [0, 0, self._times_length] # sliding winodw 안에 있는 각 status 개수
        self.recent_times=[2]*self._times_length # default (not study) 상태로 window를 다 채움
        self.head=1 # 맨앞 요소
        self.currentStatus = 2
        
    def getStatus(self, img) :
        ret = self._getStatus(img)
        if self.currentStatus != ret :
            now = datetime.now()
            print(now," ",self.STATUS[ret])
            self.currentStatus = ret 
                   
    def _getStatus(self, img) :
         # last time index와 현재 index 지정 
        headTime = self.head
        self.head = (headTime+1) % self._times_length
        current = headTime -1
        if current < 0 :
            current = self._times_length-1
            
        currentStatus = self._isStudying(img)
  
        lastStatus=self.recent_times[current]
        self.recent_times[current] = currentStatus
        if lastStatus != currentStatus :
            self.status[currentStatus] = self.status[currentStatus] + 1
            self.status[lastStatus] = self.status[lastStatus] - 1 

        if self.status[1] >= self._times_length / 2 :
            #공부중
            return 1
        elif self.status[0] >= self._times_length / 2 :
            #자는중
            return 0
        #자리비움
        return 2    
    
    def _isStudying(self, img) :
        img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    
        try:
            results=self.face_mesh.process(img).multi_face_landmarks[0]
            mesh_coord = self._landmarksDetection(img, results, True)
            
            if mesh_coord :
                ratio = self._blinkRatio(img, mesh_coord)
                #print("ratio : ", ratio)
                if ratio > 3.3 :
                    # 자는중
                    return 0
                else : 
                    # 공부중
                    return 1
        except Exception as e :
            # 자리비움
            return 2
            
        
    def _landmarksDetection(self, img, results, draw=False):
        h,w = img.shape[:2]
        # list[(x,y), (x,y)....]
        mesh_coord = results.landmark

        if draw :
            for p in mesh_coord :
                cv2.circle(img, (int(p.x*width),int(p.y*height)),1,(0,255,0), -1)
        return mesh_coord

    def _euclaideanDistance(self, p1, p2) :
        distance = math.sqrt((p2.x-p1.x)**2 + (p2.y-p1.y)**2)
        return distance

    def _blinkRatio(self, img, landmarks) :
        r_top=landmarks[self.RIGHT_TOP]
        r_bot=landmarks[self.RIGHT_BOT]
        r_in=landmarks[self.RIGHT_IN]
        r_out=landmarks[self.RIGHT_OUT]
        l_top=landmarks[self.LEFT_TOP]
        l_bot=landmarks[self.LEFT_BOT]
        l_in=landmarks[self.LEFT_IN]
        l_out=landmarks[self.LEFT_OUT]
        #print(r_top)
        # draw lines
        # cv2.line(img, (int(r_out.x*width),int(r_out.y*height)), (int(r_in.x*width),int(r_in.y*height)), utils.GREEN,2)
        # cv2.line(img, (int(r_top.x*width),int(r_top.y*height)), (int(r_bot.x*width),int(r_bot.y*height)), utils.GREEN,2)
        rh_dist = self._euclaideanDistance(r_out, r_in)
        rv_dist = self._euclaideanDistance(r_top, r_bot)
        lh_dist = self._euclaideanDistance(l_out, l_in)
        lv_dist = self._euclaideanDistance(l_top, l_bot)
        r_Ratio = rh_dist/rv_dist
        l_Ratio = lh_dist/lv_dist
        ratio = (r_Ratio+l_Ratio)/2

        return ratio
    def check(self, img) : 
        try:
            results=self.face_mesh.process(img).multi_face_landmarks[0]
            for result in results.landmark :
                x=result.x*width
                y=result.y*height
                cv2.circle(img,(int(x),int(y)),1,(0,0,255),3)
            '''
            landmark=results.landmark[self.RIGHT_TOP]
            x=landmark.x*width
            y=landmark.y*height
            cv2.circle(img,(int(x),int(y)),1,(0,0,255),3)
            landmark=results.landmark[self.RIGHT_BOT]
            x=landmark.x*width
            y=landmark.y*height
            cv2.circle(img,(int(x),int(y)),1,(0,0,255),3)
            '''
            return img
        except Exception as e :
            print(e)
            return img
    
def main():
    face=Face()
    while True :
        ret, img = cap.read()
        face.getStatus(img)
        img = face.check(img)
        cv2.imshow("img",img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        # sleep(0.1)
    cap.release()
    cv2.destroyAllWindows()

if __name__=='__main__' :
    main()
#test