#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    // Loop over all the integers from 0 to (2^n) - 1
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        
        // Check each bit of the current number (i)
        for (int j = 0; j < n; j++) {
            // If the j-th bit of i is set, include nums[j] in the subset
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        
        result.push_back(subset);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    // Get the power set
    vector<vector<int>> subsets = powerSet(nums);
    
    // Print the power set
    cout << "Power Set:" << endl;
    for (auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
