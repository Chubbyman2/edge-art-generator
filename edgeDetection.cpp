#include <opencv2/opencv.hpp>
#include <edgeDetection.hpp>

using namespace cv;

// Laplacian Operator Variables
int kernel_size = 3;
int ddepth = CV_16S;

// Canny Edge Detection Variables
int lowerThreshold = 0;
int max_lowThreshold = 100;


Mat laplacianDetection(Mat gray, Mat blurred, Mat edge) {

    GaussianBlur(gray,
        blurred,
        cv::Size(3, 3),  // smoothing window width and height in pixels
        3);              // how much the image will be blurred

    Laplacian(blurred,
        edge,
        ddepth,         // Depth of the destination image
        kernel_size);    // Size of the kernel

    // converting back to CV_8U
    convertScaleAbs(edge, edge);

    return edge;
}


Mat cannyThreshold(Mat gray, Mat blurred, Mat edge) {

    GaussianBlur(gray,
        blurred,
        cv::Size(3, 3),  // smoothing window width and height in pixels
        3);              // how much the image will be blurred

    Canny(blurred,
        edge,
        lowerThreshold, // lower threshold
        50);           // higher threshold

    // imshow("Edge Detection", edge);
    return edge;
}