# FaceDetection

## Project Overview
**This project captures video input from a webcam, detects human faces in real-time using OpenCV's Haar Cascade classifier, and displays the live feed with detected faces in a GUI window. The feed will show rectangles around the faces.**

## Steps to Run the Application
1. Requirements
* OpenCV installed on your system.
* Visual Studio (or another C++ IDE).
* Haar Cascade classifier (haarcascade_frontalface_default.xml file).
  
2. Setup Instructions
* Download OpenCV: Install OpenCV from the official OpenCV website and set it up in your development environment.
  ** Download the OpenCV pre-built binaries and extract them.
  ** In Visual Studio, go to your project's properties:
  ** Include Directories: Add the OpenCV include folder (C:\opencv\build\include).
  ** Library Directories: Add the OpenCV lib folder (C:\opencv\build\x64\vc16\lib).
  ** Additional Dependencies: Add opencv_world4xx.lib (replace xx with your version).
  ** Make sure opencv_world4xx.dll (from C:\opencv\build\x64\vc16\bin) is in the executable directory.
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

## Code
```
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Load the face detection classifier
    CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error: Could not load face classifier!" << endl;
        return -1;
    }

    // Open webcam (default camera, index 0)
    VideoCapture video(0);
    if (!video.isOpened()) {
        cerr << "Error: Could not open video stream!" << endl;
        return -1;
    }

    Mat frame;
    while (true) {
        // Capture frame-by-frame
        video.read(frame);

        // Check if the frame is empty
        if (frame.empty()) {
            cerr << "Error: Frame capture failed!" << endl;
            break;
        }

        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 5);

        // Draw rectangles around detected faces
        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
            putText(frame, "Face", faces[i].tl() - Point(0, 10), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 255, 0), 2);
        }

        // Display the resulting frame
        imshow("Webcam Feed - Face Detection", frame);

        // Press 'q' to exit the loop
        if (waitKey(30) == 'q') break;
    }

    // Release the video capture object and close all windows
    video.release();
    destroyAllWindows();
    
    return 0;
}
```
