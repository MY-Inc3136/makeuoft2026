# THIS IS THE MAP SCRIPT AFTER SWITCHING TO ARDUINO

import serial
from PIL import Image, ImageDraw

# Update this path to match what you found in Step 4
ser = serial.Serial('/dev/ttyACM0', 9600)

def add_marker():
    try:
        # Make sure 'blank_map.png' is in the same folder as this script
        with Image.open("blank_map.png") as img:
            draw = ImageDraw.Draw(img)
            # Draw a 50x50 red circle
            draw.ellipse((100, 100, 150, 150), fill="red", outline="white")
            img.save("updated_map.png")
            print("Successfully saved updated_map.png")
    except FileNotFoundError:
        print("Error: blank_map.png not found in this folder.")

print("Listening for Arduino...")
while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        if "detected" in line:
            add_marker()
        break