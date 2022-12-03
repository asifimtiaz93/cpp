#include<bits/stdc++.h>
using namespace std;

bool arr[100];
int NN=100;

void seive(){
    for (int i = 0; i<=NN; i++){
        arr[i] = true;
    }
	arr[0]=0; arr[1]=0;
	for(int i=2; i*i<=NN; i++){
		if(arr[i]){
			for(int j=i*i; j<=NN; j+=i){
				arr[j]=0;	
			}
		}
	}
}

signed main()
{
	seive();
	int t; cin>>t;
    while(t--){
    	int n; cin>>n;
    	int nn=sqrt(n);
    	
    	bool ok=false;
    	if(nn*nn == n and arr[nn]) ok=true;

    	if(ok) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0 ; //It's Sabbir
}
