import serial

print("Starting script...")

try:
    arduino = serial.Serial('/dev/ttyACM1')  # open serial port
    print("Conected to: "+ arduino.name)

except serial.serialutil.SerialException:
    raise AssertionError("The serial is not available")
except:
    raise AssertionError("Something went wrong with the serial")

# Insert your script here
print(arduino.name)         # check which port was really used
arduino.write(b"42") # write a string


#arduino.close()
