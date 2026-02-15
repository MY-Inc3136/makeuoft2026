from gpiozero import Motor, OutputDevice
from time import sleep

# The TB6612 has a 'Standby' pin that must be HIGH to enable the chip
standby = OutputDevice(1)
standby.on()

# Setup Motor A
# forward=AIN1, backward=AIN2, enable=PWMA
motor_a = Motor(forward=23, backward=24, enable=13)

try:
    print("Testing Motor A...")

    # Full speed forward
    print("Forward at full speed")
    motor_a.forward(speed=1.0)
    sleep(2)

    # Full speed backward
    print("Backward at full speed")
    motor_a.backward(speed=1.0)
    sleep(2)

    # Speed Control (0.0 to 1.0)
    print("Ramping speed up...")
    for i in range(0, 11):
        speed_val = i / 10
        motor_a.forward(speed=speed_val)
        print(f"Speed: {speed_val}")
        sleep(0.5)

    motor_a.stop()
    print("Test Complete.")

except KeyboardInterrupt:
    motor_a.stop()
    print("Test stopped by user.")