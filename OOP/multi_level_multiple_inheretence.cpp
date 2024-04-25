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
    virtual void display() //for function over-ride
    {
        std::cout<<name<<" "<<gender<<" "<<age<<std::endl;
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
    void display() override
    {
        person::display(); // to print person attributes
        std::cout<<student_level<<" "<<GPA<<std::endl;
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
    virtual int get_salary()
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
    void display() override
    {
        person::display(); // to print person attributes
        std::cout<<salary<<" "<<rank<<" "<<job<<std::endl;
    }


};

class hour : public employee
{   
    private:
    int hours;
    int hours_rate;
    public:
    hour(std::string n,std::string g,float a,int s,std::string r,std::string j,int hrs,int hrs_rate):employee(n,g,a,s,r,j)
    {
        hours = hrs;
        hours_rate = hrs_rate;
    }
    void set_Hours(int hrs)
    {
        hours = hrs;
    }
    int get_Hours()
    {
        return hours;
    }
    void set_HoursRate(int hrs_rate)
    {
        hours_rate = hrs_rate;
    }
    int get_HoursRate()
    {
        return hours_rate;
    }
    int get_salary() override
    {
        return hours_rate*hours;
    }
    void display() override
    {
        employee::display(); // to print employee attributes
        std::cout<<hours<<" "<<hours_rate<<" "<<get_salary()<<std::endl;
    }
};

class fullTime : public employee
{   
    private:
    int deduction_per_day;
    int work_days;
    public: 
    fullTime(std::string n,std::string g,float a,int s,std::string r,std::string j,int ded,int wd):employee(n,g,a,s,r,j)
    {
        deduction_per_day = ded;
        work_days = wd;
    }
    void set_workDays(int wd)
    {
        work_days = wd;
    }
    void set_deduction_per_day(int ded)
    {
        deduction_per_day = ded;
    }
    int get_workDays()
    {
        return work_days;
    }
    int get_deduction()
    {
        return deduction_per_day;
    }
    int get_salary() override
    {
        return employee::get_salary()/22*work_days-deduction_per_day*work_days;
    }
    void display() override
    {
        employee::display(); // to print employee attributes
        std::cout<<work_days<<" "<<deduction_per_day<<" "<<get_salary()<<std::endl;
    }


};

class postgradstudent : public student
{
    private :
    std::string research_interest;
    public :
    postgradstudent(std::string n,std::string g,float a,int sl,float gpa,std::string ri):student(n,g,a,sl,gpa)
    {
        research_interest = ri;
    }

    void set_research_interest(std::string res_int)
    {
        research_interest = res_int;
    }

    std::string get_research_interest() const //when method is not modifying the attribute
    {
        return research_interest;
    }
    void display() override
    {
        student::display(); // to print student attributes
        std::cout<<research_interest<<std::endl;
    }
};


class teaching_assistant : public employee, public student // multiple inhertence
{
    private:
    std::string research_interest;
    public:
    teaching_assistant(std::string n,std::string g,float a,int s,std::string r,std::string j,int sl, float gpa,std::string ri):employee(n,g,a,s,r,j),student(n,g,a,sl,gpa)
    {
        research_interest = ri;
    }
    void set_research_int(std::string ri)
    {
        research_interest = ri;
    }
    std::string get_research_int()
    {
        return research_interest;
    }
    void display() override
    {
        employee::display(); // to print employee attributes
        student::display(); //to print student attributes
        std::cout<<research_interest<<std::endl;
    }
};


int main()
{
    person p("Mohamed", "male", 23);
    student s("omar", "male", 23, 4, 3.2);
    postgradstudent psg("mazen","male",23,3,3.5,"robotics");
    employee emp("mahmoud","male",30,1000,"senior","staff");
    hour hr("gamal","male",45,2000,"princ","staff",80,30);
    fullTime fT("Hisham","male",50,3000,"junior","staff",50,16);
    teaching_assistant ta("fatma","female",28,4000,"sophomore","teacher",3,3.8,"history");
    p.display();
    s.display();
    emp.display();
    hr.display();
    fT.display();
    ta.display();
    //psg.display();
}