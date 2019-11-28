#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat img_rgb, img_hsv;
    cv::cvtColor(img, img_rgb, cv::COLOR_BGR2RGB);
    cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
    cv::Mat ans;
    cv::inRange(img_rgb, cv::Scalar(30, 66, 3), cv::Scalar(178, 232, 137), ans);
    cv::imshow("threshold_rgb", ans);
    cv::inRange(img_hsv, cv::Scalar(30, 66, 3), cv::Scalar(178, 232, 137), ans);
    cv::imshow("threshold_hsv", ans);
    cv::waitKey();
}
