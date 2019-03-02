#include <iostream>
#include <string>
using namespace std;
class Student
{
    int roll;
    string name;

  public:
    Student(int rollno, string sname)
    {
        name = sname;
        roll = rollno;
    }
    void print_student_info()
    {
        cout << "First Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
    }
};

class Test : public Student
{
    int ECD_marks, Cpp_marks, ECT_marks;

  public:
    Test(int roll, string name, int marks1, int marks2, int marks3) : Student(roll, name)
    {
        ECD_marks = marks1;
        Cpp_marks = marks2;
        ECT_marks = marks3;
    }
    int get_marks_of_subject(int subject)
    {
        switch (subject)
        {
        case 1:
            return ECD_marks;
        case 2:
            return Cpp_marks;
        case 3:
            return ECT_marks;
        default:
            return 0;
        }
    }
    void print_test_marks()
    {
        cout << "ECT_marks: " << ECT_marks << endl;
        cout << "ECD_marks: " << ECD_marks << endl;
        cout << "C++_marks: " << Cpp_marks << endl;
    }
};

class Result : public Test
{
    int total;
    float percent;

  public:
    Result(int roll, string name, int marks1, int marks2, int marks3) : Test(roll, name, marks1, marks2, marks3)
    {
    }
    void print_result()
    {
        print_student_info();
        print_test_marks();
        total = get_marks_of_subject(1) + get_marks_of_subject(2) + get_marks_of_subject(3);
        percent = total / 3;
        cout << "Total Marks: " << total << endl;
        cout << "percentage : " << percent << "%" << endl;
    }
};

int main()
{
    int roll, marks1, marks2, marks3;
    string name;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter ECT_marks: ";
    cin >> marks1;
    cout << "Enter ECD_marks: ";
    cin >> marks2;
    cout << "Enter C++_marks: ";
    cin >> marks3;
    Result R(roll, name, marks1, marks2, marks3);
    cout << endl
         << endl;
    R.print_result();
    return 0;
}