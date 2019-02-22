/*
*Author:-Pukar Giri
*Created On:-22Th February 2018 at 3:43
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#include<iostream>
#include<string>
#include<cmath>

class polar{
    public:
        float r;
        float theta;
    public:
        polar(float r,float theta)
        {
            this->r=r;
            this->theta=theta*(3.1415/180);
        }
        friend std::ostream& operator<<(std::ostream &out,polar p1)
        {
            out<<"polar("<<p1.r<<","<<p1.theta*(180/3.1415)<<")";
	    return out;
        }
};

class rect{
    public:
        float x;
        float y;
    public:
        rect(float x,float y)
        {
            this->x=x;
            this->y=y;
        }
        rect(polar p1)
        {
            this->x=p1.r*sin(p1.theta);
            this->y=p1.r*cos(p1.theta);
        }
        friend std::ostream& operator<<(std::ostream &out,rect r1)
        {
            out<<"rect("<<r1.x<<","<<r1.y<<")";
	    return out;
        }
        operator polar()
        {
            float r=sqrt(x*x+y*y);
            float theta=atan(y/x)*(180/3.1415);
            polar p1(r,theta);
            return p1;
        }
};

int main()
{
    polar p1(30,45);
    rect r1=p1;
    std::cout<<r1<<" = "<<p1<<std::endl;
    rect r2(45,45);
    polar p2=r2;
    std::cout<<p2<<" = "<<r2<<std::endl;
}
