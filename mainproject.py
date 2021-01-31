from ultrab import valb
from ultraf import valf
import RPi.GPIO as GPIO
import time
from picamera import PiCamera
from servercode import sendit
GPIO.setmode(GPIO.BCM)
ledb=21
ledf=22
GPIO.setup(ledb,GPIO.OUT)
GPIO.setup(ledf,GPIO.OUT)
while True:
   try:
       x=valb()
       print(x)
       y=valf()
       print(y)
       if x<=100 or y<=100:
          print("got it")
          camera=PiCamera()
          camera.capture("pritam.jpg")
          print("captured")
          if x>=y:
             GPIO.output(ledb, True)
             time.sleep(5)
             GPIO.output(ledb, False)
          if y>=x:
             GPIO.output(ledf, True)
             time.sleep(5)
             GPIO.output(ledf, False)   
          sendit()
   except:
      GPIO.cleanup()
