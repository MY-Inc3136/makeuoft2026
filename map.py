import serial
from PIL import Image, ImageDraw

ser = serial.Serial('/dev/ttyACM0', 9600)

def add_marker(x, y):
    try:
        with Image.open("blank_map.png") as img:
            img = img.convert("RGBA")
            draw = ImageDraw.Draw(img)
            
            # Define circle size (radius)
            r = 20 
            # Draw circle centered at (x, y)
            # Coordinates are (left, top, right, bottom)
            draw.ellipse((x-r, y-r, x+r, y+r), fill=(255, 0, 0, 180), outline="white")
            
            img.save("updated_map.png")
            print(f"Marker placed at: {x}, {y}")
            
    except Exception as e:
        print(f"Error: {e}")

print("Listening for coordinates...")
while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        
        # Check if the line starts with our keyword
        if line.startswith("MAP:"):
            # Strip "DETECTED:" and split by the comma
            raw_coords = line.replace("MAP:", "")
            try:
                x_str, y_str = raw_coords.split(",")
                add_marker(int(x_str), int(y_str))
            except ValueError:
                print("Received messy data, skipping...")