#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

cv::Mat diffImage;
int value = 127, max_value = 255;

void callback(int, void*)
{
    cv::Mat img = diffImage.clone();
    cv::threshold(img, img, value, max_value, cv::ThresholdTypes::THRESH_BINARY);
    cv::imshow("Thresholded", img);
}

int main()
{
    std::string image1, image2; std::cin >> image1 >> image2;
    cv::Mat backgroundImage = cv::imread(image1);
    cv::Mat currentImage = cv::imread(image2);
    cv::resize(backgroundImage, backgroundImage, currentImage.size());
    cv::absdiff(backgroundImage, currentImage, diffImage);
    cv::imshow("Diff", diffImage);
    cv::cvtColor(diffImage, diffImage, cv::COLOR_BGR2GRAY);
    cv::namedWindow("Thresholded");
    cv::createTrackbar("Threshold", "Thresholded", &value, max_value, callback);
    callback(value, 0);
    cv::waitKey();
}
