/*
*Author:-Pukar Giri
*Created On:-22Th February 2018 at 11:00
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#include <iostream>
#include <string>
#include <iomanip>
class person
{
protected:
  std::string name;
  int age;
  bool married;

public:
  person(std::string name, int age, bool married)
  {
    this->name = name;
    this->age = age;
    this->married = married;
  }
  friend std::ostream &operator<<(std::ostream &out, person &person)
  {
    out << ((person.married) ? "M" : "Unm") << "arried"
        << " person with name " << person.name << " and age " << person.age;
    return out;
  }
};

class employee
{
protected:
  std::string emp_Id;
  float salary;

public:
  employee(std::string emp_id, float salary)
  {
    this->emp_Id = emp_id;
    this->salary = salary;
  }
  friend std::ostream &operator<<(std::ostream &out, employee &emp)
  {
    out << "Employee with employee id " << emp.emp_Id << " and salary " << emp.salary;
    return out;
  }
};

class manager : public person, public employee
{
protected:
  float bonus;

public:
  manager(std::string name, int age, bool married, std::string emp_id, float salary, float bonus) : person(name, age, married), employee(emp_id, salary)
  {
    this->bonus = bonus;
  }
  friend std::ostream &operator<<(std::ostream &out, manager &emp)
  {
    out << std::endl;
    out << std::left << std::setw(15) << "Name"
        << " : " << emp.name << std::endl;
    out << std::left << std::setw(15) << "Age"
        << " : " << emp.age << std::endl;
    out << std::left << std::setw(15) << "Marital-status"
        << " : " << ((emp.married) ? "M" : "Unm") << "arried" << std::endl;
    out << std::left << std::setw(15) << "Employee Id"
        << " : " << emp.emp_Id << std::endl;
    out << std::left << std::setw(15) << "Salary"
        << " : " << emp.salary << std::endl;
    out << std::left << std::setw(15) << "Bonus"

        << " : " << emp.bonus << std::endl;
    return out;
  }
};
int main()
{

  manager pukar("Pukar Giri", 20, false, "THA074BEX025", 99000, 35);
  std::cout << pukar << std::endl;
}
