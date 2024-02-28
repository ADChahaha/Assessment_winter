#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../img/count.png");
    cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
    cv::Canny(image,image,125,350);
    cv::namedWindow("image",0);
    cv::imshow("image",image);


    cv::waitKey(0);



    return 0;
}