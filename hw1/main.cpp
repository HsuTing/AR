#include "opencv2/opencv.hpp"
#include "Detect/Detect.h"

using namespace cv;

int main()
{
   VideoCapture cap(0);
   if(!cap.isOpened()) {  // check if we succeeded
     return -1;
   }

   //-- 1. Load the cascades
   Detect detect;
   Mat frame;

   //-- 2. Read the video stream
     while(true) {
       cap >> frame;

       //-- 3. Apply the classifier to the frame
       if(!frame.empty()) {
         detect.detect(frame);
       }
       else {
         cout << " --(!) No captured frame -- Break!" << endl;
         break;
       }

       int c = waitKey(10);
       if((char)c == 'c') {
         break;
       }
     }

  return 0;
}
