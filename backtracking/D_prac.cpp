#include<bits/stdc++.h>
using namespace std;
int N;

bool ans[20] = {1};
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int a){
    for (int n: prime){
        if (n==a) return true;
    }
    return false;
}

void backtracking(int n, bool visit[]){
    
    if (n == N){
        if (!isPrime(ans[N-1]+1)){
            return;
        } 
        cout << "1";
        for (int i=1; i<N; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;

    }
    for (int i=2; i<=N; ++i){
        if (visit[i]) continue;
        if (isPrime(i+ans[n-1])){
            cout << "d";
            visit[i] = 1;
            ans[n] = i;

            backtracking(n+1, visit);
            visit[i] = 0;
        }

    }
}


int main(){
    
    cin >> N;
    bool visit[20] = {0};
    backtracking(1,visit);

}