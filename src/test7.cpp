#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat img, img1;
int threshVal = 127;
int maxThreshVal = 255;

void callback(int, void*)
{
    cv::threshold(img, img1, threshVal, maxThreshVal, cv::ThresholdTypes::THRESH_BINARY);
    cv::imshow("Thresholded", img1);
}


int main()
{
    std::string filename; std::cin >> filename;
    img = cv::imread(filename);
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::imshow("Original", img);
    cv::namedWindow("Thresholded");
    cv::createTrackbar("threshold", "Thresholded", &threshVal, maxThreshVal, callback);
    callback(threshVal, 0);
    cv::waitKey();
}
