#Libraries
import RPi.GPIO as GPIO
import time
import serial
 
#GPIO Mode (BOARD / BCM)
GPIO.setmode(GPIO.BCM)

####GAUCHE#### 
#set GPIO Pins
GPIO_TRIGGER_G = 20
GPIO_ECHO_G = 21
 
#set GPIO direction (IN / OUT)
GPIO.setup(GPIO_TRIGGER_G, GPIO.OUT)
GPIO.setup(GPIO_ECHO_G, GPIO.IN)

####AVANT#### 
#set GPIO Pins
GPIO_TRIGGER_A = 17
GPIO_ECHO_A = 18
 
#set GPIO direction (IN / OUT)
GPIO.setup(GPIO_TRIGGER_A, GPIO.OUT)
GPIO.setup(GPIO_ECHO_A, GPIO.IN)

####Droite#### 
#set GPIO Pins
GPIO_TRIGGER_D = 23
GPIO_ECHO_D = 24
 
#set GPIO direction (IN / OUT)
GPIO.setup(GPIO_TRIGGER_D, GPIO.OUT)
GPIO.setup(GPIO_ECHO_D, GPIO.IN)
 
def distance(GPIO_TRIGGER, GPIO_ECHO):
    # set Trigger to HIGH
    GPIO.output(GPIO_TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER, False)
 
    StartTime = 0
    StopTime = 0
    test = 0
    # save StartTime
    while GPIO.input(GPIO_ECHO) == 0:
        print(GPIO_TRIGGER)
        StartTime = time.time()
 
    # save time of arrival
    while GPIO.input(GPIO_ECHO) == 1:
        print("1")
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
 
    return distance


try:
    arduino = serial.Serial('/dev/ttyACM0')  # open serial port
    print("Conected to: "+ arduino.name)

except serial.serialutil.SerialException:
    raise AssertionError("The serial is not available")
except:
    raise AssertionError("Something went wrong with the serial")
 
if __name__ == '__main__': 
    try: 
        while True:
            print("im in")
            bit = arduino.read()
            print(bit)

            if(bit != ""):
                
                print("Bonjour")
                dist_G = distance(GPIO_TRIGGER_G, GPIO_ECHO_G)
                dist_A = distance(GPIO_TRIGGER_A, GPIO_ECHO_A)
                dist_D = distance(GPIO_TRIGGER_D, GPIO_ECHO_D)
                
                print ("Measured Distance Gauche = %.1f cm" % dist_G)
                print ("Measured Distance Avant = %.1f cm" % dist_A)
                print ("Measured Distance Droite = %.1f cm" % dist_D)
            
                min_dist =20
                
                if (dist_D > 35  and dist_A > 35 and dist_G > 35):
                    print('FINIIIII')
                    arduino.write(b'0')
                    time.sleep(1)
    
                elif (dist_D > min_dist):
                    
                    print('Droite')
                    arduino.write(b'1')
                    time.sleep(4)
                        
                    print('Avant')
                    arduino.write(b'2')
                    time.sleep(3)
                    
                elif (dist_A > 20):
                    
                    print('Avant')
                    arduino.write(b'2')
                    time.sleep(3)
                
                elif (dist_G > min_dist):
		    
                    print('Gauche')
                    arduino.write(b'3')
                    time.sleep(3)
                    
                    print('Avant')
                    arduino.write(b'2')
                    time.sleep(2)

                else:
                                        
                    print('Demi Tour')
                    arduino.write(b'4')

		    time.sleep(4)


        # Reset by pressing CTRL + C
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()
