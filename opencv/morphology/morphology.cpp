#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../img/morphology.png");
    cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
    cv::Mat eroded,dilated,opened,closed;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3)); // cv::MORPH_CROSS //cv::MORPH_ELLIPSE

    int times = 5;

    cv::erode(image,eroded,kernel,cv::Point(-1,-1),times);
    cv::dilate(image,dilated,kernel,cv::Point(-1,-1),times);
    cv::morphologyEx(image,opened,cv::MORPH_OPEN,kernel,cv::Point(-1,-1),times);
    cv::morphologyEx(image,closed,cv::MORPH_CLOSE,kernel,cv::Point(-1,-1),times);

    cv::namedWindow("image",0);
    cv::namedWindow("erode",0);
    cv::namedWindow("dilate",0);
    cv::namedWindow("open",0);
    cv::namedWindow("close",0);

    cv::imshow("image",image);
    cv::imshow("erode",eroded);
    cv::imshow("dilate",dilated);
    cv::imshow("open",opened);
    cv::imshow("close",closed);

    cv::waitKey(0);

    return 0;
}