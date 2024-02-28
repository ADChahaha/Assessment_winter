#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../img/bgr_pic.jpg");
    cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
    cv::Canny(image,image,125,350);
    cv::namedWindow("image",0);  
    //reverse color
    cv::Mat lut(256,1,CV_8U);
    for(int i = 0;i < 256;++i)
        lut.at<uchar>(i) = 255 - i;
    cv::LUT(image,lut,image);

    cv::imwrite("edge.jpg",image);
    cv::imshow("image",image);  
    cv::waitKey(0);



    return 0;
}