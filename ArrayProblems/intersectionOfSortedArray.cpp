#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans;
    int i = 0, j = 0;

    // Traverse both arrays using two pointers
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++; // Move pointer in arr1
        } else if (arr1[i] > arr2[j]) {
            j++; // Move pointer in arr2
        } else {
          ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int n1, n2;

    // Input for the first array
    cout<< "Enter size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of the first array (sorted): ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for the second array
    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of the second array (sorted): ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Get the intersection of both arrays
    vector<int> newArray = intersectionOfArray(arr1, arr2);

    // Output the result
    cout << "Intersection of the two arrays: ";
    for (auto it : newArray) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
