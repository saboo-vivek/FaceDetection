# FaceDetection

## Project Overview
**This project captures video input from a webcam, detects human faces in real-time using OpenCV's Haar Cascade classifier, and displays the live feed with detected faces in a GUI window. The feed will show rectangles around the faces.**

## Steps to Run the Application
1. Requirements
OpenCV installed on your system.
Visual Studio (or another C++ IDE).
Haar Cascade classifier (haarcascade_frontalface_default.xml file).
2. Setup Instructions
* Download OpenCV: Install OpenCV from the official OpenCV website and set it up in your development environment.
* Download Haar Cascade Classifier: Download the haarcascade_frontalface_default.xml from the OpenCV GitHub repository.
* Create a Visual Studio Project:
* Create a new Visual Studio C++ console project.
* Add the OpenCV include directories, lib directories, and set up the opencv_world490.lib as mentioned in the code section.
* Place haarcascade_frontalface_default.xml in the Same Folder as your project executable.
* Build and Run: After setting up, build the project and run the application. The GUI window will open, showing a live webcam feed with face detection.
3. Running the Application
Run the application, and your webcam feed will appear in a window titled "Webcam Feed - Face Detection".
As the application runs, it will detect faces and draw a green rectangle around each face.

To exit the program, press the 'q' key.
