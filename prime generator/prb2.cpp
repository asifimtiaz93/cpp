#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
bool prime[N];

void primegen(){
    for (int i=0; i<=N; i++){
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;

    for (int i=4; i<=N; i=i+2){
        prime[i] = false;
    }
    for (int i=3; i<=N; i=i+2){
        if (prime[i] == true){
            for (int j = i*i; j<=N; j+=i*2){
                prime[j] = false;
            }
        }
    }
}


int main(){
    primegen();
    int count =0;
    int input;
    cin >> input;
   
    for (int i=6; i<=input; i++){
        int n = i;
        if (!prime[n]){
            set <int> st;
            for(int j=2; j*j<=n; j++){
            while(n%j == 0){
                n = n/j;
                st.insert(j);
            }
        }
        if (n>2) st.insert(n);

        if (st.size()==2) {
            cout << i;
            count++;
        }
        }
        
    }

    cout << count;
}