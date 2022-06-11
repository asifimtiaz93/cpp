#include <bits/stdc++.h>
using namespace std;

// adjacency matrix
vector<vector<int> > adj;
 
// function to add edge to the graph
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

int main(){
    // number of vertices
    int v = 5;
 
    // number of edges
    int e = 4;
 
    // adjacency matrix
    adj = vector<vector<int> >(v, vector<int>(v, 0));
 
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);


}