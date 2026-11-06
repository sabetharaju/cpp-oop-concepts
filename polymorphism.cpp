#include<iostream>
using namespace std;
using std::string;

class AbstractEmployee{
public:
    virtual ~AbstractEmployee() = default;
    virtual void askForPromotion() = 0;
};

class Employee:public AbstractEmployee{


private:
    int age;
protected:
    string Name;

public:

    ~Employee() override = default;

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
    void displayInfo(){
        std::cout<< "Name "<<Name<<std::endl;
        std::cout<< "Age "<<age<<std::endl;
    }
    Employee(string name, int a){
        Name = name;
        age = a;
    }

    void askForPromotion() override{
        if(age >= 25){
            std::cout<< Name <<" is eligible for promotion."<<std::endl;
        } else {
            std::cout<< Name <<" is not eligible for promotion."<<std::endl;
        }
    }
    virtual void work(){
        std::cout<< Name <<" is checking emails."<<std::endl;
    }
};

class Developer: public Employee{
public:
    string favoriteLanguage;

    Developer(string name, int a, string lang)
    : Employee(name, a){
        favoriteLanguage = lang;
    }
    void Fixbug(){
        std::cout<< Name <<" fixed a bug using "<<favoriteLanguage<<std::endl;
    }
    void work() override{
        std::cout<< Name <<" is writing "<<favoriteLanguage<<" code."<<std::endl;
    }
};

class Teacher:public Employee {
 public:   
    string subject;
     

    Teacher(string name, int a, string sub)
    : Employee(name, a){
        subject = sub;
    }
    void work() override{
        std::cout<< Name <<" is teaching "<<subject<<" well."<<std::endl;
    }
};

int main(){
    
    Developer d = Developer("Bob", 20, "C");
    Teacher t = Teacher("Alice", 30, "Math");
    
    Employee* e1 = &d;
    Employee* e2 = &t;
    e1->work();
    e2->work();
}
