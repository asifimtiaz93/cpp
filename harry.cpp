#include <iostream>
using namespace std;
int n;
int ps[100];
int memo[999][999];
int split[999][999];
int colorcode[100][100];

void lcsbottom(){
    // for (int i=1; i<=n; i++){
    //     memo[i][i] = 0;
    // }

    for (int l=2; l<=n; l++){
        for (int i=1; i<=n-l+1; i++){
                    int j = i+l-1;
                    int minvalue = 999999;
                    

                    for (int k = i; k<j; k++){
                        int value = memo[i][k]+memo[k+1][j]+colorcode[i][k]* colorcode[k+1][j];
                        if (value<=minvalue){
                            minvalue = value;
                            memo[i][j] = minvalue;
                            colorcode[i][j] = (colorcode[i][k]+colorcode[k+1][j])%100;
                        }

                    }
                   
                    
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
        
    for (int i = 1; i <= n; i++){
        cin >> colorcode[i][i];
    }    

    lcsbottom();
    cout << memo[1][n]<< endl;
    // parenthesize(1,n);
}