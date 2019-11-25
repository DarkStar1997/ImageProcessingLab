#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat img, img1;
int val = 5;
int maxVal = 10;

void callback(int, void*)
{
    double factor = (double)val / (maxVal / 2);
    cv::resize(img, img1, cv::Size(), factor, factor);
    cv::imshow("zoomed", img1);
}

int main()
{
    std::string filename; std::cin >> filename;
    img = cv::imread(filename);
    cv::imshow("original", img);
    cv::namedWindow("zoomed");
    cv::createTrackbar("scale", "zoomed", &val, maxVal, callback);
    callback(val, 0);
    cv::waitKey();
}
