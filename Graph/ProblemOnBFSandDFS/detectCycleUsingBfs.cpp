#include <bits/stdc++.h> 
using namespace std;

// Function to detect a cycle using BFS
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1; // Mark the source node as visited
    queue<pair<int, int>> q; // Queue stores {node, parent}
    q.push({src, -1}); // Push source node with no parent (-1)

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Traverse all adjacent nodes
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) { // If the adjacent node is not visited
                vis[adjacentNode] = 1; // Mark it as visited
                q.push({adjacentNode, node}); // Push it into the queue with the current node as parent
            } 
            // If the adjacent node is visited and is not the parent of the current node, a cycle exists
            else if (parent != adjacentNode) {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle detected
}

// Function to check if the graph contains a cycle
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0}; // Initialize visited array with all zeros (not visited)

    // Check for cycles in each component of the graph
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If node is not visited, call BFS to detect a cycle
            if (detect(i, adj, vis)) 
                return true; // If cycle found, return true
        }
    }
    return false; // No cycle found in any component
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<int> adj[n]; // Adjacency list representation of the graph

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Add edge (u -> v)
        adj[u].push_back(v);

        // Add edge (v -> u) since the graph is undirected
        adj[v].push_back(u);
    }

    // Check if the graph contains a cycle
    if (isCycle(n, adj)) {
        cout << "Cycle present";
    } else {
        cout << "Cycle not present";
    }

    return 0;
}
