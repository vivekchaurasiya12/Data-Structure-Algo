#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n, int m) {
   for(int i=0;i<=n-2;i++){
    for(int j=i+1;j<=m-1;j++){
       swap( matrix[i][j] , matrix[j][i]);
    }
   }
   for(int i=0;i<n;i++){
     reverse(matrix[i].begin(), matrix[i].end());
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

    vector<vector<int>> newMatrix = rotateMatrix(matrix, n, m);

    // Output the modified matrix
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
