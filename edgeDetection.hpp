#include <opencv2/opencv.hpp>
#ifndef EDGE_DETECTION_
#define EDGE_DETECTION_

cv::Mat laplacianDetection(cv::Mat gray, cv::Mat blurred, cv::Mat edge);
cv::Mat cannyThreshold(cv::Mat gray, cv::Mat blurred, cv::Mat edge);

#endif 