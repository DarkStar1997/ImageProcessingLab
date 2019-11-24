#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string filename;
    std::cin >> filename;
    cv::Mat img = cv::imread(filename);
    int rows = img.rows, cols = img.cols * img.channels();
    std::cout << img.rows << '*' << img.cols << " Channels: " << img.channels() << '\n';
    const uchar* ptr;
    if(img.isContinuous())
    {
        cols *= rows; rows = 1;
    }
    for(int i = 0; i < rows; i++)
    {
        ptr = img.ptr<uchar>(i);
        for(int j = 0; j < cols; j++)
            std::cout << (int)ptr[j] << ' ';
        std::cout << '\n';
    }
}
