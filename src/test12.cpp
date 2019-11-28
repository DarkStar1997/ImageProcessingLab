#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat kernel = cv::Mat::ones(cv::Size(5, 5), CV_8U);
    cv::Mat erode, dilate;
    cv::erode(img, erode, kernel, cv::Point(), 10);
    cv::imshow("eroded", erode);
    cv::dilate(img, dilate, kernel, cv::Point(), 10);
    cv::imshow("dilated", dilate);
    cv::waitKey();
}
