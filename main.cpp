#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
using namespace cv;
using namespace std;


Mat image;
Mat src;
Mat src_gray;
Mat canny;
char* canny_window = "Canny";
  Mat grad;
  const char* window_name = "Sobel Demo - Simple Edge Detector";
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  int lowThreshold = 0;
  int const max_lowThreshold = 100;
  int ratio = 3;
  int kernel_size = 3;
  int blursize = 3;
  int max_blursize = 10;

  Mat frame; //current frame
  Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
  Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
  char keyboard; //input from keyboard

void processVideo(char* videoFilename);

Mat CannyThreshold(int, Mat canny){
    cvtColor( canny, canny, COLOR_BGR2GRAY );
    if (blursize != 0){
        blur(canny, canny, Size(blursize,blursize));
    }
    if (lowThreshold != 0) {
        Canny(canny, canny, lowThreshold, lowThreshold*ratio, kernel_size );
    }
    return canny;
    //imshow( canny_window, canny );
}


int main()
{
    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
    processVideo("C:\\Users\\Mishanya\\Documents\\Counter2016\\video.mp4");
    return 0;
}

void processVideo(char* videoFilename) {
    //create the capture object
    VideoCapture capture(videoFilename);
    if(!capture.isOpened()){
        //error in opening the video input
        cerr << "Unable to open video file: " << videoFilename << endl;
        exit(EXIT_FAILURE);
    }
    //read input data. ESC or 'q' for quitting
    keyboard = 0;
    while( keyboard != 'q' && keyboard != 27 ){
        //read the current frame
        if(!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        frame = CannyThreshold(0,frame);
        //update the background model
        pMOG2->apply(frame, fgMaskMOG2,0);
        //get the frame number and write it on the current frame
        stringstream ss;
        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
                  cv::Scalar(255,255,255), -1);
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
                FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
        //show the current frame and the fg masks
        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG2);
        //get the input from the keyboard
        keyboard = (char)waitKey( 30 );
    }
    //delete capture object
    capture.release();
}
