import serial
import RPi.GPIO as GPIO
import time

ser=serial.Serial("/dev/ttyACM0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600
def blink(pin):


    GPIO.output(pin,GPIO.HIGH)  
    time.sleep(1)  
    GPIO.output(pin,GPIO.LOW)  
    time.sleep(1)  
    return

GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)
GPIO.output(11,GPIO.LOW)

while True:
    print("coucou")
    #blink(11)
    
    read_ser=ser.readline()
    print(read_ser)
    
    if(read_ser==b'Hello From Arduino!\r\n'):
        print("hi")
        blink(11)

