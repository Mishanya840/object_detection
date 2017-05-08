#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/video.hpp>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;

class Video
{
public:
    Video();
    void processVideo(string videoFilename);
    VideoCapture capture;

private:
    int keyboard;
    Mat frame;
};

#endif // VIDEO_H
