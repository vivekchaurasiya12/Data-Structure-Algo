#include <bits/stdc++.h>
using namespace std;

// DFS function to traverse all nodes in a connected component
void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
    vis[node] = 1; // Mark the node as visited
    
    // Visit all adjacent nodes
    for (auto it : adjLs[node]) {
        if (!vis[it]) { // If the adjacent node is not visited
            dfs(it, adjLs, vis);
        }
    }
}

// Function to find the number of provinces (connected components)
int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size(); // Number of nodes in the graph
    
    // Step 1: Convert adjacency matrix to adjacency list
    vector<int> adjLs[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // If there's a connection (excluding self-loops)
            if (isConnected[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
            }
        }
    }
    
    // Step 2: Initialize visited array to track visited nodes
    vector<int> vis(V, 0);
    int count = 0; // Counter for connected components
    
    // Step 3: Traverse all nodes
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If the node is not yet visited
            count++; // Increment the connected component count
            dfs(i, adjLs, vis); // Perform DFS for the component
        }
    }
    
    return count; // Return the total number of connected components
}

int main() {
    // Input: Adjacency matrix
    vector<vector<int>> isConnected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Output: Number of provinces
    cout << "Number of Provinces: " << findCircleNum(isConnected) << endl;
    return 0;
}
