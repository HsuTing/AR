#include <iostream>
#include "opencv2/opencv.hpp" 

using namespace std;
using namespace cv;

class Detect {
  public:
    Detect();
    bool detect(Mat frame);
    bool track(Mat image);
  private:
    //detect
    string face_cascade_name;
    string eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    Mat frame_gray;
    Mat faceROI;

    //track data
    vector<Rect> faces;
    vector<Rect> eyes; 

    //track
    Mat hsv;
    Mat hue;
    Mat hist;
    Mat mask;
    Mat backproj;
    int hsize;
    float hranges[2];
    const float* phranges;
    int ch[2];
    Rect trackWindow;
};
