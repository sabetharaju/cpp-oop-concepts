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
    }

    string getName(){
        return Name;
    }

    int getAge(){
        return age;
    }

    // Overloading == so two Employee objects can be compared directly with ==
    bool operator==(const Employee &other) const{
        return (this->age == other.age);
    }

    // Overloading + so two Employee objects can be "combined" into a team description
    string operator+(const Employee &other) const{
        return this->Name + " & " + other.Name;
    }

    // Overloading << so an Employee object can be printed directly with std::cout
    friend std::ostream& operator<<(std::ostream &out, const Employee &emp){
        out << emp.Name << " (" << emp.age << ")";
        return out;
    }
};

int main(){
    Employee emp1("John", 30);
    Employee emp2("Alice", 30);
    Employee emp3("Bob", 25);

    std::cout<< "emp1: "<<emp1<<std::endl;   // uses overloaded <<
    std::cout<< "emp2: "<<emp2<<std::endl;
    std::cout<< "emp3: "<<emp3<<std::endl;

    if(emp1 == emp2){                        // uses overloaded ==
        std::cout<< emp1.getName() <<" and "<<emp2.getName()<<" are the same age."<<std::endl;
    }
    if(!(emp1 == emp3)){
        std::cout<< emp1.getName() <<" and "<<emp3.getName()<<" are NOT the same age."<<std::endl;
    }

    std::cout<< "Team formed: "<<(emp1 + emp3)<<std::endl;   // uses overloaded +
}
