#include <bits/stdc++.h>
using namespace std;

int adj[6][6];
map<int,bool> v;
map<int,int> dt;
map<int,int> tt;
map<int,int> parent;
int t=0;
void dfs(int s){
    v[s] = true;
    // dt[s] = 1;
    // tt[s] = 0;
    // parent[s] = -1;
    cout << s;
    for (int i=0; i<6; i++){
        if (adj[s][i] == 1 && (!v[i])){
            
            t++;
            dt[i] = t;
            // tt[i] = t+1;
            parent[i] = s;
            dfs(i);
            tt[s] = tt[s]+1;
        }
        
    }
    

}

int main(){
    int n,e;
    cin >> n >> e;

    for (int i=0; i<6;i++){
        for (int j=0; j<6; j++){
            adj[i][j] = 0;
        }
    }
    for (int i=0; i<6;i++){
        for (int j=0; j<6; j++){
         cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<e; i++){
        int x, y;
         cin >> x >> y;

        adj[x][y] = 1;
        adj[y][x] = 1;

    }


    dfs(0);
   
    cout << endl;
    
    map <int,int> ::iterator it;
    for (it = parent.begin(); it!=parent.end(); it++){
        cout << it->first << " " << it->second<<endl;
    }
    map <int,int> ::iterator i;
    for (i = dt.begin(); i!=dt.end(); i++){
        cout << i->first << " " << i->second<<endl;
    }
    map <int,int> ::iterator in;
    for (in = tt.begin(); in!=tt.end(); in++){
        cout << in->first << " " << in->second<<endl;
    }



}