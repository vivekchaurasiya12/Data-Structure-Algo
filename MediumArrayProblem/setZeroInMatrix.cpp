#include <bits/stdc++.h>
using namespace std;

// Function to set the matrix such that if any element is 0, its entire row and column are set to 0

vector<vector<int>> setMatrix(vector<vector<int>> &matrix, int n, int m) {

    int col = 1; // Variable to track if the first column needs to be zeroed
    
    // First pass: Mark the first row and first column for rows and columns that need to be zeroed

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) { 
                matrix[i][0] = 0; // Mark the first element of the row
                
                if (j != 0) {
                    matrix[0][j] = 0; // Mark the first element of the column
                } else {
                    col = 0; // Special case for the first column
                }
            }
        }
    }
    
    // Second pass: Update the matrix using the marks in the first row and column

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) { 
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // Set the element to 0 if its row or column was marked
                }
            }
        }
    }
    
    // If the top-left element is 0, zero out the first row

    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    
    // If `col` is 0, zero out the first column

    if (col == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    
    return matrix;  
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

    // Call the function to modify the matrix

    vector<vector<int>> nemMatrix = setMatrix(matrix, n, m);

    // Output the modified matrix
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
