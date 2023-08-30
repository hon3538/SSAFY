#! /bin/bash

#용량 해결
sudo apt-get purge wolfram-engine
sudo apt-get purge libreoffice*
sudo apt-get clean
sudo apt-get autoremove

#설치
sudo apt-get update
sudo apt-get upgrade -y

sudo apt-get install build-essential cmake pkg-config -y

sudo apt-get install libjpeg-dev libtiff5-dev libjasper-dev libpng-dev -y

sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev -y
sudo apt-get install libxvidcore-dev libx264-dev -y
sudo apt-get install libfontconfig1-dev libcairo2-dev -y
sudo apt-get install libgdk-pixbuf2.0-dev libpango1.0-dev -y
sudo apt-get install libgtk2.0-dev libgtk-3-dev -y

sudo apt-get install libatlas-base-dev gfortran -y

sudo apt-get install libhdf5-dev libhdf5-serial-dev libhdf5-103 -y
sudo apt-get install python3-pyqt5 -y

pip3 install imutils
pip3 install opencv-contrib-python

echo "complete"
