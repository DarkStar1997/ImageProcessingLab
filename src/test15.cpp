#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat sobl_img;
    cv::Sobel(img, sobl_img, CV_16S, 0, 1, 3);
    cv::convertScaleAbs(sobl_img, sobl_img);
    cv::imshow("Sobel", sobl_img);
    cv::waitKey();
}
