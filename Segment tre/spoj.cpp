#include<bits/stdc++.h>
using namespace std;
#define MX 100001
int arr[MX];
int tree[MX];
int divis[MX];

void init(int node, int b, int e){
    if (b==e){
        tree[node] = arr[b];

        if (tree[node]%3==0){
            divis[node] = 1;
        }else{
            divis[node] = 0;
        }

        return;
    }

    int left = node*2;
    int right= (node*2)+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    divis[node] = divis[left]+divis[right];

}

int query(int node, int b, int e, int i, int j){
    if (i>e || j<b){
        
    }
    if (b>=i && e<=j){
        return divis[node];
    }
    //partial
    int left = node*2;
    int right= (node*2)+1;
    int mid = (b+e)/2;

    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid+1, e, i, j);
    cout << "hidden : " << q1+q2 << endl ;
    return q1+q1;

    
}

void update(int node, int b, int e, int i, int newvalue){
    if (i>e || i<b){
        return;
    }
    if (b>=i && e<=i){
        tree[node] += newvalue;
         if (tree[node]%3==0){
            divis[node] = 1;
        }else{
            divis[node] = 0;
        }
    }

    int left = node*2;
    int right= (node*2)+1;
    int mid = (b+e)/2;

    update(left, b, mid,i,newvalue) ;
    update(right, mid+1, e,i,newvalue) ;
    divis[node] = divis[left]+divis[right];
    
}


int main(){
    int n, q;

    cin >> n;
    for (int i =1; i<=n; i++){
        arr[i] = 0;
    }

    init(1,1,n);
    for (int i =1; i<=8; i++){
        cout << divis[i] << " ";
    }
    int cmd, start, end;
    cin >> cmd >> start >> end;

    if (cmd == 1){
        cout << query(1,1,n,start, end);

    }



}