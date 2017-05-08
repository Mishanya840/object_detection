#include "Video.h"

Video::Video( )
{

}

void Video::processVideo(string imageFilename) {
    cv::namedWindow("Frame");

    capture.open(0);
    if (!capture.isOpened()) {
       //cerr << "Unable to open video file: " << imageFilename << endl;
        exit(EXIT_FAILURE);
    }
    while ((char)keyboard != 'q' && (char)keyboard != 27) {

            frame = imread(imageFilename ,1);
            if (!frame.empty()){
                //cerr << "Unable to read img." << endl;
                //cerr << "Exiting..." << endl;
                exit(EXIT_FAILURE);
            }
            imshow("Frame", frame);
    }
    keyboard = waitKey(1);

    //delete capture object
    capture.release();
}
