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
