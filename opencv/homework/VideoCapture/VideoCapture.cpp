#include <opencv2/opencv.hpp>
#include <iostream>
int main()
{
    cv::VideoCapture cap(0);
    cv::Mat frame;
    cv::namedWindow("frame",0);
    while(1)
    {
        cap >> frame;
        if(frame.empty())
            break;
        cv::imshow("frame",frame);
        char c = cv::waitKey(33);
        //esc
        if(27 == c)
            break;
    }
    

    return 0;
}