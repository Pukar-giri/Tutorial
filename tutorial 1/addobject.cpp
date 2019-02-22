/*
*Author:-Pukar Giri
*Created On:-22Th February 2018 at 11:00
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class students
{
    public:
        std::vector<std::string> name;
        std::vector<int> roll;
        std::vector<std::string>redgno;
        students()=default;
       void add_student(std::string sname,int sroll,std::string sredgno)
        {
        name.push_back(sname);
        roll.push_back(sroll);
        redgno.push_back(sredgno);
        }
};

class teachers
{
    public:
        std::vector<std::string>name;
        std::vector<int>id;
        teachers()=default;
        void add_teachers(std::string tname,int tid)
        {
            name.push_back(tname);
            id.push_back(tid);
        }   
};

class school
{
    public:
        std::vector<std::string> sname;
        std::vector<int> roll;
        std::vector<std::string>redgno;
        std::vector<std::string>teacher_name;
        std::vector<int>id;
        school()=default;
        void show_details()
        {
            std::cout<<"This school consists of following Teachers: "<<std::endl;
            std::cout<<std::string(33,'_')<<std::endl;
            std::cout<<"|"<<std::setw(20)<<std::left<<"Name"<<"|"<<std::setw(10)<<std::left<<"ID"<<"|"<<std::endl;
            std::cout<<"|"<<std::string(20,'_')<<"|"<<std::string(10,'_')<<"|"<<std::endl;
            for(int i=0;i<teacher_name.size();i++)
            {
                std::cout<<"|"<<std::setw(20)<<std::left<<teacher_name[i]<<"|"<<std::setw(10)<<std::left<<id[i]<<"|"<<std::endl;
            }
	    std::cout<<"|"<<std::string(20,'_')<<"|"<<std::string(10,'_')<<"|"<<std::endl<<std::endl;
	    std::cout<<"This school consists of following students : "<<std::endl;
            std::cout<<std::string(44,'_')<<std::endl;
            std::cout<<"|"<<std::setw(20)<<std::left<<"Name"<<"|"<<std::setw(10)<<std::right<<"Roll no"<<"|"<<std::setw(10)<<std::left<<"Redg no "<<"|"<<std::endl;
            std::cout<<"|"<<std::string(20,'_')<<"|"<<std::string(10,'_')<<"|"<<std::string(10,'_')<<"|"<<std::endl;
            for(int i=0;i<sname.size();i++)
            {
                std::cout<<"|"<<std::setw(20)<<std::left<<sname[i]<<"|"<<std::setw(10)<<std::right<<roll[i]<<"|"<<std::setw(10)<<std::left<<redgno[i]<<"|"<<std::endl;
            }
            std::cout<<"|"<<std::string(20,'_')<<"|"<<std::string(10,'_')<<"|"<<std::string(10,'_')<<"|"<<std::endl;
        }
};

school operator+(teachers & teacher,students & student) //using global operator overloading 
{
    school s;
    for(int i=0;i<student.name.size();i++)
    {
        s.sname.push_back(student.name[i]);
        s.roll.push_back(student.roll[i]);
        s.redgno.push_back(student.redgno[i]);
    }
    for (int j=0;j<teacher.name.size();j++)
    {
        s.teacher_name.push_back(teacher.name[j]);
        s.id.push_back(teacher.id[j]);
    }
    return s;
}
int main()
{
   students grp1;
   grp1.add_student("ram bharati",27,"5567th");
   grp1.add_student("Pukar giri",25,"1337th");
   grp1.add_student("sushil khadka",46,"01134th");
   teachers tch1;
   tch1.add_teachers("saroj sakya",1);
   tch1.add_teachers("devendra kathayat",2);
   tch1.add_teachers("rajan g.",3);
   school thapathali=tch1+grp1; //adding students and teachers to form a school
   thapathali.show_details();
}
