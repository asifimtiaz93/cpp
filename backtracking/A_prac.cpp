#include<bits/stdc++.h>
using namespace std;
int n,k;
char ch[27];
bool visited [27];

void permutaion(int pos){
    if (k==0) return;
    else if(pos == n){
        k--;
        for (int i=0; i<n; i++){
            cout << ch[i];
        }
        cout << endl;
        return;
    }
    for (int i=0; i<n; i++){
        if (visited[i]) continue;
        visited[i] = 1;
        ch[pos] = i+'A';
        permutaion(pos+1);
        visited[i] = 0;

    }
}

int main(){
cin >> n >> k;
permutaion(0);
}