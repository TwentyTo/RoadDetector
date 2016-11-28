#pragma once
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\opencv.hpp>
#include <string>
#include <time.h>
#include <iostream>

namespace
{
   cv::Scalar CGreen = cv::Scalar(0, 255, 0);
   cv::Scalar CRed = cv::Scalar(255, 0, 0);
   cv::Scalar CBlue = cv::Scalar(0, 0, 255);
   cv::Scalar CBlack = cv::Scalar(0, 0, 0);
   cv::Scalar CWhite = cv::Scalar(255, 255, 255);
   int keyWait = -1;
   int cutBottom = 130;
   double horizont = 0.53;
   int startFrame = 7500;
   int lowThreshold = 70;
}