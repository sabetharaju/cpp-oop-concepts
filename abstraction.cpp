#include<iostream>
using namespace std;
using std::string;

class AbstractEmployee{
    virtual void askForPromotion() = 0;
};

class Employee: public AbstractEmployee{

private:
    string Name;
    int age;

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
    void dispalyinfo(){
        std::cout<< "Name "<<Name<<std::endl;
        std::cout<< "Age "<<age<<std::endl;
    }
    Employee(string name, int a){
        Name = name;
        age = a;
    }

    void askForPromotion(){
        if(age >= 25){
            std::cout<< Name <<" is eligible for promotion."<<std::endl;
        } else {
            std::cout<< Name <<" is not eligible for promotion."<<std::endl;
        }
    }
};

int main(){
    Employee emp1("John", 30);
    Employee emp2("Alice", 20);

    emp1.askForPromotion();
    emp2.askForPromotion();
}
