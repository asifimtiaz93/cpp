#include <iostream>
using namespace std;
int n;
int ps[100];
int memo[999][999];
int split[999][999];


void lcsbottom(){
    for (int i=1; i<=n; i++){
        memo[i][i] = 0;
    }

    for (int l=2; l<=n; l++){
        for (int i=1, j=l; 
                 i<=n-l+1; 
                 i++,j++){
                    int minvalue = 999999;
                    int splitpos;

                    for (int k = i; k<j; k++){
                        int value = memo[i][k]+ 
                                    memo[k+1][j]+
                                    (ps[i-1]*ps[k]*ps[j]);
                        if (value<=minvalue){
                            minvalue = value;
                            splitpos = k;
                        }

                    }
                    memo[i][j] = minvalue;
                    split [i][j] = splitpos; 
                 }
    }
}

void parenthesize(int i, int j){
    if (i == j){
        cout << "A" << i << " ";
    }
    else{
        cout << "(" ;
        parenthesize(i, split[i][j]);
        parenthesize(split[i][j]+1, j);
        cout << ")";
    }
}
int main(){
    cin >> n;
    
    int c=0;
    for (int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        ps[c] = u;
        c++;
        ps[c] = v;
    }

    lcsbottom();
    cout << memo[1][n]<< endl;
    parenthesize(1,n);
}