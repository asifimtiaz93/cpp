#include<bits/stdc++.h>

using namespace std;

int main()
{
    map <string,int> m;
    m["asif"] = 11;
    m["imtiaz"] = 33;
    m["afia"] = 71;

    map<string, int> ::iterator p;
    p = m.begin();
    while(p!=m.end()){
        cout << p->first;
        cout <<  " ";
        cout << p->second <<endl;
        p++;
    }
    cout <<m.size();

    cout <<endl<<endl;
    map <int, vector<int>> mv;
    mv[2].push_back(5);
    mv[2].push_back(6);
    mv[3].push_back(5);

    map <int, vector<int>> ::iterator k;
    k = mv.begin();
    while(k!=mv.end()){
        cout << k->first <<endl;
        for(int i=0; i<k->second.size(); i++){
            cout<<k->second[i];
        }
        k++;

    }



}