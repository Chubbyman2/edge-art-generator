#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <sys/stat.h>
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
    std::string basedir = "C:/Users/charl/Desktop/edge-art-generator/";
    std::string imagedir = "arknights.png";
    std::string imagepath = basedir + imagedir;

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

    // Create folder to store results
    char _savedir[] = "C:/Users/charl/Desktop/edge-art-generator/results/"; // Must use char, not std::string
    _mkdir(_savedir);
    std::string savedir = "results/"; // Converting is annoying

    // Save results
    imwrite(basedir + savedir + "laplace_edges.png", laplaceEdge);
    imwrite(basedir + savedir + "canny_edges.png", cannyEdge);

    // Resize edge detections for display
    resize(laplaceEdge, laplaceEdgeResized, Size(), 0.25, 0.25);
    resize(cannyEdge, cannyEdgeResized, Size(), 0.25, 0.25);

    // Display windows
    imshow("Laplace Edge Detection", laplaceEdgeResized);
    imshow("Canny Edge Detection", cannyEdgeResized);

    waitKey(0);

    return 0;
}