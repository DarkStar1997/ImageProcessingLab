#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename), img_gray;
    cv::imshow("original", img);
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::imshow("Gray", img_gray);
    cv::bitwise_not(img_gray, img_gray);
    cv::imshow("Inverted", img_gray);
    cv::waitKey();
}
