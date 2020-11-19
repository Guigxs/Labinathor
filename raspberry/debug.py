# #Libraries
import time
import serial

try:
    arduino = serial.Serial('/dev/ttyACM0')  # open serial port linux
   # arduino = serial.Serial('COM8')  # open serial port windows
    print("Conected to: "+ arduino.name)

except serial.serialutil.SerialException:
    raise AssertionError("The serial is not available")
except:
    raise AssertionError("Something went wrong with the serial")
 
if __name__ == '__main__': 
    try: 
        while True:
            x = input("Give me a direction (0, 1, 2, 3, 4, 5): ")

            if (x == "0"):
                print("Writing 0")
                arduino.write(b'0')
            elif (x == "1"):
                print("Writing 1")
                arduino.write(b'1')
            elif (x == "2"):
                print("Writing 2")
                arduino.write(b'2')
            elif (x == "3"):
                print("Writing 3")
                arduino.write(b'3')
            elif (x == "4"):
                print("Writing 4")
                arduino.write(b'4')
            else:
                print("Error {} not in the the protocol!".format(x))
            
            time.sleep(3)
            print("\n--Recieved from arduino--\n{}\n-------------------------\n".format(arduino.read(arduino.inWaiting())))
        
    except KeyboardInterrupt: # Reset by pressing CTRL + C
        print("Measurement stopped by User")

