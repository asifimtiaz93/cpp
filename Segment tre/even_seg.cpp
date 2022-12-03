#include <bits/stdc++.h>
using namespace std;
#define MX 100001

int arr[MX];
int tree[MX*3];
void init(int node, int b, int e){
    if (b ==e ){
        if (arr[b]%2 == 0){
            tree[node] = 1;
        }else{
            tree[node] = 0;
        }
        return;
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    
    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left]+tree[right];

}
int main(){

    arr[1] = 2;
arr[2] = 9;
arr[3] = 11;
arr[4] = 5;
arr[5] = 8;

int n = 5;

init(1,1,n);

for (int i=0; i<4*n; i++){
    cout << tree[i] << " ";
}

}