#include <opencv2/opencv.hpp>
#include <vector>

int hue = 0,saturation = 128,value_bright = 128;

void onTrackBar(int value,void* data);

cv::Mat image = cv::imread("../img/bgr_pic.jpg");

int main()
{

    cv::namedWindow("control",0);
    cv::namedWindow("image",0);
    cv::namedWindow("changed",0);
    cv::imshow("image",image);

    cv::createTrackbar("Hue","control",&hue,179,onTrackBar);
    cv::createTrackbar("Saturation","control",&saturation,255,onTrackBar);
    cv::createTrackbar("Value","control",&value_bright,255,onTrackBar);

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
 //   channels[0] = hue;
 //   channels[1] = saturation;
    channels[2] = value_bright;
    cv::merge(channels,hsv_image);
    cv::cvtColor(hsv_image,bgr_image,cv::COLOR_HSV2BGR);
    cv::imwrite("changed_pic.jpg",bgr_image);
    cv::imshow("changed",bgr_image);
}