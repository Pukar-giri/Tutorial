/*
 * *Author:-Pukar Giri
 * *Created On:-22Th February 2018 at 9:28
 * *Licence:- MIT
 * *Email:-crazzy.lx75@gmail.com
 */
 
#include <iostream>
#include <string>
class timer
{
    private: 
        int hours;
        int minutes;
        int seconds;

    public:
        timer(std::string time)
        {
            int start_index=0;
            int partcount;
            int part[3];
            for (int index=0;index<time.length();index++)
            {
                char ch =time[index];
                if (ch==':'||index==time.length()-1)
                {
                    part[partcount]=std::stoi(time.substr(start_index,index-start_index+1));
                    partcount+=1;
                    start_index=index+1;
                }
            }
            if (partcount !=3)
            {
                throw std::invalid_argument("The input time must be in format HH:MM:SS");
            }
            hours=part[0];
            minutes=part[1];
            seconds=part[2];
        }
        void show()
        {
            std::cout<<"The timer has been set to "<<hours <<" hours "<<minutes<<" minutes and "<<seconds<<" seconds."<<std::endl;
        }
};


int main()
{
    timer t("10:20:30");
    t.show();
}
