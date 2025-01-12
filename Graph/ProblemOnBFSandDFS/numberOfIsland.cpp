#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
    int n = grid.size(); // Number of rows in the grid
    int m = grid[0].size(); // Number of columns in the grid
    queue<pair<int, int>> q; // Queue for BFS
    q.push({row, col}); // Push the starting cell into the queue
    vis[row][col] = 1; // Mark the starting cell as visited

    // BFS traversal
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traverse all 8 possible directions
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow; // Calculate new row
                int ncol = col + delcol; // Calculate new column
                
                // Check if the new cell is valid
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1; // Mark the cell as visited
                    q.push({nrow, ncol}); // Push the cell into the queue
                }
            }
        }
    }
}

// Function to find the number of islands
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(); // Number of rows in the grid
    int m = grid[0].size(); // Number of columns in the grid
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
    int count = 0; // Initialize the island count

    // Traverse every cell in the grid
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If the cell is unvisited and is part of an island ('1')
            if (!vis[row][col] && grid[row][col] == '1') {
                count++; // Increment the island count
                bfs(row, col, vis, grid); // Perform BFS to mark the entire island
            }
        }
    }

    return count; // Return the total number of islands
}


// Example usage
int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '0', '1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
