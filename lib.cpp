#include <iostream>
using namespace std;
class User{
    int id;
    string name;
    string password;
    string email;
    long int phnNo;
public:
    void setId(int id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    void phnNo(long int phnNo){
        this->phnNo = phnNo;
    }
    void email(string email){
        this->email = email;
    }
    void password(string password){
        this->password = password;
    }

};
int main(){

}