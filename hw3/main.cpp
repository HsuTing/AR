#include "opencv2/opencv.hpp"
#include <iostream>

#define marker_num 3
#define marker_url "marker/"

using namespace cv;
using namespace std;

void load(string[marker_num], vector<Mat>& ,int&);

int main()
{
  string marker[marker_num] = {"marker1.png", "marker2.png", "marker3.png"}; 
  vector<Mat> makerLibrary;
  int markerCount = 0;
  load(marker, makerLibrary, markerCount);

  Mat frame;
  VideoCapture cap(0);

  if(!cap.isOpened()) {
    cout << "Could not open or find the video." << endl;
    return 0;
  }

  namedWindow("hw3", WINDOW_AUTOSIZE);

  while(1) {
    cap >> frame;

    if(frame.empty()) {
      break;
    }

    imshow("hw3", frame);

    if(waitKey(30) >= 0) {
      break;
    }
  }

  return 0;
}

void load(string files[marker_num], vector<Mat>& library,int& markerCount) {
  for(int i = 0; i < marker_num; i++) {
    Mat image = imread(marker_url + files[i], CV_LOAD_IMAGE_COLOR);

    if(!image.data) {
      cout <<  "Could not open or find " << marker_url << files[i] << endl;
    }

    int msize = 64; 

    Mat src(msize, msize, CV_8UC1);
    Point2f center((msize-1)/2.0f,(msize-1)/2.0f);
    Mat rot_mat(2,3,CV_32F);
	
    resize(image, src, Size(msize,msize));
    Mat subImg = src(Range(msize/4,3*msize/4), Range(msize/4,3*msize/4));
    library.push_back(subImg);

    rot_mat = getRotationMatrix2D( center, 90, 1.0);

    for (int i=1; i<4; i++){
      Mat dst= Mat(msize, msize, CV_8UC1);
      rot_mat = getRotationMatrix2D( center, -i*90, 1.0);
      warpAffine( src, dst , rot_mat, Size(msize,msize));
      Mat subImg = dst(Range(msize/4,3*msize/4), Range(msize/4,3*msize/4));
    }

    markerCount++;
  }
}
