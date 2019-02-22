/*
 * *Author:-Pukar Giri
 * *Created On:-22Th February 2018 at 9:35
 * *Licence:- MIT
 * *Email:-crazzy.lx75@gmail.com
 */

#include <iostream>
#include <string>
enum bools {pfalse,ptrue};
class palindrome
{
    private:
        std::string no_to_check;
    public:
        palindrome(int input)
        {
            no_to_check=std::to_string(input);
        }
    bools is_palindrome()
        {
            int lastindex=no_to_check.length()-1;
            for (int index=0;index<lastindex;index++,lastindex--)
            {
                if (no_to_check[index]!=no_to_check[lastindex])
                {
                    return pfalse;
                }
            }
            return ptrue;            
        }
};

int main()
{
    int num;
    std::cout <<"Enter the number you want to check "<<std::endl;
    std::cin>>num;
    palindrome num1(num);
    if (num1.is_palindrome()) std::cout<<"the supplied number is palindrome"<<std::endl;
    else std::cout<<"the supplied number is not a palindrome"<<std::endl;
}
