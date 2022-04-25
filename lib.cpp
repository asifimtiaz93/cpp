#include <iostream>
#include <ctime>
using namespace std;
class User{
    int id;
    string name;
    string password;
    string email;
    int phnNo;
public:
//setter
    void setId(int id);
    void setName(string name);
    void setphnNo(int phnNo);
    void setemail(string email);
    void setpassword(string password);
//getter
    int getId();
    long int getPhnNo();
    string getName();
    string getEmail();
    string getPassword();
};
class Admin{
    string username = "root";
    string password = "toor";
};

class Book{

    int isbn;
    string name;
    string publication;
    string author;
    float price;

public:
//setter

    void setIsbn(int isbn);
    void setName(string name);
    void setPublication(string publication);
    void setAuthor(string author);
    void setPrice(float price);
//getter

    int getIsbn();
    int getName();
    int getPublication();
    int getAuthor();
    int getprice();

};

class Transaction{
    string name;
    int isbn;
    string bookname;


};
int main(){
    time_t now = time(0);
    char* dt= ctime(&now);
    cout << dt;

}
