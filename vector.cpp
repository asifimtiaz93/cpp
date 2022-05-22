#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(5);
    cout << v.size()<<" ";
    cout<<v.capacity();
    v.push_back(6);
    cout << v.size()<<" ";
    cout<<v.capacity();
    v.push_back(7);
    cout << v.size()<<" ";
    cout<<v.capacity();
    v.push_back(8);
    cout << v.size()<<" ";
    cout<<v.capacity();
    v.push_back(9);
    cout << v.size()<<" ";
    cout<<v.capacity();
    for (int i=0; i<v.size(); i++){
        cout<< v[i]<<endl;
    }
}