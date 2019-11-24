#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::imshow("Original", img);
    cv::Mat m_img;
    cv::equalizeHist(img, m_img);
    cv::imshow("Equalized", m_img);
    cv::waitKey();
}
