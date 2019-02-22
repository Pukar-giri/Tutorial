/*
 * *Author:-Pukar Giri
 * *Created On:-22Th February 2018 at 4:00
 * *Licence:- MIT
 * *Email:-crazzy.lx75@gmail.com
 * */

#include <iostream>

class distance
{
public:
  double foot;
  double inch;
  distance() = default;
  distance(double foot, double inch)
  {
    this->foot = foot;
    this->inch = inch;
  }
  friend std::istream &operator>>(std::istream &in, distance &dist)
  {
    std::cout << "enter the foot part: " << std::endl;
    in >> dist.foot;
    std::cout << "enter the inch part: " << std::endl;
    in >> dist.inch;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, distance &dist)
  {
    out << dist.foot << " feet " << dist.inch << " inches";
    return out;
  }
  distance operator+(distance &dist1)
  {
    return distance(this->foot + dist1.foot, this->inch + dist1.inch);
  }
  distance operator-(distance &dist1)
  {
    return distance(this->foot - dist1.foot, this->inch - dist1.inch);
  }
};

int main()
{
  distance d1(5, 5);
  distance d2;
  std::cin >> d2;
  distance d3 = d1 + d2;
  std::cout << d1 << " + " << d2 << " = " << d3 << std::endl;
  distance d4 = d2 - d1;
  std::cout << d2 << " - " << d1 << " = " << d4 << std::endl;
}