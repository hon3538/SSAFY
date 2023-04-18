#!/usr/bin/python
# -*- coding:utf-8 -*-

import sys
import os
picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'pic')
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

import logging    
from time import sleep

import traceback
from waveshare_OLED import OLED_0in96
#96인치 OELD
from PIL import Image,ImageDraw,ImageFont
logging.basicConfig(level=logging.DEBUG)

try:
    disp = OLED_0in96.OLED_0in96()

    logging.info("\r 0.96inch OLED ")
    # Initialize library.
    disp.Init()
    # Clear display.
    logging.info("clear display")
    disp.clear()

    # Create blank image for drawing.
    image1=Image.new('1',(disp.width,disp.height),255)
    draw=ImageDraw.Draw(image1)
    font1=ImageFont.truetype(os.path.join(picdir,'Font.ttc'),18)
    font2=ImageFont.truetype(os.path.join(picdir,'Font.ttc'),24)

    #1 draw Point1
    draw.point((20,20)) # 점 하나 씩기
    draw.point([(0,0),(127,0),(0,63)]) # 점 여러개 찍기
    for i in range(10,60): draw.point((i,i)) # 점 반복해서찍어서 선만들기
    draw.line([(0,0),(127,0)]) # 두 점 연결하여 선만들기
    draw.text((20,0),'Waveshare',font=font1,fill=0) # 20,0 위치에 글씨쓰기
    disp.ShowImage(disp.getbuffer(image1))
    sleep(1)
except IOError as e:
    logging.info(e)
except KeyboardInterrupt:
    logging.info("ctrl+c")
    OLED_0in96.config.module_exit()
    exit()
    