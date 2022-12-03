#include<bits/stdc++.h>
using namespace std;
int N;

bool visited[20]={0};
int ans[20] = {1};

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int a){
    for (int n: prime)
        if (n ==a) return true;
    return false;
}

void backtracking(int len){
    if (len==N){
        if (!isPrime(ans[N-1]+1))
            return;
        
        cout << "1 ";
        for (int i=1; i<N; ++i)
            cout << ans[i] << " ";
        
        cout << endl;
        return;
    }


    for (int i=2; i<=N; ++i){
        if (visited[i])continue;
        if (isPrime(i+ans[len-1])){
            visited[i] = 1;
            ans[len] = i;

            backtracking(len+1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> N;
    backtracking(1);
}