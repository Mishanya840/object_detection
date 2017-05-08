#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
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
  int lowThreshold = 1;
  int const max_lowThreshold = 100;
  int ratio = 3;
  int kernel_size = 3;
  int blursize = 3;
  int max_blursize = 10;

void CannyThreshold(int, void*){
    src.copyTo(canny);
    cvtColor( canny, canny, COLOR_BGR2GRAY );
    if (blursize != 0){
        blur(canny, canny, Size(blursize,blursize));
    }
    if (lowThreshold != 0) {
        Canny( canny, canny, lowThreshold, lowThreshold*ratio, kernel_size );
    }
    imshow( canny_window, canny );
 }

int main()
{
           char* filename = "C:\\Users\\Mishanya\\Documents\\Counter2016\\image.jpg";
           // получаем картинку
           src = imread(filename,1);

           printf("[i] image: %s\n", filename);
           assert( !src.empty() );

           // окно для отображения картинки
           cvNamedWindow("original",CV_WINDOW_AUTOSIZE);

           // показываем картинку
           imshow("original",src);
           cvtColor( src, src_gray, COLOR_BGR2GRAY );

           CannyThreshold(0,0);
           createTrackbar( "Min Threshold:", canny_window, &lowThreshold, max_lowThreshold, CannyThreshold );
           createTrackbar( "Min Blur:", canny_window, &blursize, max_blursize, CannyThreshold );

           Mat grad_x, grad_y;
           Mat abs_grad_x, abs_grad_y;
           //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
           Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
           //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
           Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
           convertScaleAbs( grad_x, abs_grad_x );
           convertScaleAbs( grad_y, abs_grad_y );
           addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
           //imshow( "sobel", grad );


           // ждём нажатия клавиши
           cvWaitKey(0);


           // удаляем окно
           cvDestroyWindow("original");
           return 0;
}
