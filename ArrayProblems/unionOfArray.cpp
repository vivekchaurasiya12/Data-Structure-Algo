#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfArray(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    // Traverse both arrays and merge them
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else {
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Add remaining elements from arr2
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    // Add remaining elements from arr1
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    return unionArr;
}

int main() {
    int n1, n2;
    
    // Input for first array
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of the first array (sorted): ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for second array
    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of the second array (sorted): ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Get the union of both arrays
    vector<int> newArray = unionOfArray(arr1, arr2);

    // Output the result
    cout << "Union of the two arrays: ";
    for (auto it : newArray) {
        cout << it << " ";
    }
   

    return 0;
}
