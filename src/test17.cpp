#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string filename; std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    cv::Mat img_blur;
    cv::GaussianBlur(img, img_blur, cv::Size(31, 31), 0);
    cv::Mat img_hpf = img - img_blur;
    img_hpf = img_hpf + cv::Scalar(127, 127, 127);
    cv::imshow("High Pass Filter", img_hpf);
    cv::imshow("Low Pass Filter", img_blur);
    cv::waitKey();
}
