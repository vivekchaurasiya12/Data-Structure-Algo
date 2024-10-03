#include<bits/stdc++.h>
using namespace std;

// Function to find unique triplets that sum up to zero
vector<vector<int>> threeSum(vector<int> &arr) {
    vector<vector<int>> result;
    
    // Sort the array to apply two-pointer technique
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    
    // Loop to fix the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1, right = n - 1;  // Two pointers
        int target = -arr[i];  // We are looking for two numbers whose sum is equal to -arr[i]

        while (left < right) {
            int sum = arr[left] + arr[right];
            
            // If we found the triplet
            if (sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});
                
                // Move the left pointer to the right, skip duplicates
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                // Move the right pointer to the left, skip duplicates
                while (left < right && arr[right] == arr[right - 1])
                    right--;
                
                left++;
                right--;
            }
            // If the sum is less than the target, move the left pointer to the right
            else if (sum < target) {
                left++;
            }
            // If the sum is greater than the target, move the right pointer to the left
            else {
                right--;
            }
        }
    }
    
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

    // Call the function to find unique triplets that sum up to zero
    vector<vector<int>> result = threeSum(arr);
    
    // Output the result
    for (auto triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
