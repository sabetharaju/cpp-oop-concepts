#include<iostream>
using namespace std;
using std::string;

class AbstractEmployee{
    virtual void askForPromotion() = 0;
};

class Employee: public AbstractEmployee{

private:
    int age;
protected:
    string Name;

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
};

class Teacher:public Employee {
 public:   
    string subject;
     
    void PrepareLesson(){
        std::cout<< Name <<" is preparing a "<<subject<<" lesson."<<std::endl;
    }
    Teacher(string name, int a, string sub)
    : Employee(name, a){
        subject = sub;
    }
};

int main(){
    
    Developer d = Developer("Bob", 20, "C");
    Teacher t = Teacher("Alice", 30, "Math");
    d.Fixbug();
    d.askForPromotion();
    t.PrepareLesson();
    t.askForPromotion();
}
