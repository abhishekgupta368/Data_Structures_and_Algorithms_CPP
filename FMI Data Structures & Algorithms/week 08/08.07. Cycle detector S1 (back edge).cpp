// github.com/andy489

// https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/-1-12/problem

#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> adj;
vector<bool> visited;

void dfs(int s, bool &cycle) {
    if (visited[s]) {
        cycle = true; // back edge
        return;
    }
    visited[s] = true;
    for (const auto &x : adj[s])
        dfs(x, cycle);
    visited[s] = false;
}

int main() {
    int q, V, E, xi, yi, wi, i;
    cin >> q;
    
    while (q--) {
        bool cycle(false); // cycle detector
        cin >> V >> E;
        
        adj.assign(V, list<int>());
        visited.assign(V, 0);
        
        while (E--) {
            cin >> xi >> yi >> wi; // we do not use wi for detecting cycle!
            --xi;
            --yi;
            adj[xi].push_back(yi);
        }
        
        for (i = 0; i < V; ++i)
            dfs(i, cycle);
        
        cout << (cycle ? "true " : "false ");
    }
    return 0;
}
