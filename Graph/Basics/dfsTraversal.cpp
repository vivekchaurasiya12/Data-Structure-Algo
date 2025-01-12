#include <bits/stdc++.h>
using namespace std;

// Depth First Search function
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;  // Mark the current node as visited
    ls.push_back(node);  // Add the current node to the DFS result list
    
    // Traverse all neighbors of the current node
    for (auto it : adj[node]) {
        if (!vis[it]) {  // If the neighbor is not visited
            dfs(it, adj, vis, ls);  // Recursively call dfs for the neighbor
        }
    }
}

// Function to perform DFS traversal of the graph
vector<int> dfsTraversal(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);  // Initialize a visited array of size V with all zeros
    vector<int> ls;         // List to store the DFS traversal result

    // Loop through all nodes to handle disconnected components
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {  // If the node is not visited
            dfs(i, adj, vis, ls);  // Perform DFS starting from the node
        }
    }

    return ls;  // Return the DFS traversal result
}

int main() {
    int n, m;
    cin >> n >> m;  // Input the number of nodes and edges
    vector<int> adj[n];  // Adjacency list representation of the graph

    // Input the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // Input an edge between nodes u and v
        adj[u].push_back(v);  // Add v to u's adjacency list
        adj[v].push_back(u);  // Add u to v's adjacency list (undirected graph)
    }

    // Get the DFS traversal result
    vector<int> dfs = dfsTraversal(n, adj);

    // Output the DFS traversal result
    for (auto it : dfs) {
        cout << it << " ";  // Print each node in the traversal
    }
    return 0;
}
