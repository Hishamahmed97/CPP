#include <iostream>
#include <string>

// Here composition relation is depticed
// Room class cannot exist without the existance of house

class Room;

class House
{
    private:
    Room * livingRoom;
    Room * kitchen;
    ~House(){
        delete livingRoom;
        delete kitchen;
    };
    
    public:
    House():livingRoom(new Room()),kitchen(new Room()){}
};

class Room
{
    private:
    int size;
    public:
    Room():size(0){} //default constructor
};

