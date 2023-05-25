import cv2
import time, threading
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import math

cam=cv2.VideoCapture(0)

# camera frame
height=240
width=320
center=(width-5)/2


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
	print("thread")
	if ret :
		print("true")
		res=pipeline(img)
		cv2.imshow("test", res)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		return

	threading.Timer(0.1, thread_camera).start()
	
def main():

	if not cam.isOpened():
		print("Could not open cam")
		exit()
	cam.set(cv2.CAP_PROP_FRAME_WIDTH,width)
	cam.set(cv2.CAP_PROP_FRAME_HEIGHT,height)
	thread_camera()

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
		return
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
	for line in lines:
		for x1, y1, x2, y2 in line:
			cv2.line(line_image, (x1, y1), (x2,int(y2)), color, thickness)
			print('x1: ',x1,' y1: ',y1)
			print('x2: ',x2,' y2: ',y2)
			print()
			#cv2.line(line_image, (x1, y1), (x1,int(y1)),color,thickness)
	# Merge the image with the lines onto the original
	temp_img = cv2.addWeighted(img, 0.8, line_image,1.0, 0.0)

	# Return the modified image.
	return temp_img

def pipeline(image):
	cannyed_image=processImage(image)
	cropped_image = region_of_interest(cannyed_image, np.array([region_of_interest_vertices], np.int32))
	#cannyed_image=processImage(cropped_image
	cv2.imshow("test3",cannyed_image)
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
		rho=1,
		theta=np.pi/60,
		threshold=30,
		lines=np.array([]),
		minLineLength=10,
		maxLineGap=6
	)

	left_line_x=[]
	left_line_y=[]
	right_line_x= []
	right_line_y= []
	print(type(lines))
	if lines is None:
		return image
	print('2 line')
	for line in lines:
		for x1, y1, x2, y2 in line:
			slope =(y2-y1)/(x2-x1) # calculating the slope
			if math.fabs(slope) <0.5: # only consiger extreme slope
				continue
			if slope <= 0: # If the slope is negative, left group
				left_line_x.extend([x1,x2])
				left_line_y.extend([y1,y2])
			else: #otherwise,m right group
				right_line_x.extend([x1, x2])
				right_line_y.extend([y1, y2])
	
	if len(left_line_x)==0 or len(left_line_y)==0 or len(right_line_x)==0 or len(right_line_y)==0:
		return image

	min_y = image.shape[0] * (2/5) # just below the horizon
	max_y = image.shape[0] # the bottom of the image

	poly_left =np.poly1d(np.polyfit(
		left_line_y,
		left_line_x,
		deg=1
	))
	left_x_start = int(poly_left(max_y))
	left_x_end = int(poly_left(min_y))

	poly_right = np.poly1d(np.polyfit(
		right_line_y,
		right_line_x,
		deg=1
	))
	right_x_start = int(poly_right(max_y))
	right_x_end = int(poly_right(min_y))

	line_image = draw_lines(
		image,
		[[
			[left_x_start, max_y, left_x_end, min_y],
			[right_x_start, max_y, right_x_end, min_y],
		]],
		thickness=5,
	)	
	return line_image
	


main()
while True:
	sleep(1)

cam.release()
cv2.destroyAllWindows()


