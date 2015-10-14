#include "opencv2/opencv.hpp"
#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;

Mat image;
int trackObject = 0;
Rect selection;

int main()
{
  VideoCapture cap;
  Rect trackWindow;
  int hsize = 16;
  float hranges[] = {0,180};
  const float* phranges = hranges;
  int matchesNum = 0;

  CascadeClassifier cascade;
  if(!cascade.load("../opencv/data/haarcascades/haarcascade_frontalface_alt.xml")) {
    return -1;
  }

  cap.open(0);
  if (!cap.isOpened()) {
    return -1;
  }

  namedWindow("hw1", 1);
  Mat frame, hsv, hue, hist, mask, backproj;

  while(1) {
    cap >> frame;
    if(frame.empty()) {
      break;
    }

    frame.copyTo(image);
    if(!trackObject) {
        Mat grayframe; 
        vector <Rect> faces;
        int detectionsNum = 0;

        cvtColor(image, grayframe, CV_BGR2GRAY);
        cascade.detectMultiScale(grayframe, faces, 1.2, 4, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, cvSize(0, 0));

        detectionsNum = (int)faces.size();
        Rect *faceRects = &faces[0];

        if(detectionsNum > 0) {
          matchesNum += 1;
        }
        else {
          matchesNum = 0;
        }

        if(matchesNum == 3) {
          trackObject = -1;
          selection = faceRects[0];
        }

        for(int i = 0; i < detectionsNum; i++) { 
          Rect r = faceRects[i];
          rectangle(image, Point(r.x, r.y), Point(r.x + r.width, r.y + r.height), CV_RGB(0, 255, 0)); 
        }   
    }

    if(trackObject) {
      cvtColor(image, hsv, CV_BGR2HSV);
      inRange(hsv, Scalar(0, 69, 53), Scalar(180, 256, 256), mask);
      int ch[] = {0, 0};
      hue.create(hsv.size(), hsv.depth());
      mixChannels(&hsv, 1, &hue, 1, ch, 1);

      if(trackObject < 0) {
        Mat roi(hue, selection), maskroi(mask, selection);
        calcHist(&roi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
        normalize(hist, hist, 0, 255, CV_MINMAX);

        trackWindow = selection;
        trackObject = 1;      
      }

      calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
      backproj &= mask;
      RotatedRect trackBox = CamShift(backproj, trackWindow, TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1));
      ellipse(image, trackBox, Scalar(0, 0, 255), 3, CV_AA);
    }

    imshow("hw1", image);
    if(waitKey(30) >= 0) {
      break;
    }
  }

  return 0;
}
