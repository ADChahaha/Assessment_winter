#include <opencv2/opencv.hpp>

void gamaJiaoZheng(const cv::Mat& image,cv::Mat& output,double value)
{
    output.create(image.size(),image.type());
    cv::Mat lookup(256,1,CV_8U);
    for(int i = 0;i < 256;++i)
    {
        lookup.at<uchar>(i) = pow(i/255.0,value)*255.0;
    }
    cv::LUT(image,lookup,output);

}

int main()
{
    cv::Mat gama1 = cv::imread("../img/gama1.png");
    cv::Mat gama2 = cv::imread("../img/gama2.jpg");
    cv::Mat JiaoZheng1;
    cv::Mat JiaoZheng2;

    gamaJiaoZheng(gama1,JiaoZheng1,1/2.2);
    gamaJiaoZheng(gama2,JiaoZheng2,1/2.2);

    cv::namedWindow("gama1",0);
    cv::namedWindow("gama2",0);
    cv::namedWindow("JiaoZheng1",0);
    cv::namedWindow("JiaoZheng2",0);

    cv::imshow("gama1",gama1);
    cv::imshow("gama2",gama2);
    cv::imshow("JiaoZheng1",JiaoZheng1);
    cv::imshow("JiaoZheng2",JiaoZheng2);

    cv::waitKey(0);



    return 0;
}