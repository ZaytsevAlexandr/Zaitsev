import RPi.GPIO as GPIO
import sys
import time
dac = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setmode(GPIO.BCM)
GPIO.setup(dac,GPIO.OUT)
def decimal2bin(a):
    return [int(i) for i in bin(a)[2:].zfill(8)]
val = 0
T = input('Enter your period: ')
if not T.isdigit():
    print('NAN')
    sys.exit()
step = 1
try:
    while (True):
        val+=step
        if val == 255 or val == 0:
            step = -step
        GPIO.output(dac, decimal2bin(val))
        time.sleep(int(T)/510)
except KeyboardInterrupt:
    print('  See you later')
finally:
    GPIO.output(dac, 0)
    GPIO.cleanup()
