from gtts import gTTS
import serial
from playsound import playsound
import os
import time
import threading as th
############## ERRORBYTE : ['DESCRIPTION TEXT', REPEAT TIME SECS, LAST EXEC TIME STAMP(INIT 0), CONTINUOUS REPEAT]
messagehash = { b'\x01':['ENGINE OVER SPEED',10,0,1],
                b'\x02':['FUEL LEVEL LOW',25,0,2],
                b'\x03':['HIGH EXHAUST TEMPERATURE',25,0,2],
                b'\x04':['HIGH ENGINE TEMPERATURE',10,0,1],
                b'\x05':['VEHICLE OVERLOADED',50,0,1]
}

errorList = list(messagehash.keys())
s = serial.Serial("COM4", 9600)
readbuff = []

def readSerial():
    global readbuff
    while(1):
        x = s.read()
        if not(x in readbuff) and (x in errorList):
            readbuff.append(x)

def readLoud():
    global readbuff
    while(1):
        if(len(readbuff) > 0):
            for r in readbuff:
                if((time.time() - messagehash[r][2]) > messagehash[r][1]):
                    messagehash[r][2] = time.time()
                    for _ in range(messagehash[r][3]):
                        tts = gTTS(messagehash[r][0])
                        tts.save('msg.mp3')
                        playsound('msg.mp3')
                        os.remove("msg.mp3")
                    idx = readbuff.index(r)
                    readbuff = readbuff[:idx] + readbuff[idx+1:]


t2 = th.Thread(target=readLoud)
t1 = th.Thread(target=readSerial)
t2.start()
t1.start()
t1.join()
t2.join()