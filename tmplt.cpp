#include <bits/stdc++.h>

using namespace std;
template <class T>
class Calculator{
private:
    T n1;
    T n2;
public:
    Calculator(T num1, T num2){
        n1 = num1;
        n2 = num2;
    }
    void displayResult(){
        cout << " a+b = "<<add() << endl;
        cout << " a-b = "<<subtract() << endl;
        cout << " a*b = "<<multiply() << endl;
        cout << " a/b = "<<divide() << endl;
    }
    T add() {return n1+n2;};
    T subtract() {return n1-n2;};
    T multiply() {return n1*n2;};
    T divide() {return n1/n2;};
};

int main(){
    Calculator <int> intCalc(2,3);
    intCalc.displayResult();
    Calculator <float> floatCalc(5.2,3.2);
    floatCalc.displayResult();
}