#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat lap_img;
    cv::Laplacian(img, lap_img, CV_16S, 3);
    cv::convertScaleAbs(lap_img, lap_img);
    cv::imshow("Laplace", lap_img);
    cv::waitKey();
}
