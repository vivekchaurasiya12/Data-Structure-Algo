#include<bits/stdc++.h>
using namespace std;

// Function to find the majority element that appears more than ⌊n/3⌋ times
vector<int> majorityElement(vector<int> &arr, int n) {
    
    
    
    // Initializing variables to store potential majority elements and their counts
   
    int count1 = 0, count2 = 0;      // Counters for the two potential majority elements
    int elem1 = INT_MIN, elem2 = INT_MIN;  // The two potential majority elements (initialized to a minimum integer)

    
    
    
    // First pass: Identify two potential candidates using the Boyer-Moore Voting Algorithm
   
    for (int i = 0; i < n; i++) {
        if (count1 == 0 && elem2 != arr[i]) {  // If count1 is 0 and the current element is not equal to elem2
            count1 = 1;                        // Set count1 to 1
            elem1 = arr[i];                    // Assign current element as elem1
        } 
       
       
        else if (count2 == 0 && elem1 != arr[i]) { // If count2 is 0 and the current element is not equal to elem1
            count2 = 1;                          // Set count2 to 1
            elem2 = arr[i];                      // Assign current element as elem2
        } 
        else if (arr[i] == elem1) {  // If the current element equals elem1, increment count1
            count1++;
        } 
        else if (arr[i] == elem2) {  // If the current element equals elem2, increment count2
            count2++;
        } 
        else {
            // If the current element is neither elem1 nor elem2, decrement both counts
            count1--;
            count2--;
        }
    }

    // Second pass: Count the occurrences of the two potential candidates (elem1 and elem2)
    count1 = 0, count2 = 0; // Reset counts
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem1) {
            count1++;  // Count occurrences of elem1
        }
        if (arr[i] == elem2) {
            count2++;  // Count occurrences of elem2
        }
    }

    vector<int> result;
    int min = (n / 3) + 1; // The minimum number of occurrences to be considered a majority element (⌊n/3⌋ + 1)

    // Check if the counts of elem1 and elem2 exceed the threshold and add them to the result
    if (count1 >= min) {
        result.push_back(elem1);
    }
    if (count2 >= min ) {  // Ensure that elem2 is not the same as elem1
        result.push_back(elem2);
    }

    // Sort the result for proper order before returning
    sort(result.begin(), result.end());

    return result;
}

int main() {
    int n;

    // Input the number of elements in the array
    cin >> n;
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and output the majority element(s)
    vector<int> num = majorityElement(arr, n);
    
    // Output the result
    for (auto it : num) {
        cout << it << " ";
    }

    return 0;
}
