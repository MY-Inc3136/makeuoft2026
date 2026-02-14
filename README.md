# makeuoft2026
Scavenging robot that detects areas of interest (e.g. animals, water source) and marks them on a graphical map, which it then sends in a text message.


The robot will detect areas using a camera and computer vision.
When the robot detects an area, it wil move towards that area and marks its location on a map. 

### Key Functions of the Robot
- Read in image data
- Categorise image
  - Point of interest
  - Garbage
- Move towards the point of interest
- Track the location of the point
- Output the location
- Repeat

### Map
The map may be deployed as an interactive web app. The robot will find points of interest and send them to the web app. The point of interest will then be indicated using a marker. The user may interact with the marker to find details about the point of interest. The web app will automatically refresh whenever it receives a new point of interest. The map will then be sent to the user through a text message.
