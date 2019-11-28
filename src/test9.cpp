#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

cv::Mat img, img1;
int clicks = 0;
cv::Point start, end;

void callback(int event, int x, int y, int flags, void* param)
{
    if(clicks == 0)
    {
        if(event == cv::MouseEventTypes::EVENT_LBUTTONDOWN)
        {
            start = cv::Point(x, y);
            clicks++;
        }
    }
    else if(clicks == 1)
    {
        if(event == cv::MouseEventTypes::EVENT_MOUSEMOVE)
        {
            end = cv::Point(x, y);
            img1 = img.clone();
            cv::rectangle(img1, start, end, cv::Scalar(0, 0, 255));
            cv::imshow("Original", img1);
        }
        else if(event == cv::MouseEventTypes::EVENT_LBUTTONDOWN)
        {
            clicks++;
            end = cv::Point(x, y);
            img1 = img.clone();
            img1 = img1(cv::Rect(start, end));
            int top = (int)(0.05 * img1.rows), left = (int)(0.05 * img1.cols), bot = top, right = left;
            cv::copyMakeBorder(img1, img1, top, left, bot, right, cv::BORDER_ISOLATED, cv::Scalar(0, 0, 255));
            cv::imshow("New", img1);
        }
    }
    cv::waitKey(1);
}

int main()
{
    std::string filename; std::cin >> filename;
    img = cv::imread(filename);
    cv::namedWindow("Original");
    cv::imshow("Original", img);
    cv::setMouseCallback("Original", callback, nullptr);
    cv::waitKey();
}
