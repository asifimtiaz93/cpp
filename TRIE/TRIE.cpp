#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
class Node
{
public:
    int EoW;
    Node *children[26];        ///array of pointer , not pointing an array
                                ///initially they are just pointer , not dynamically allocated memory
    Node(){
        EoW=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    ~Node(){
        for(int i=0;i<26;i++){      ///As children is an array of pointers , not pointing an array
            delete children[i];     /// so , individual destruction is necessary
        }
    }
};
void Insert(Node *temp,string s)
{
    int n=s.size();    ///temp is pointing to root
    for(int i=0;i<n;i++){
        int rp=s[i]-'A';
        if(temp->children[rp]==NULL) temp->children[rp]= new Node();
        temp=temp->children[rp];
    }
    temp->EoW++;
}
int Search(Node *root,string s)
{
    int n=s.size();
    Node *temp=new Node();
    temp=root;
    for(int i=0;i<n;i++){
        if(temp==NULL) return 0;
        int x=s[i]-'A';
        temp=temp->children[x];
    }
    if(temp->EoW==0) return 0;
    return temp->EoW;
}
bool isLeaf(Node *temp)
{
    for(int i=0;i<26;i++){
        if(temp->children[i]!=NULL)
            return 0;
    }
    return 1;
}
bool isJunction(Node *temp)
{
    if(temp->EoW>=1) return 1;
    if(isLeaf(temp)) return 0;   ///if the edge is leaf then it is not junction
    return 1;
}
void removeEdge(Node *temp,char c,int d)
{
    if(d==0) return ;  ///don't delete edge
    int x=c-'A';
    Node *toDelete=temp->children[x];
    temp->children[x]=NULL;
    delete toDelete;
}
bool Delete(Node *temp,string s,int k)
{
    if(temp==NULL) return 0;
    if(k==s.size()){
        if(temp->EoW==0) return 0;
        if(isLeaf(temp)==0){      ///Not leaf node
            temp->EoW-=1;         ///simply decreasing EoW by 1
            return 0;             ///No need of edge deletion
        }
        return 1;                 ///if Leaf and Eow>0, then edge deletion is needed =>> so return 1
    }
    int x=s[k]-'A';
    int d=Delete(temp->children[x],s,k+1);
    removeEdge(temp,s[k],d);
    if(isJunction(temp)==1)  d=0;  ///if temp reaches to a junction point,
                                    ///then the deletion of edge is not needed anymore
    return d;
}

void printTRIE(Node *cur , string s="")
{
    if(cur->EoW>=1){
        cout<<s<<"\n";
    }
    for(int i=0;i<26;i++){
        if(cur->children[i]!=NULL)
        {
            char c=char(i+65);
            printTRIE(cur->children[i],s+c);
        }
    }
}
int main()
{
    Node *root=new Node();
    Insert(root,"MIST");
    Insert(root,"MIST");
    Insert(root,"MISTCE");
    Insert(root,"MISTCSE");
    Insert(root,"BUP");
    printTRIE(root);
    cout<<"frequency(MIST) :"<<Search(root,"MIST")<<"\n";
    Delete(root,"MIST",0);
    cout<<"frequency(MIST) :"<<Search(root,"MIST")<<"\n";
    Insert(root,"CU");
    printTRIE(root);
    cout<<"frequency(CU) :"<<Search(root,"CU")<<"\n";
    Delete(root,"CU",0);
    cout<<"frequency(CU) :"<<Search(root,"CU")<<"\n";
    Delete(root,"CU",0);
    cout<<"frequency(CU) :"<<Search(root,"CU")<<"\n";
    delete root;
}

