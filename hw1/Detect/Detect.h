#include <iostream>
#include "opencv2/opencv.hpp" 

using namespace std;
using namespace cv;

class Detect {
  public:
    Detect();
    void detect(Mat frame);
  private:
    string face_cascade_name;
    string eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    vector<Rect> faces;
    Mat frame_gray;
    Mat faceROI;
};
