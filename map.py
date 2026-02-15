import serial
from PIL import Image, ImageDraw

ser = serial.Serial('/dev/ttyACM0', 9600)

def add_marker(x, y, index):
    try:
        with Image.open(f"map{index}.png") as img:
            img = img.convert("RGBA")
            draw = ImageDraw.Draw(img)
            
            # Define circle size (radius)
            r = 20 
            # Draw circle centered at (x, y)
            # Coordinates are (left, top, right, bottom)
            draw.ellipse((x-r, y-r, x+r, y+r), fill=(255, 0, 0, 180), outline="white")
            
            img.save(f"map{index+1}.png")
            print(f"Marker placed at: {x}, {y}")
            
    except Exception as e:
        print(f"Error: {e}")

print("Listening for coordinates...")

loopCount = 0

while True:
    if loopCount >= 10: # creates up to 10 markers
        break

    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        
        # Check if the line starts with our keyword
        if line.startswith("MAP:"):
            # Strip "DETECTED:" and split by the comma
            raw_coords = line.replace("MAP:", "")
            try:
                x_str, y_str = raw_coords.split(",")
                add_marker(int(x_str), int(y_str), loopCount)
                loopCount+=1
            except ValueError:
                print("Received messy data, skipping...")