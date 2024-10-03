#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> &matrix) {
    int n = matrix.size();      // Number of rows
    int m = matrix[0].size();   // Number of columns
    vector<int> result;

    int left = 0, right = m - 1;  // Column boundaries
    int top = 0, bottom = n - 1;  // Row boundaries

    // Traverse in a spiral order
    while (left <= right && top <= bottom) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary left

        // Traverse from right to left across the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        // Traverse from bottom to top along the left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    return result;
}

int main() {
    int n, m;

    // Input the number of rows and columns in the matrix
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    // Input the elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Call the function to traverse the matrix in a spiral order
    vector<int> spiralOrder = spiralTraverse(matrix);

    // Output the result
    for (int num : spiralOrder) {
        cout << num << " ";
    }

    return 0;
}
