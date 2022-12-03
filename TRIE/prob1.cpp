#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int EOW;
    Node *children[26];

    Node(){
        EOW = 0;
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
    }

};

void insert(Node *temp, string s){
    int n=s.size();
    for (int i=0; i<n; i++){
        int pos = s[i]-'A';
        if (temp->children[pos]== NULL) temp->children[pos] = new Node();
        temp = temp->children[pos];

    }
    temp->EOW+=1;
}

int search(Node *temp, string s){
    int n = s.size();
    
    for (int i=0; i<n; i++){
        if (temp == NULL) return 0;
        int pos = s[i]-'A';
        temp  = temp->children[pos];
    }
    if (temp->EOW==0) return 0;
    return temp->EOW;
}

bool isLeaf(Node *temp){
    for (int i=0; i<26; i++){
        if (temp->children[i] != NULL){
            return 0;
        }
    }
    return 1;
}

bool isJunction(Node *temp){
    if (temp->EOW>=1) return 1;
    if (isLeaf(temp)) return 0;
    return 1;
}

void removeEdge(Node *temp, char c, int d){
    if (d == 0) return;

    int pos = c-'A';
    Node *toDelete = temp->children[pos];
    temp->children[pos] = NULL;
    delete toDelete;
}

bool delete_(Node *temp, string s, int k){
    if (temp == NULL) return 0;
    if (k==s.size()){
        if (temp->EOW == 0) return 0;
        if (isLeaf(temp)==0){
            temp->EOW-=1;
            return 0;
        }
        return 1;
    }

    int pos = s[k]-'A';
    int d = delete_(temp->children[pos], s, k+1);
    removeEdge(temp, s[k], d);
    if (isJunction(temp)==1) d=0;

    return d;
}
void printTrie(Node *cur, string s=""){
    if (cur->EOW>=1){
        cout << s << endl;
    }
    for (int i=0; i<26; i++){
        if (cur->children[i] != NULL){
            char c = char(i+65);
            printTrie(cur->children[i], s+c);
        }
    }
}
int main(){
    Node *root = new Node();
    insert(root, "BUP");
    insert(root, "MIST");
    printTrie(root);
    cout << search(root, "MIST");

    delete_(root, "MIST", 0);
    printTrie(root);
}