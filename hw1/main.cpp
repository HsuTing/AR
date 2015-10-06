#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "FaceDetect/FaceDetect.h"

using namespace cv;

int main()
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    FaceDetect test;

    Mat frame;
    while(1)
    {
        cap >> frame; // get a new frame from camera
        imshow("Webcam", frame);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor

    return 0;
}
