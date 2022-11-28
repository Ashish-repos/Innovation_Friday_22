from gtts import gTTS
import serial
from playsound import playsound
import os
import time
import threading as th
from tkinter import *
from tkinter import ttk, filedialog
import tkinter.messagebox

op = int(input('Language options...\n\
English - 1\n\
French - 2\n\
Mandrin - 3\n\
Portugese - 4\n\
Spanish - 5\n\
...\n\
Enter your options - '))

############## ERRORBYTE : ['DESCRIPTION TEXT', REPEAT TIME SECS, LAST EXEC TIME STAMP(INIT 0), CONTINUOUS REPEAT]
messagehash = { b'\x01':['FUEL STOP',30,0,1],
                b'\x02':['ENGINE OVER SPEED',20,0,1],
                b'\x03':['ENGINE IS IDLE GEAR UP',40,0,1],
                b'\x04':['ENGINE OIL TEMPERATURE IS HIGH',20,0,1],
                b'\x05':['ENGINE OIL TEMPERATURE IS HIGH',20,0,1],
                b'\x06':['FUEL PRESSURE TOO LOW',30,0,1],
                b'\x07':['FUEL PRESSURE TOO HIGH',30,0,1],
                b'\x08':['MACHINE LOAD AT 10 PERCENT',20,0,1],
                b'\x09':['MACHINE LOAD AT 20 PERCENT',20,0,1],
                b'\x0a':['MACHINE LOAD AT 30 PERCENT',20,0,1],
                b'\x0b':['MACHINE LOAD AT 40 PERCENT',20,0,1],
                b'\x0c':['MACHINE LOAD AT 50 PERCENT',20,0,1],
                b'\x0d':['MACHINE LOAD AT 60 PERCENT',20,0,1],
                b'\x0e':['MACHINE LOAD AT 70 PERCENT',20,0,1],
                b'\x0f':['MACHINE LOAD AT 80 PERCENT',20,0,1],
                b'\x10':['MACHINE LOAD AT 90 PERCENT',20,0,1],
                b'\x12':['MACHINE LOAD AT 100 PERCENT',20,0,1]

}

errorList = list(messagehash.keys())

lang_options = ['en','fr','zh-CN','pt','es']

for i in range(100):
    try:
        s = serial.Serial("COM"+str(i), 9600)
        break
    except:
        pass

s = serial.Serial("COM3", 9600)
readbuff = []

def readSerial():
    global readbuff
    while(1):
        x = s.read()
        print(x)
        if not(x in readbuff) and (x in errorList):
            readbuff.append(x)

def readLoud():
    global readbuff
    while(1):
        if(len(readbuff) > 0):
            print('speaking')
            for r in readbuff:
                if((time.time() - messagehash[r][2]) > messagehash[r][1]):
                    messagehash[r][2] = time.time()
                    for _ in range(messagehash[r][3]):
                        tts = gTTS(text = messagehash[r][0],lang=lang_options[op-1], slow = False)
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