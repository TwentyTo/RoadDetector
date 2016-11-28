#include "consts.hpp"
#include "functions.hpp"
#include <vector>

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      std::cout << "There is no path to video" << std::endl;
      return 0;
   }
   cv::VideoCapture cap(argv[1]);

   cv::Size video_size;

   cv::Mat frame;
   cv::Mat frameClone;
   cv::Mat greyFrame;
   CvMemStorage* houghStorage = cvCreateMemStorage(0);
   if (cap.isOpened())
   {
      while(1)
      {
         cap >> frame;
         frame = frame.rowRange(0,frame.rows - cutBottom); // remove hood
         cv::pyrDown(frame, frame, cv::Size(frame.cols/2, frame.rows/2)); // scale 0.5
         frameClone = crop(frame, horizont); // remove sky
         cv::cvtColor(frameClone, greyFrame, CV_BGR2GRAY); // rgb to grey
         cv::GaussianBlur(greyFrame, greyFrame, cv::Size(5, 5), 0, 0); // gausblur
         cv::Canny(greyFrame, greyFrame, 1, 100); // edges
         std::vector<cv::Vec4i> lines;
         cv::HoughLinesP(greyFrame, lines, 1, CV_PI/180, 50, 50, 10);
         processLanes(lines, greyFrame, frameClone);
         

         cv::imshow("RoadDetector", frameClone);
         char pressedKey = cvWaitKey(keyWait);
         if (pressedKey == 'p' || pressedKey == 'P')
         {
            keyWait *= -1;
         }
         else if(pressedKey == 'n' || pressedKey == 'N')
         {
            cap >> frame;
         }
      }
   }
   return 0;
}
