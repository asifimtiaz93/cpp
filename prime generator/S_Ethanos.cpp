#include <bits/stdc++.h>

using namespace std;

bool prime[100];

void primeset(int n){
    for (int i = 0; i<=n; i++){
        prime[i] = true;
    }

    
    prime[0] = prime[1] = false;

    
    for(int i=2; i<=n; i=i+2){
        prime[i] = false;
    }
    for (int i=3; i<=n; i=i+2){
        if (prime[i]==true){
            for (int j = i*i; j<=n; j+=2*i){
                prime[j] = false;
            }
        }
    }
    //printing prime array...........
    // for (int i = 0; i<=n; i++){
    //     if (prime[i] == true)cout << " 1 ";
    //     else cout << " 0 ";
    // }
}

int main(){
    int n;
    cout << endl;
    cout << "Enter a number: ";
    cin >> n;

    primeset(n);

    cout << "Enter a number to check is it prime? :";
    int q;
    cin >>q;
    if (prime[q] == true){
        cout << "This is a prime";
    }else{
        cout << "This isnt a prime";
    }

}
