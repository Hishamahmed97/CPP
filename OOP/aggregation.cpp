#include <iostream>
#include <string>
#include <vector>

class Department;

class Employee
{
    private:
    std::string name;
    Department * department;
    public:
    Employee(std::string name):name(name),department(nullptr){}
    void setDepartment(Department * newdepartment)
    {
        department = newdepartment;
    }
};

class Department
{
    private:
    std::string name;
    std::vector<Employee*> employees;
    public:
    Department(std::string name):name(name){}
    void addEmployee(Employee* employee)
    {
        employees.push_back(employee);
        employee->setDepartment(this); //this is equal to current class (Department)
    }
};