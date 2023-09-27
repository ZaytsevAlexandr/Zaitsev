import RPi.GPIO as GPIO
import sys
dac = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setmode(GPIO.BCM)
GPIO.setup(dac,GPIO.OUT)
def decimal2bin(a):
    return [int(i) for i in bin(a)[2:].zfill(8)]
try:
    while (True):
        a = input('INPUT 0 TO 255: ')
        if not a.isdigit():
            print('Error')
            continue
        if a == 'q':
            sys.exit()
        if int(a) < 0 or int(a) > 255:
            print('WRONG NUMBER, IT SUPPOSED TO BE LESS THAN 255 OR MORE THAN O')
            continue
        if int(a)%1 > 0:
            print('NOT AN INTEGER')
            continue
        GPIO.output(dac,decimal2bin(int(a)))
        voltage = int(a) * 3.3 / 256
        print("Your voltage: ","{:.2f}".format(voltage))
except ValueError:
    print('Value error')
except KeyboardInterrupt:
    print('  See you later')
finally:
    GPIO.output(dac, 0)
    GPIO.cleanup()