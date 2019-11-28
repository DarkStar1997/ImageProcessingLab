#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat blur, medianBlur;
    cv::blur(img, blur, cv::Size(5, 5));
    cv::medianBlur(img, medianBlur, 15);
    cv::imshow("Blur", blur);
    cv::imshow("Median Blur", medianBlur);
    cv::waitKey();
}
