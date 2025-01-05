#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    // Create an adjacency matrix
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0)); // 1-based indexing

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Add edge (u -> v)
        adjMatrix[u][v] = 1;

        // comment the following line for an undirected graph
         adjMatrix[v][u] = 1;
    }

    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
