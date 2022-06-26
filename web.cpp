#include <bits/stdc++.h>

using namespace std;

class Human{
public:
    int age;
    string name;

    Human(int age, string name){
        this->age = age;
        this->name = name;
    }
    virtual int getSal()=0;
    void display(){
        cout << "Name: " << name<< endl;
        cout << "Age: "<< age << endl;
    }
    Human(){}; //dummy constr(as default constr)
};

class Student: virtual public Human{
public:
    int roll;
    float gpa;

    Student(int roll, float gpa, int age, string name): Human(age,name){
        this->roll = roll;
        this->gpa = gpa;
    }
    void display(){
        Human::display();
        cout << "Roll: " << roll << endl;
        cout << "GPA: " << gpa << endl;
    }
    Student(){}; // dummy
};

class Photographer: virtual public Human{
public:
    string camera;
    int salary;

    Photographer(string camera, int salary, int age, string name): Human(age,name){
        this->camera = camera;
        this->salary = salary;
    }
    int getSal(){
        return salary;
    }
    void display(){
        Human::display();
        cout << "Camera : " << camera << endl;
        cout << "Salary : " << salary << endl;
    }
    Photographer(){}; // dummy
};

class AmeturePhotographer: public Student, public Photographer{
public:
    string dept;
    //sloution of diamond problem
    AmeturePhotographer(string dept,string camera, int salary, int roll, float gpa, int age, string name): Student(roll,gpa,age,name),Photographer(camera,salary,age,name),Human(age,name){
        this->dept = dept;
    }
    void display(){
        Student::display();
        Photographer::display();
        cout << "Dept:" << dept << endl;

    }
    int getSal(){
        return salary+ 300;
    }
    AmeturePhotographer(){}; // dummy

};
void printSal(Human *h){
    cout << "Salary: "<< h->getSal() << endl;
}
int main(){
    AmeturePhotographer* ob = new AmeturePhotographer[100];
    ob[0] = AmeturePhotographer("EECE", "NIKON", 600, 17, 2.40, 29, "milon");
    AmeturePhotographer am("CSE", "Canon", 500, 13, 3.40, 19, "kalu");
    Human *ptr;
    ptr = &am;
    printSal(ptr); //POC obj slicing
    am.display(); //POC diamond prob


    cout << endl;
    ob[0].display(); // POC array of objects

    //poc writing obj to file
    ofstream out ("record.txt", ios::out)    ;
    out.write((char *) &ob[0], sizeof(ob[0]));

    ifstream in ("record.txt", ios::in);
    in.read((char*) &ob[1], sizeof(ob[1]));

    cout << ob[1].camera;



}