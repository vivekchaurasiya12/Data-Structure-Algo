#include<bits/stdc++.h>
using namespace std;
//better aproach
/*
// Function to find the largest element in the array
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0]; // Initialize largest with the first element
    for(int i = 0; i < n; i++) { // Iterate through the array
        if(arr[i] > largest) { // Compare each element with largest
            largest = arr[i]; // Update largest if current element is greater
        }
    }
    return largest; // Return the largest element found
}

// Function to find the second largest element in the array
int secondLargestElement(vector<int> &arr, int n, int largest) {
    int secondLargest = -1; // Initialize second largest
    for(int i = 0; i < n; i++) { // Iterate through the array
        if(arr[i] > secondLargest && arr[i] != largest) { // Check for second largest
            secondLargest = arr[i]; // Update second largest if conditions are met
        }
    }
    return secondLargest; // Return the second largest element found
}
*/

//OPTIMAL APPROACH

int secondLargest(vector<int> &arr,int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest =arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main() {
    int n; // Variable to store the number of elements
    cin >> n; // Input the number of elements
    vector<int> arr(n); // Create a vector of size n to hold the elements
    for(int i = 0; i < n; i++) { // Loop to input elements
        cin >> arr[i]; // Input each element into the vector
    }

    int sLargest = secondLargest(arr,n);
     cout<<sLargest <<endl;
/*
    BETTER APPROACH

    int largest = largestElement(arr, n); // Find the largest element
    int secondLargest = secondLargestElement(arr, n, largest); // Find the second largest element
    cout << secondLargest << endl; // Output the second largest element
*/
    return 0; // End of the program
}
