#include<iostream>
using namespace std;
using std::string;

class Employee{
private:
    string Name;
    static int employeeCount;   // shared across ALL Employee objects, not per-object

public:
    Employee(string name){
        Name = name;
        employeeCount++;        // every new Employee increments the shared counter
    }

    ~Employee(){
        employeeCount--;
    }

    string getName(){
        return Name;
    }

    // static member function - can be called without an object, and can only
    // access static members (no access to Name, age, etc.)
    static int getEmployeeCount(){
        return employeeCount;
    }
};

// static members must be defined once outside the class
int Employee::employeeCount = 0;

int main(){
    std::cout<<"Employees before hiring: "<<Employee::getEmployeeCount()<<std::endl;

    Employee emp1("John");
    Employee emp2("Alice");
    Employee emp3("Bob");

    std::cout<<"Employees after hiring 3: "<<Employee::getEmployeeCount()<<std::endl;

    {
        Employee temp("Temp Contractor");
        std::cout<<"While contractor is active: "<<Employee::getEmployeeCount()<<std::endl;
    } // temp goes out of scope here, destructor runs, count decreases

    std::cout<<"After contractor left: "<<Employee::getEmployeeCount()<<std::endl;
}
