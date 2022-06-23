#include <opencv2/opencv.hpp>
#ifndef EDGE_DETECTION_
#define EDGE_DETECTION_

using namespace cv;
Mat laplacianDetection(Mat gray, Mat blurred, Mat edge);
Mat cannyThreshold(Mat gray, Mat blurred, Mat edge);

#endif 