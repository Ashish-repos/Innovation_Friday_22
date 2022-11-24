import serial
import time

s = serial.Serial("COM4", 9600)

for _ in range(1000):
    print(s.read(),'\t\t', time.time())