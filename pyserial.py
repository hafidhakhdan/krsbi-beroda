import serial
import time

ser = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = 1)
 
def write_read(c):
    ser.write(bytes(c, 'utf-8'))
    time.sleep(0.05)
    data = ser.readline()
    return data


while True:
    num = input("Enter a number: ")
    value = write_read(num)
    print(num)