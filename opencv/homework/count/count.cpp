#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

cv::RNG rng;

cv::Scalar getRandomColor()
{
    return cv::Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
}


int main()
{

    cv::Mat image = cv::imread("../img/count.png");
    cv::Mat canny;
    cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
    //find contours
    cv::Canny(image,canny,125,350);
    cv::dilate(canny,canny,cv::Mat(),cv::Point(-1,-1),3);
    std::vector<std::vector<cv::Point>> points;
    cv::findContours(canny,points,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_NONE);
    //convert to BGR
    cv::cvtColor(image,image,cv::COLOR_GRAY2BGR);
    //deal number
    std::string number = "total: ";
    number += std::to_string(points.size());
    cv::putText(image,number,cv::Point(30,30),0,1,cv::Scalar(0,0,255),2);
    //draw rect
    for(int i = 0;i < points.size();++i)
    {
        cv::Scalar color = getRandomColor();
        cv::Rect rect = cv::boundingRect(points[i]);
        cv::rectangle(image,rect,color,2);
        cv::putText(image,std::to_string(i),cv::Point(rect.x+10,rect.y+30),0,1,color,2);
    }
    
    cv::namedWindow("image",0);
    cv::imshow("image",image);


    cv::waitKey(0);



    return 0;
}