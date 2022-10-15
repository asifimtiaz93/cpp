#include<bits/stdc++.h>
#define in long long
const in INF = 1e9+7 ;

using namespace std ;

in inputPos[1005] ;
in matriX[1005][1005] ;
in n , k ;

void MCM(){
    for(in l=3 ; l<k+3 ; l++){
        for(in i=1 ; i<=k-l+3 ; i++){
            in j=i+l-1 ;
            in anser = INF ;
            for(in k=i+1 ; k<j ; k++){
                in temp = matriX[i][k] + matriX[k][j] + inputPos[j-1] - inputPos[i-1] ;
                if(temp < anser){
                    anser = temp ;
                }
            }
            matriX[i][j] = anser ;
        }
    }
}

int main()
{
    while(cin >> n and n)
    {
        cin >> k ;
        inputPos[0] = 0 ;
        for(in i=1;i<=k;i++) cin >> inputPos[i] ;
        inputPos[k+1] = n ;
    
        MCM() ;
        cout << "The minimum cutting is " << matriX[1][k+2] << "." << endl ;
        
        // cout << "\nMemoization table" << endl ;
        // for(in i=1 ; i<k+3 ; i++){
        //     for(in j=1 ; j<k+3 ; j++){
        //         cout << matriX[i][j] << " " ;
        //     }
        //     cout << endl ;
        // }
    }    
    return 0 ;
}
