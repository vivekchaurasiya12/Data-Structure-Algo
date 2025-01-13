#include <bits/stdc++.h>
using namespace std;

// Depth-First Search (DFS) helper function for the flood fill algorithm
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int delRow[], int delCol[], int inicolor) {
    // Update the current cell in the answer grid with the new color
    ans[row][col] = color;

    // Get the dimensions of the image
    int n = image.size();      // Number of rows
    int m = image[0].size();   // Number of columns

    // Explore the 4 possible directions (up, right, down, left)
    for (int i = 0; i < 4; i++) {
        int newrow = row + delRow[i]; // Calculate new row index
        int newcol = col + delCol[i]; // Calculate new column index

        // Check if the new position is within bounds, has the initial color,
        // and hasn't been filled with the new color yet
        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
            image[newrow][newcol] == inicolor && ans[newrow][newcol] != color) {
            // Perform DFS on the neighboring cell
            dfs(newrow, newcol, ans, image, color, delRow, delCol, inicolor);
        }
    }
}

// Main function for the flood fill algorithm
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    // Get the initial color of the starting pixel
    int inicolor = image[sr][sc];

    // Create a copy of the original image to store the result
    vector<vector<int>> ans = image;

    // Define arrays to represent the 4 possible directions
    int delRow[] = {-1, 0, 1, 0}; // Row movement: up, right, down, left
    int delCol[] = {0, 1, 0, -1}; // Column movement: up, right, down, left

    // Start the DFS from the given starting pixel
    dfs(sr, sc, ans, image, color, delRow, delCol, inicolor);

    // Return the updated image
    return ans;
}

// Example usage
int main() {
    // Input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;     // Starting row
    int sc = 1;     // Starting column
    int newColor = 2; // New color to fill

    // Call the floodFill function
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Print the resulting image
    for (const auto &row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
