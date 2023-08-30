import cv2
import numpy as np

cap=cv2.VideoCapture(0)
# yolov3.weights : yolov3의 훈련된 가중치를 저장하고 있는 이진 파일
# yolov3.cfg : yolov3의 네트워크 구성을 저장하고 있는 텍스트 파일
net = cv2.dnn.readNet("yolov3-tiny.weights","yolov3-tiny.cfg")
classes = []
with open("coco.names","r") as f:
    # 읽어온 coco파일을 공백라인을 제거하여 classes 배열 안에 넣는다
    # strip() : whitespace(띄어쓰기, 탭, 엔터)를 없애는 것, 중간에 끼어있는 것은 없어지지 않느다.
    classes = [line.strip() for line in f.readlines()] 
# 네트워크의 모든 레이어 이름을 가져와서 layer_names에 넣는다
# getLayerNames() : 네트워크의 모든 레이어 이름을 가져온다, YOLOv3에는 3개의 출력레이어(82, 94, 106)가 있다.
layer_names = net.getLayerNames()
# print(layer_names[35])
# 레이어 중 출력 레이어의 인덱스를 가져와서 output_layers에 넣는다
# getUnconnectedOutLayers() : 출력 레이어를 가져온다
output_layers = [ layer_names[i-1] for i in net.getUnconnectedOutLayers()]

# 클래스의 개수만큼 랜덤으로 BRG 배열을 생성한다. 한 사물 당 하나의 color만 사용할 수 있도록 구분해야한다.
# np.random.uniform(a,b) : random 모듈 안에 정의되어 있는 두 수 사이의 랜덤 한 소수를 리턴 시켜주는 함수이다.
colors = np.random.uniform(0,255, size=(len(classes), 3))

while cap.isOpened():
    # 이미지 가져오기
    ret, img = cap.read()
    # img = cv2.resize(img, None, fx=0.4, fy=0.4) # 이미지 크기를 재설정한다
    height, width, channels = img.shape # 이미지의 속성들을 넣는다.

    # 물체 감지
    # 이미지를 blob 객체로 처리한다.
    # cv2.dnn.blobFromImage(image, scalefactor=None, size=None, mean=None, swapRB=None, crop=None, ddepth=None)
    # scalefactor : 입력 영상 픽셀 값에 곱할 값. 기본값은 1 (0~1 사이로 정규화하여 지정해야한다)
    blob = cv2.dnn.blobFromImage(img, 0.00392, (416,416), (0, 0, 0), True, crop=False)
    # blob 객체에 setInput 함수를 적용한다
    net.setInput(blob)
    # output_layers를 네트워크 순방향으로 실행(추론)한다.
    outs = net.forward(output_layers)

    # 물체 인식 정보를 화면에 표시
    # 물체의 범위를 박스 형태로 정확하게 잡아주고 그 물체가 무엇인지 labeling 해줘야 한다
    # labeling하는 기준은 신뢰도가 0.5를 넘으면 물체라고 인식을 한다

    # 정보를 화면에 표시
    class_ids = [] # 인식한 사물 클래스 아이디를 넣는 배열
    confidences = [] # 0에서 1까지 사물 인식에 대한 신뢰도를 넣는 배열
    boxes = [] # 사물을 인식해서 그릴 상자에 대한 배열
    for out in outs:
        for detection in out:
            scores = detection[5:]
            class_id = np.argmax(scores) # scores 중에서 최대값을 색인하여 class_id에 넣는다.
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
                confidences.append(float(confidence))
                class_ids.append(class_id)
            print("class_id : ",class_id,"  confidence : ",confidence)

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
            cv2.putText(img, label, (x, y+30), font, 3, color, 3) # yolo에서 학습된 사물의 명칭을 출력한다
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    cv2.imshow("image",img)


cv2.destroyAllWindows()
        
                    