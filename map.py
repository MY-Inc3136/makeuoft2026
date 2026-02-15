# THIS IS THE MAP SCRIPT AFTER SWITCHING TO ARDUINO

import serial
from PIL import Image, ImageDraw

# Ensure your port matches your Ubuntu setup
ser = serial.Serial('/dev/ttyACM0', 9600)

def add_marker():
    try:
        # 1. Open and immediately copy into memory to release the original file
        with Image.open("blank_map.png") as original:
            img = original.copy().convert("RGB") 
            
        draw = ImageDraw.Draw(img)
        
        # 2. Draw the marker
        # Using a bright red circle
        draw.ellipse((100, 100, 150, 150), fill="red", outline="white")
        
        # 3. Save with a unique name or overwrite safely
        # Adding a tiny delay ensures the OS has time to breathe
        img.save("updated_map.png", "PNG")
        print("Done! Image saved successfully.")
        
    except Exception as e:
        print(f"Oops, something went wrong: {e}")

print("Listening for Arduino...")
while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        if "detected" in line:
            print("Arduino says: Object Detected!")
            add_marker()
            # Prevent 'double-triggering' if the Arduino sends multiple lines
            ser.reset_input_buffer()