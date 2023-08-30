import cv2
import numpy as np
from time import sleep
cap=cv2.VideoCapture(0)
net = cv2.dnn.readNet("yolov3-tiny.weights","yolov3-tiny.cfg")
classes = []
with open("coco.names","r") as f:
    classes = [line.strip() for line in f.readlines()] 
layer_names = net.getLayerNames()
output_layers = [ layer_names[i-1] for i in net.getUnconnectedOutLayers()]

colors = np.random.uniform(0,255, size=(len(classes), 3))


PERSON = 0
CELL_PHONE = 67
while cap.isOpened():
    ret, img = cap.read()
    # img = cv2.resize(img, None, fx=0.4, fy=0.4) # 이미지 크기를 재설정한다
    height, width, channels = img.shape # 이미지의 속성들을 넣는다.
    blob = cv2.dnn.blobFromImage(img, 0.00392, (416,416), (0, 0, 0), True, crop=False)
    net.setInput(blob)
    outs = net.forward(output_layers)
    
    # 정보를 화면에 표시
    class_ids = [] # 인식한 사물 클래스 아이디를 넣는 배열
    confidences = [] # 0에서 1까지 사물 인식에 대한 신뢰도를 넣는 배열

    for out in outs:
        for detection in out:
            scores = detection[5:]
            # print(outs[0][0][5:])
            class_id = np.argmax(scores) # scores 중에서 최대값을 색인하여 class_id에 넣는다.
            # if class_id != CELL_PHONE :
            #     continue
            confidence = scores[class_id] # scores 중에서 class_id에 해당하는 값을 confidence에 넣는다
            if confidence > 0.4 : # 만약 정확도가 0.5가 넘는다면 사물이 인식되었다고 판단
                confidences.append(round(float(confidence),3))
                class_ids.append(class_id)
            #print("class : ",classes[class_id],"  confidence : ",confidence)
    
    for i in range(len(confidences)) :
        print(classes[class_ids[i]]," ",confidences[i])
        
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    cv2.imshow("image",img)
    

cv2.waitKey(0)
cv2.destroyAllWindows()
        
                    