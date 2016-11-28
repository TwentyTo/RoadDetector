#pragma once

#include "consts.hpp"

CvPoint2D32f point_on_segment(CvPoint2D32f line0, CvPoint2D32f line1, CvPoint2D32f pt);
cv::Mat crop(cv::Mat frame, double horizont);
void processLanes(std::vector<cv::Vec4i> lines, cv::Mat edges, cv::Mat frame);