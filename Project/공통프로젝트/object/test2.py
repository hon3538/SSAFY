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
    boxes = [] # 사물을 인식해서 그릴 상자에 대한 배열

    for out in outs:
        for detection in out:
            scores = detection[5:]
            # print(outs[0][0][5:])
            class_id = np.argmax(scores) # scores 중에서 최대값을 색인하여 class_id에 넣는다.
            if class_id != CELL_PHONE :
                continue
            confidence = scores[class_id] # scores 중에서 class_id에 해당하는 값을 confidence에 넣는다
            if confidence > 0.4 : # 만약 정확도가 0.5가 넘는다면 사물이 인식되었다고 판단
                # 객체 탐지
                center_x = int(detection[0]*width)
                center_y = int(detection[1]*height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)
                # 좌표
                x = int(center_x - w / 2)
                y = int(center_y - h / 2)
                boxes.append([x, y, w, h])
                confidences.append(round(float(confidence),3))
                class_ids.append(class_id)
            #print("class : ",classes[class_id],"  confidence : ",confidence)
    
    # 노이즈 제거
    # 같은 사물에 대해서 박스가 여러 개인 것을 제거하는 Non Maximum Suppresion 작업을 한다
    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)

    # 결과 이미지 출력
    # Font 종류 중 하나인 FONT_HERSHEY_PLAIN(작은 크기 산세리프 폰트)를 적용한다
    font = cv2.FONT_HERSHEY_PLAIN
    for i in range(len(boxes)):
        if i in indexes:
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]]) # 클래스 아이디 지정해둔 것을 label 변수에 저장
            color = colors[i] # 위에서 colors 배열에 색상을 넣어둔 것을 color에 저장
            cv2.rectangle(img, (x,y), (x+w,y+h),color,2) # 사각형을 그린다
            cv2.putText(img, label, (x, y+30), font, 2, color, 3) # yolo에서 학습된 사물의 명칭을 출력한다
            print(class_ids[i]," ",i)
            print(label," ",confidences[i])
            
            cv2.putText(img, str(confidences[i]), (x, y), font, 2, color, 3) # yolo에서 학습된 사물의 명칭을 출력한다
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    cv2.imshow("image",img)
    

cv2.waitKey(0)
cv2.destroyAllWindows()
        
                    