#include <iostream>

class person
{
private:
    std::string name;
    std::string gender;
    float age;

public:
    person(std::string n, std::string g, float a) : name(n), gender(g), age(a) // initializtion list for parameters with constructor
    {
    }
    void set_name(std::string n)
    {
        name = n;
    }
    void set_gender(std::string g)
    {
        gender = g;
    }
    void set_age(float a)
    {
        age = a;
    }
    std::string get_name()
    {
        return name;
    }
    std::string get_gender()
    {
        return gender;
    }
    float get_age()
    {
        return age;
    }
};

class student : public person // make inhertitence relation and get them as they are in parent (private will not be inherited)
{
private:
    int student_level;
    float GPA;

public:
    student(std::string n, std::string g, float a, int sl, float gpa) : person(n, g, a), student_level(sl), GPA(gpa)
    {
    }
    void set_stud_level(int sl)
    {
        student_level = sl;
    }
    void set_GPA(float gpa)
    {
        GPA = gpa;
    }
    int get_stud_level()
    {
        return student_level;
    }
    int get_gpa()
    {
        return GPA;
    }
};

class employee : public person
{
    private:
    int salary;
    std::string rank;
    std::string job;
    public:
    employee(std::string n,std::string g,float a,int s,std::string r,std::string j):person(n,g,a),salary(s),rank(r),job(j)
    {
    }
    void set_salary(int s)
    {
        salary = s;
    }
    void set_rank(std::string r)
    {
        rank = r;
    }
    void set_job(std::string j)
    {
        job = j;
    }
    int get_salary()
    {
        return salary;
    }
    std::string get_rank()
    {
        return rank;
    }
    std::string get_job()
    {
        return job;
    }


};

int main()
{
    person p("Mohamed", "male", 23);
    student s("omar", "male", 23, 4, 3.2);
    employee e("Hisham","Male",25,1000,"senior","engineer");

    e.set_name("Mahmoud");
    e.set_gender("male");
    e.set_age(30);
    e.set_salary(2000);
    e.set_rank("junior");
    e.set_job("sw engineer");
    
    std::cout<<"employee name is: "<<e.get_name();
    std::cout<<"employee gender is: "<<e.get_gender();
    std::cout<<"employee age is: "<<e.get_age();
    std::cout<<"employee salary is: "<<e.get_salary();
    std::cout<<"employee rank is: "<<e.get_rank();
    std::cout<<"employee job is: "<<e.get_job();




}