#include<iostream>
#include<string>
using std::string;

class Employee{
public:
string Name;
int age;
int EmpId;
string company;
string role;

    void dispalyinfo(){
        std::cout<<std::endl;
        std::cout<< "EmployeeName is "<<Name<<std::endl;
        std::cout<<age<<" years old."<<std::endl;
        std::cout<< "Employee Id is "<<EmpId<<std::endl;
        std::cout<< "Working in "<<company<<" Company."<<std::endl;
        std::cout<< "In the position as "<<role<<"."<<std::endl;
    }
    Employee(string name, int a, int id, string comp, string r){
        Name = name;
        age = a;
        EmpId = id;
        company = comp;
        role = r;
    }
    Employee(){
        age = 0;
        EmpId = 0;
    }
};

int main(){
    string name, company, role;
    int n, age, empId;
    Employee employees[100];

    std::cout<<"Enter the number of employees: ";
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cout<<"Enter employee "<<i+1<<" details:"<<std::endl;
        std::cout<<"Name: ";
        std::cin>>name;
        std::cout<<"Age: ";
        std::cin>>age;
        std::cout<<"Employee ID: ";
        std::cin>>empId;
        std::cout<<"Company: ";
        std::cin>>company;
        std::cout<<"Role: ";
        std::cin>>role;

        employees[i] = Employee(name, age, empId, company, role);
    }

    std::cout<<std::endl<<"All Employee Details:"<<std::endl;
    std::cout<<"================================"<<std::endl;
    for(int i=0;i<n;i++){
        employees[i].dispalyinfo();
        std::cout<<std::endl;
    }
    std::cout<<"================================"<<std::endl;

}
