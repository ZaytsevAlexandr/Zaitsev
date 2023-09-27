import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(21, GPIO.OUT)
dac = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setup(dac, GPIO.OUT, initial=GPIO.HIGH)
pwm = GPIO.PWM(21, 1000)
pwm.start(0)
try:
    while (True):
        DC = int(input('Input your Duty Cycle: '))
        pwm.ChangeDutyCycle(DC)
        print("Your value: ","{:.2f}".format(DC * 3.3 / 100))
except KeyboardInterrupt:
    print('  See you later')
except ValueError:
    print('Duty Cycle is used in procents (it cannot be more than 100)')
finally:
    GPIO.output(21, 0)
    GPIO.output(dac, 0)
    GPIO.cleanup()
