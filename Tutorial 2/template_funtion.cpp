

#include <iostream>
#include <string>
#include <type_traits>

using namespace std;
template <typename T>

double  square_root(T num)
{
   
 if (is_arithmetic<T>::value)
 {
    if (num>=0)
    {
       double i, precision = 0.00001;
       for(i = 1; i*i <=num; ++i);
       for(--i; i*i < num; i += precision);
       return i;
    }
    else
    {
        throw invalid_argument("The supplied argument must be a non negative number");
    }
 }
 else
 {
     throw invalid_argument("Supplied argument must be a number")
 }
}

int main()
{
    cout<<square_root(5)<<endl;
    cout<<square_root(115.112)<<endl;
   // cout<<square_root(string("hello"))<<endl; //this should throw exception on compilation 
}
