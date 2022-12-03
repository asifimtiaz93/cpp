#include <bits/stdc++.h>
using namespace std;
#define MX 100001

int arr[MX];
int tree[MX*3];


int init(int node, int b, int e){
    if (b == e){
        tree[node] = arr[b];
        return tree[node];
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    init(left, b,mid);
    init(right, mid+1, e);
    
    return tree[node] = max(tree[left], tree[right]);


}
int query(int node, int b, int e, int i, int j){
    if (i>e || j<b){
        return INT_MIN;
    }
    if (b>=i && e<=j){
        return tree[node];
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    int left_max = query(left, b, mid, i, j);
    int right_max = query(right, mid+1, e, i, j);

    return tree[node] = max(left_max, right_max);


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

cout << "Enter Range: " << endl;
int i,j;
cin>>i >> j;

cout << query(1,1,n,i,j);


}