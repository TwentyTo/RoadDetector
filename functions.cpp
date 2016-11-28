#include "functions.hpp"
cv::Mat crop (cv::Mat frame, double cropFuct)
{
   cv::Mat temp = frame.rowRange(frame.rows * cropFuct, frame.rows);
   return temp;
}

void processLanes(std::vector<cv::Vec4i> lines, cv::Mat edges, cv::Mat frame)
{
   for (int i = 0; i < lines.size(); i++)
   {
      cv::Vec4i line = lines[i];
      int dx = line[2] - line[0];
      int dy = line[3] - line[1];
      double angle = atan2f(dy, dx) * 180 / CV_PI;

      if (abs(angle) <= 10)
         continue;
      cv::line(frame, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 0, 255));
   }
}