#include<iostream>
using namespace std;
using std::string;

class Employee{
private:
string Name;
int age;
int EmpId;
string company;
string role;
      

public:

    void setName(string name){
        Name = name;
    }
    void setAge(int a){
        if(a >= 18){
            age = a;
        }
    }
    string getName(){
        return Name;
    }
    int getAge(){
        return age;
    }
        void setEmpId(int id){
        EmpId = id;
    }
    int getEmpId(){
        return EmpId;
    }
    void setCompany(string comp){
        company = comp;
    }
    string getCompany(){
        return company;
    }
    void setRole(string r){
        role = r;
    }
    string getRole(){
        return role;
    }
    void dispalyinfo(){
        std::cout<< "Name "<<Name<<std::endl;
        std::cout<< "Age "<<age<<std::endl;
        std::cout<< "Employee ID "<<EmpId<<std::endl;
        std::cout<< "Company "<<company<<std::endl;
        std::cout<< "Role "<<role<<std::endl;
    }
    Employee(string name, int a, int id, string comp, string r){
        Name = name;
        age = a;
        EmpId = id;
        company = comp;
        role = r;
    }
};

int main(){
    Employee emp1("John", 30, 1, "CompanyA", "Manager");
    emp1.dispalyinfo();

    Employee emp2("Alice", 25, 2, "CompanyB", "Developer");
    emp2.dispalyinfo();

    emp1.setName("Meena");
    emp1.setAge(15);
    emp1.dispalyinfo();

    std::cout<<emp1.getName()<<" is "<<emp1.getAge()<<" years old. "<<emp1.getCompany()<<" company."<<std::endl;
    std::cout<<emp2.getName()<<" is "<<emp2.getAge()<<" years old. "<<emp2.getCompany()<<" company."<<std::endl;
    
    }
