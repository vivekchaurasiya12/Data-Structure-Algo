#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal for both connected and disconnected graphs
vector<int> bfsTraversal(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);  // Visited array to track visited nodes
    vector<int> bfs;        // Result vector to store BFS traversal
    queue<int> q;
    
    // Loop to handle disconnected components
    for (int i = 0; i < n; i++) { 
        if (!vis[i]) {  // If node `i` is unvisited, start a BFS
            vis[i] = 1;
            q.push(i);
            
            while (!q.empty()) { // Standard BFS loop
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                // Explore all neighbors of the current node
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1; // Mark neighbor as visited
                        q.push(it); // Add to queue for further processing
                    }
                }
            }
        }
    }
    return bfs;
}

int main() {
    int n, m;
    cin >> n >> m; // Input number of nodes and edges
    vector<int> adj[n]; // Adjacency list representation
    
    // Input edges for the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Add edge from u to v
        adj[v].push_back(u);  // Add edge from v to u (undirected graph)
    }
    
    // Perform BFS traversal
    vector<int> bfs = bfsTraversal(n, adj);
    
    // Print the BFS traversal
    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    return 0;
}
