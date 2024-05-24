#include<iostream>
#include<vector>
template<typename T1,typename T2>


struct pair
{
    T1 first;
    T2 second;
    pair(T1 f,T2 s):first(f),second(s)
    {

    }
    void display()
    {
        std::cout<<first<<" "<<second<<"\n";
    }
};

int main()
{
    pair<int,std::string> p(1,"mahmoud");
    p.display();
    // similar to array and vector which are template classes std::array<int,10> myarray;
    //below is std pair in C++ --> we use it with vector to make data container

    std::vector<std::pair<int,std::string>> p1;
    // p1 is a vector of type pair which is type of int and string
    //vector has some cool functions like push back to add date
    p1.push_back(std::make_pair(1,"omar"));
    p1.push_back(std::make_pair(2,"mahmoud"));
    p1.push_back(std::make_pair(3,"hisham"));
    for (int i=0;i<p1.size();i++)
    {
        std::cout <<p1[i].first<<"\t"<<p1[i].second<<"\n";
    }
    return 0;
}