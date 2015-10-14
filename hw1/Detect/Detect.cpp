#include "Detect.h"

Detect::Detect() {
  face_cascade_name = "../opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
  eyes_cascade_name = "../opencv/data/haarcascades/haarcascade_eye.xml";

  if( !face_cascade.load(face_cascade_name) ) {
    cout << "loading face cascade fail." << endl;
    exit(1);
  }
  if( !eyes_cascade.load(eyes_cascade_name) ) {
    cout << "loading eyes cascade fail." << endl;
    exit(1);
  }

  ch[0] = 0;
  ch[1] = 0;

  hsize = 16;

  hranges[0] = 0;
  hranges[1] = 180;

  phranges = hranges;
}

bool Detect::detect(Mat frame) {
  bool check = false;
  Mat frame_gray;

  cvtColor(frame, frame_gray, CV_BGR2GRAY);
  equalizeHist(frame_gray, frame_gray);

  //-- Detect faces
  face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));

  for(size_t i = 0; i < faces.size(); i++) {
    Mat faceROI = frame_gray(faces[i]);

    //-- In each face, detect eyes
    eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));

    if(eyes.size() == 2) {
      Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
      ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

      for(size_t j = 0; j < eyes.size(); j++) {
        Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
        int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
        circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
      }

      cvtColor(frame, hsv, CV_BGR2HSV);
      hue.create(hsv.size(), hsv.depth());
      mixChannels(&hsv, 1, &hue, 1, ch, 1);

      Mat roi(hue, faces[i]), maskroi(mask, faces[i]);
      calcHist(&roi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
      normalize(hist, hist, 0, 255, CV_MINMAX);

      check = true;
    }
  }

  //-- Show what you got
  imshow("webcam live", frame);
  return check;
}

bool Detect::track(Mat frame) {
  bool check = false;

  calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
  RotatedRect trackBox = CamShift(backproj, trackWindow, TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));

  return check;
}
