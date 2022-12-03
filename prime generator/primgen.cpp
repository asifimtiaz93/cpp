#include <bits/stdc++.h>
using namespace std;
bool prime[10000];

void primegen(int n){
    for (int i=0; i<n; i++){
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i=4; i<n; i+=2){
        prime[i] = false;
    }

    for (int i= 3; i<n; i+=2){
        if (prime[i]==true){
            for (int j = i*i; j<n; j+=i*2){
                prime[j] = false;
            }
        }
    }
}


int main(){
    primegen(100);
    int n;
    while(true){
        cin >> n;
        if (prime[n]) cout << "prime" << endl;
        else cout << "not prime" << endl;
    }


}