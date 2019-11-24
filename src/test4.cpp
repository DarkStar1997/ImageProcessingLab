#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    float beta; std::cin >> beta;
    cv::imshow("Original", img);

    cv::Mat lookupTable(1, 256, CV_8U);
    uchar* p = lookupTable.ptr();
    for(int i = 0; i < 256; i++)
        p[i] = cv::saturate_cast<uchar>(i + beta);

    cv::LUT(img, lookupTable, img);

    cv::imshow("Altered Image", img);
    cv::waitKey();
}
