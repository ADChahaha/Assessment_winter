#include <opencv2/opencv.hpp>
#include <vector>

int hue = 0,saturation = 0,value = 0;

void onTrackBar(int value,void* data);

cv::Mat image = cv::imread("../img/count.png");

int main()
{
    cv::namedWindow("control",0);
    cv::namedWindow("image");

    cv::createTrackbar("Hue","control",&hue,179,onTrackBar);
    cv::createTrackbar("Saturation","control",&saturation,255,onTrackBar);
    cv::createTrackbar("Value","control",&value,255,onTrackBar);

    cv::waitKey(0);

    return 0;
}

void onTrackBar(int value,void* data)
{
    cv::Mat hsv_image;
    cv::Mat bgr_image;
    cv::cvtColor(image,hsv_image,cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> channels;
    cv::split(hsv_image,channels);
    channels[0] = hue;
    channels[1] = saturation;
    channels[2] = value;
    cv::merge(channels,hsv_image);
    cv::cvtColor(hsv_image,bgr_image,cv::COLOR_HSV2BGR);
    cv::imshow("image",bgr_image);
}