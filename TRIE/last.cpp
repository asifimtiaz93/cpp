#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll longest = 0, tempLongest = 0;
string s;
vector<ll> l;

struct Node
{
    ll EOW; ///marks end of word
    Node* children[2];
};

Node *root;

Node* Create()
{
    Node *temp = new Node();
    temp->EOW = 0;
    for(int i=0;i<2;++i)
        temp->children[i] = NULL;
    return temp;
}


void Add(Node* root, string p)
{
    int n = p.size();
    tempLongest = 0;
    for(int i=0;i<n;++i)
    {
        if(root->children[p[i]-'0'] == NULL) /// character not present in trie
        {
            root->children[p[i]-'0'] = Create(); /// root->children[char] now is pointing at a new node
        }

        root = root->children[p[i]-'0'];
        root->EOW++;
       // cout<<root->EOW*(i+1)<<endl;
        l.push_back(root->EOW*(i+1));
       // tempLongest = max(tempLongest,));

    }
}



void Delete()
{
    root->EOW = 0;
    longest = tempLongest = 0;
    for(int i=0;i<2;++i)
    {
        if(root->children[i]!=NULL)
        {
            root->children[i] = NULL;
        }
    }
}


void solve()
{
    root = Create();
    int n; cin>>n;
    vector<string> v(n);
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    //sort(v.begin(),v.end());
    for(auto k:v)
    {
        Add(root,k);
    }
    cout<<*max_element(l.begin(),l.end())<<endl;
    l.clear();
    Delete();

}

/*
4
4
0000
0001
10101
010
2
01010010101010101010
11010010101010101010
3
010101010101000010001010
010101010101000010001000
010101010101000010001010
5
01010101010100001010010010100101
01010101010100001010011010101010
00001010101010110101
0001010101011010101
00010101010101001

*/
int main()
{
    ios
    ll t=1;
    cin>>t;
    for(ll tc=1;tc<=t;++tc)
    {
        //cout<<"Case "<<tc<<": "<<endl;
        solve();
    }
}
