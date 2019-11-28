#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string f1, f2; std::cin >> f1 >> f2;
    cv::Mat img = cv::imread(f1);
    cv::Mat logo = cv::imread(f2);
    cv::Vec2b x(0, 0);
    for(int i = 0; i < logo.rows; i++)
        for(int j = 0; j < logo.cols; j++)
            img.at<cv::Vec3b>(i + x[0], j + x[1]) = img.at<cv::Vec3b>(i + x[0], j + x[1]) * 0.5 + logo.at<cv::Vec3b>(i, j) * 0.5;
    cv::imshow("Overlay", img);
    cv::waitKey();
}
