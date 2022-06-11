#include <bits/stdc++.h>
using namespace std;

map <int, vector <int>> m;
map <int,bool> v;

void dfs(int s){
    v[s] = true;
    //cout << s << " ";
    
    vector <int> ::iterator i;
    for (i = m[s].begin(); i!=m[s].end(); i++){
        if (!v[*i]){ /// visited kina???
            dfs(*i);
        }
    }
}

int main(){
    int n,e;
    cout<< "Enter number of vertex and edges: ";
    cin >> n >> e ;

    cout << "Enter edges: "<<endl;
    
    while(e--){
        int x,y;
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
    }

    dfs(0);
    
}