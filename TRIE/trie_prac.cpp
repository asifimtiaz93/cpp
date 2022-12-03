#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int EOW;
    Node *children[26];

    Node(){
        EOW = 0;
        for (int i =0; i<26; i++){
            children[i] = NULL;
        }

    }

    ~Node(){
        for(int i=0;i<26;i++){      ///As children is an array of pointers , not pointing an array
            delete children[i];     /// so , individual destruction is necessary
        }
    }
    

};

void insert(Node *temp, string s){
        int size = s.size();
        
        for (int i=0; i<size; i++){
            int rp = s[i] - 'A';
            if (temp->children[rp] == NULL){
                
                temp->children[rp] = new Node();
                
            }
            temp = temp->children[rp];
        }

        temp->EOW+=1;

    }

    void print_trie(Node *cur, string s=""){
        if (cur->EOW >=1){
            cout << s << endl;
        }

        for (int i=0; i<26; i++){
            if (cur->children[i] !=NULL){
                
                char c = char(i+65);
                print_trie(cur->children[i],s+c);
            }
        }
        
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
        if (temp->EOW >=1) return 1;
        if (isLeaf(temp)) return 0;
        return 1;
    }

    void removeEdge(Node *temp, char c, int d){
        if (d == 0) return;
        int rp = c-'A';
        Node *todelete = temp->children[rp];
        temp->children[rp] = NULL;
        delete todelete;
    }
    bool delete_(Node *temp, string s, int k){
        if (temp == NULL) return 0;
        if (k == s.size()){
            if (temp->EOW == 0) return 0;
            if (isLeaf(temp)==0){
                temp->EOW-=1;
                return 0;
            } 
            else return 1;
        }
        int rp = s[k] - 'A';
        
        int d = delete_(temp->children[rp], s, k+1);

        removeEdge(temp, s[k],  d);
        if (isJunction(temp)==1) d = 0;

        return d;

    }

int main(){
    Node *root = new Node();

    insert(root, "BUP");
    insert(root, "MIT");
    insert(root, "MIST");
    print_trie(root);

    delete_(root, "MIT",0);
    print_trie(root);
}