#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
bool prime[N];

void primeGen(){
    for (int i=0; i<=N; i++){
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;
    for (int i=4; i<=N; i+=2){
        prime[i] = false;
    }

    for (int i=3; i<=N; i+=2){
        if (prime[i]){
            for (int j=i*i; j<=N; j+=i*2){
                prime[j] = false;
            }
        }
    }
}

int main(){
primeGen();

    int n;
    cin>> n;

    int count =0;
    int i=2;
    while(count <n){
        if (prime[i] && prime[i+2]){
            count++;
        }
        i++;
    }

    cout << "(" << i-1 << " , " << i+2-1 << ")" << endl;

}