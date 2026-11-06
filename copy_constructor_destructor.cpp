#include<iostream>
using namespace std;
using std::string;

class Employee{
private:
    string Name;
    int age;

public:
    Employee(string name, int a){
        Name = name;
        age = a;
        std::cout<< "Constructor called for "<<Name<<std::endl;
    }

    // Copy constructor - called when one object is initialized from another
    Employee(const Employee &source){
        Name = source.Name;
        age = source.age;
        std::cout<< "Copy constructor called for "<<Name<<std::endl;
    }

    ~Employee(){
        std::cout<< "Destructor called for "<<Name<<std::endl;
    }

    void setName(string name){
        this->Name = name;   // 'this' resolves the naming clash with the parameter
    }

    string getName(){
        return this->Name;
    }

    void displayInfo(){
        std::cout<< "Name "<<Name<<", Age "<<age<<std::endl;
    }
};

int main(){
    std::cout<<"--- Creating emp1 ---"<<std::endl;
    Employee emp1("John", 30);

    std::cout<<std::endl<<"--- Creating emp2 as a copy of emp1 ---"<<std::endl;
    Employee emp2 = emp1;   // invokes the copy constructor, not the parameterized one

    emp2.setName("John (copy)");

    std::cout<<std::endl<<"--- Displaying both ---"<<std::endl;
    emp1.displayInfo();
    emp2.displayInfo();

    std::cout<<std::endl<<"--- End of main, destructors fire in reverse order ---"<<std::endl;
}
