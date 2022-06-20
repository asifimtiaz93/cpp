#include <bits/stdc++.h>

using namespace std;

class Person{
public:
    string name;
    int id;
protected:
    string designation;
private:
    int contact;
public:
    virtual int getSal() =0;

    Person(int id, string name, string designation, int contact){
        this->id = id;
        this->name = name;
        this->designation = designation;
        this->contact= contact;
    }
};

class Employee: public Person{
private:
    int basicSal;
public:
    int bonus;

    int getSal(){
        return basicSal+bonus;
    }

    Employee(int id, string name, string designation, int contact, int basicSal, int bonus) : Person(id,name, designation, contact){
        this->basicSal = basicSal;
        this->bonus = bonus;
    }

};

class Operator : public Employee{
private:
    int overtime_rate, overtime_hr;
public:
    int getSal(){
        return Employee::getSal() + (overtime_rate*overtime_hr); 
    }
    Operator(int id, string name, string designation, int contact, int basicSal, int bonus, int overtime_rate, int overtime_hr): Employee(id, name, designation, contact, basicSal, bonus){
        this->overtime_rate = overtime_rate;
        this->overtime_hr = overtime_hr;
    }
};


void printSal(Person *p){

    cout << "Salary of Worker Name, ID:" << p->name << " "<< p->id<< " is "<<p->getSal();
}


class Machine{
private:
    string name;
    int id;
protected:
    string model;
public:
    string company;
    virtual int power_consumption()=0;
    virtual void operated_by()=0;

};


class Electric_Machine{
protected:
    int power_rate, hrs_active;
public:
   int  power_consumption(){
        return power_rate*hrs_active;
    }

};


int main(){
    Operator l(12,"rahim", "op", 1767777, 50000, 3000, 500, 5);
    Person * ptr;
    ptr = &l;
    printSal(ptr);

}
