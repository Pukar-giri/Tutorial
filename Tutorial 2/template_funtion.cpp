

#include <iostream>
#include <cmath>
#include <type_traits>

using namespace std;
template <typename T>

double  square_root(T num)
{
   
    if (is_arithmetic<T>::value)
    {
       return sqrt(num);
    }
    else
    {
        throw invalid_argument("The supplied argument must be a number");
    }
}

int main()
{
    cout<<square_root(5)<<endl;
    cout<<square_root(115.112)<<endl;
    //cout<<square_root("hello")<<endl;
}
