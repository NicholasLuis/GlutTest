# These are the instructions for getting glut to work on your computer
## Note: This is for WINDOWS COMPUTERS


## First

Downlaod freeglut here: https://www.transmissionzero.co.uk/software/freeglut-devel/ (specifically the MSVC Package).
This is the open-source version. glut is decades old and out of date so it might not work with your computer

Extract the files.


## Second

### Find the freeglut.dll and freeglut.lib files and copy it into your project folder (one of each)

Note: There are folders titled "x64". Use these files instead if your operating system is 64-bit

Add this to the bottom of your CMakeLists.txt:
```
target_link_libraries(${CMAKE_PROJECT_NAME} "${CMAKE_SOURCE_DIR}/lib/freeglut.lib") # <-- CHANGE THE FILEPATH DEPENDING ON WHERE YOU COPIED THE FILES INTO. In this example, I have a folder called "lib"
```

Also, follow this file path: .../build/debug/

Copy and paste the .dll file into that folder

(note that your project needs to be built first such as by running build.sh)


### Find the .h files and copy it into your project folder

Add these .h files to the same folder as your other header files


## Third

In your code: #include "freeglut.h"
