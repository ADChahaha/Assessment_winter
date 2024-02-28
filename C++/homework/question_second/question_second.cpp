#include <iostream>

#define PI 3.1415926

class Shape 
{
public:
    virtual double calculateArea() = 0;
};

class Circle : public Shape 
{
private:
    double radiu;
public:
    virtual double calculateArea() override
    {
        return PI * radiu * radiu;
    }
    Circle(double circle_radiu):radiu(circle_radiu){}
};


class Rectangle : public Shape 
{
private:
    double x;
    double y;
    double width;
    double height;
public:
    Rectangle(double rect_x,double rect_y,double rect_width,double rect_height):x(rect_x),y(rect_y),width(rect_width),height(rect_height){}
    virtual double calculateArea() override
    {
        return width * height;
    }
};

int main() 
{
    //补充你的代码
    Circle circle(3.0);
    Rectangle rect(0,0,20.0,30.0);
    std::cout << "The area of circle is: " << circle.calculateArea() << std::endl;
    std::cout << "The area of rectangle is: " << rect.calculateArea() << std::endl;
}