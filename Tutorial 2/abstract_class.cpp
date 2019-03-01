#include <iostream>

class polygon
{
    protected:
        float length;
        float height;
    public:
        polygon()=default;
        polygon(float length,float height)
        {
            this->length=length;
            this->height=height;
        }
        virtual float area()=0;
};

class rectangle:public polygon
{
    public:
        rectangle(float length,float height):
            polygon(length,height)
         {
         }
        float area() override
        {
            return length*height;
        }
};

class triangle:public polygon
{
    public:
        triangle(float length,float height):
            polygon(length,height)
         {}
        float area() override
        {
            return 0.5*length*height;
        }
 };

int main()
{
    rectangle r1(10,10);
    triangle t1(10,10);
    std::cout<<"area of triangle: "<<t1.area()<<" but area of rectangle: "<<r1.area()<<std::endl;
}
