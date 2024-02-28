#include <opencv2/opencv.hpp>

#define THRESH_BINARY 1
#define THRESH_BINARY_INV 0




void thresholdByIt(const cv::Mat& image,cv::Mat& output,double threshold_value,double max_value,int type)
{
    output.create(image.size(),image.type());
    if(1 == image.channels() && CV_8U == image.depth())
    {
        //GRAY IMAGE
        auto it_output = output.begin<uchar>();
        for(auto it = image.begin<uchar>(),itend = image.end<uchar>();it != itend;++it,++it_output)
        {
            if(*it < threshold_value)
                *it_output = type?0:max_value;
            else
                *it_output = type?max_value:0;
        }
    }   
    else
    {
        //BGR IMAGE
        return;
    }
}

void thresholdByAt(const cv::Mat& image,cv::Mat& output,double threshold_value,double max_value,int type)
{
    output.create(image.size(),image.type());
    if(1 == image.channels() && CV_8U == image.depth())
    {
        //GRAY IMAGE
        for(int row = 0;row < image.rows;row++)
        {
            for(int col = 0;col < image.cols;++col)
            {
                if(image.at<uchar>(row,col) < threshold_value)
                    output.at<uchar>(row,col) = type?0:max_value;
            else
                output.at<uchar>(row,col) = type?max_value:0;
            }
        }
    }   
    else
    {
        //BGR IMAGE
        return;
    }
}

void thresholdByPtr(const cv::Mat& image,cv::Mat& output,double threshold_value,double max_value,int type)
{
    output.create(image.size(),image.type());
    if(1 == image.channels() && CV_8U == image.depth())
    {
        //GRAY IMAGE
        for(int row = 0;row < image.rows;row++)
        {
            auto ptr_image = image.ptr(row);
            auto ptr_output = output.ptr(row);
            for(int col = 0;col < image.cols;++col)
            {
                if(ptr_image[col] < threshold_value)
                    ptr_output[col] = type?0:max_value;
            else
                ptr_output[col] = type?max_value:0;
            }
        }
    }   
    else
    {
        //BGR IMAGE
        return;
    }
}

int main()
{
    //create a gray image
    cv::Mat image(200,200,CV_8UC1,cv::Scalar(128));
    cv::namedWindow("image",0);
    
    cv::imshow("image",image);
    
    cv::waitKey(3000);

    //threshold to black
    thresholdByPtr(image,image,129,255,THRESH_BINARY);

    cv::imshow("image",image);

    cv::waitKey(3000);
    //threshold to gray
    thresholdByAt(image,image,1,128,THRESH_BINARY_INV);

    cv::imshow("image",image);

    cv::waitKey(3000);
    //threshold to black again
    thresholdByIt(image,image,129,255,THRESH_BINARY);

    cv::imshow("image",image);

    cv::waitKey(0);

    return 0;
}