#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <edgeDetection.hpp>

using namespace cv;
Mat image, gray, blurred, edge, laplaceEdgeResized, cannyEdgeResized, combined;

int main()
{
    // Set the image path to the absolute path of whatever image you want
    char imagepath[] = "C:/Users/charl/Desktop/edge-art-generator/arknights.png";

    // Pass in absolute path just cuz of how CMake runs
    image = imread(imagepath);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    // Returns void
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Get Laplacian edge
    Mat laplaceEdge = laplacianDetection(gray, blurred, edge);

    // Get Canny edge
    Mat cannyEdge = cannyThreshold(gray, blurred, edge);

    // Resize edge detections
    resize(laplaceEdge, laplaceEdgeResized, Size(), 0.25, 0.25);
    resize(cannyEdge, cannyEdgeResized, Size(), 0.25, 0.25);

    // Display windows
    imshow("Laplace Edge Detection", laplaceEdgeResized);
    imshow("Canny Edge Detection", cannyEdgeResized);
    waitKey(0);

    return 0;
}