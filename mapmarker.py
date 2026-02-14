import cv2 # uses OpenCv library

# Load blank map
map_img = cv2.imread('blank_map.png')

# Coordinates
# Coordinates measured by the pixel. (0, 1) is in the first column and 2nd row of the image, going pixel by pixel.
# In OpenCV, (0, 0) is the top left corner of the img
pos_x = 0
pos_y = 0
# ^^^ READ COORDS FROM ROBOT
# For the robot, we can scale what counts as 1 unit everytime it moves to match the image

position = (pos_x, pos_y)

# Draw circle marker - most basic way to do it, but we could replace it later
# parameters: image, centre of circle coordinates, radius, BGR colour, thickness
cv2.circle(map_img, position, 10, (0, 0, 255), -1)

# Save map as a new image
cv2.imwrite('marked_map.png', map_img);
