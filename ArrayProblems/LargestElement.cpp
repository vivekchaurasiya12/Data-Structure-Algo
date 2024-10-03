#include<bits/stdc++.h>
using namespace std;

// Function to find the largest element in an array
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0]; // Initialize largest with the first element
    for(int i = 0; i < n; i++) { // Iterate through the array
        if(arr[i] > largest) { // Compare each element with largest
            largest = arr[i]; // Update largest if current element is greater
        }
    }
    return largest; // Return the largest element found
}

int main() {
    int n; // Variable to store the number of elements
    cin >> n; // Input the number of elements
    vector<int> arr(n); // Create a vector of size n to hold the elements

    for(int i = 0; i < n; i++) { // Loop to input elements
        cin >> arr[i]; // Input each element into the vector
    }

    // Call the function to find the largest element
    int largest = largestElement(arr, n);
    
    // Output the largest element
    cout << largest << endl;

    return 0; // End of the program
}
