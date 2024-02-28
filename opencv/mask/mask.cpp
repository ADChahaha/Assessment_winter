#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main()
{
    cv::Mat mask = cv::imread("../img/src.jpg");
    cv::Mat gray,threshold,opened,area,canny,output;
    //change to gray image and threshold
    cv::cvtColor(mask,gray,cv::COLOR_BGR2GRAY);
    cv::threshold(gray,threshold,180,255,cv::THRESH_BINARY);
    cv::erode(threshold,opened,cv::Mat(),cv::Point(-1,-1),7);
    cv::dilate(opened,opened,cv::Mat(),cv::Point(-1,-1),20);
    mask.copyTo(area,opened);
    //get contours
    cv::Canny(area,canny,125,350);
    cv::dilate(canny,canny,cv::Mat(),cv::Point(-1,-1),5);
    std::vector<std::vector<cv::Point>> points;
    cv::findContours(canny,points,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_NONE);
    //get poly(four)
    std::vector<cv::Point2f> poly;
    cv::approxPolyDP(points[0],poly,50,1);
    std::vector<cv::Point2f> rect;
    for(auto it = poly.begin();it != poly.end();++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    rect.push_back(cv::Point2f(0,0));
    rect.push_back(cv::Point2f(0,mask.rows - 1));
    rect.push_back(cv::Point2f(mask.cols - 1,mask.rows - 1));
    rect.push_back(cv::Point2f(mask.cols - 1,0));
    //
    cv::Mat matrix = cv::getPerspectiveTransform(poly,rect);
    cv::warpPerspective(mask,output,matrix,mask.size());
    cv::imwrite("result.jpg",output);

    cv::namedWindow("mask",0);
    cv::imshow("mask",output);

    cv::waitKey(0);



    return 0;
}