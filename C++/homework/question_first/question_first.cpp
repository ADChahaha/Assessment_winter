#include <iostream>
#include <string>

class Person 
{
private:
    std::string name;
    int age;
public:

    // 参数化构造函数
    Person(const std::string& personName, int personAge) 
    {
        name = personName;
        age = personAge;
    }

    // 成员函数 display，用于打印姓名和年龄
    void display() const 
    {
        std::cout << "name is: " << name << " age is: " << age << std::endl;
    }
};

int main() 
{
    //实现你的功能
    Person per1("Name1",18);
    Person per2("Name2",20);
    per1.display();
    per2.display();
}