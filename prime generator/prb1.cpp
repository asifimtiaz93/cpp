#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
bool prime[N];

void setPrime(){
    for (int i=0; i<=N; i++){
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;

    for (int i=4; i<=N; i=i+2){
        prime[i] = false;
    }

    for (int i=3; i <=N ; i=i+2){
        if (prime[i] == true){
            for (int j = i*i ; j<=N; j =j+ (2*i)){
                prime[j] = false;
            }
        }
    }
}



int main(){
setPrime();


int testcase;
cin >> testcase;

for (int i=0; i<testcase; i++){
    int n;
    cin>> n;

    
    int rooted_n = sqrt(n);
    cout << rooted_n << endl;
    cout << rooted_n*rooted_n << endl;
    if (rooted_n*rooted_n == n and prime[rooted_n]==true){
        cout << "YES" << endl;
    }else{
        cout << "No" << endl;
    }
}


}