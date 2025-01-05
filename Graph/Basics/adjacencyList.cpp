#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Adjacency list to store a weighted graph
    vector<pair<int, int>> adj[n + 1]; // 1-based indexing

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        // Add edge (u -> v) with weight
        adj[u].push_back({v, wt});

        // Add edge (v -> u) with weight for undirected graph
        adj[v].push_back({u, wt});
    }

    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto it : adj[i]) {
            cout << "(" << it.first << ", " << it.second << ") "; // Print (neighbor, weight)
        }
        cout << endl;
    }

    return 0;
}
