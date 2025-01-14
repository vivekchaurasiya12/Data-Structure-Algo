#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();    // Number of rows
    int m = grid[0].size(); // Number of columns

    // Visited array to track visited cells
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int countFresh = 0; // Count of fresh oranges
    queue<pair<pair<int, int>, int>> q; // Queue to store {{row, col}, time}

    // Initialize the queue with all rotten oranges and mark them as visited
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0}); // Push rotten oranges with time = 0
                vis[i][j] = 1;       // Mark as visited
            } else if (grid[i][j] == 1) {
                countFresh++;        // Count fresh oranges
            }
        }
    }

    int timeElapsed = 0; // Track the total time taken
    int dRow[] = {-1, 0, 1, 0}; // Directional row changes (up, right, down, left)
    int dCol[] = {0, 1, 0, -1}; // Directional column changes (up, right, down, left)
    int countRotten = 0; // Count of fresh oranges turned rotten

    // Perform BFS to rot adjacent fresh oranges
    while (!q.empty()) {
        int row = q.front().first.first; // Current row
        int col = q.front().first.second; // Current column
        int time = q.front().second; // Current time
        q.pop();

        // Update the maximum time taken
        timeElapsed = max(timeElapsed, time);

        // Check all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Check if the neighboring cell is within bounds, is a fresh orange, and is not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                
                q.push({{newRow, newCol}, time + 1}); // Add to queue with incremented time
                vis[newRow][newCol] = 1; // Mark as visited
                countRotten++; // Increment the count of rotten oranges
            }
        }
    }

    // If all fresh oranges are rotten, return the time taken; otherwise, return -1
    return (countRotten == countFresh) ? timeElapsed : -1;
}

// Example usage
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);
    if (result != -1) {
        cout << "All oranges are rotten in " << result << " minutes." << endl;
    } else {
        cout << "Not all oranges can be rotten." << endl;
    }

    return 0;
}
