#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; // Choosing the pivot as the first element
    int i = low;
    int j = high;
    
    while (i < j) {
        // Increment i until we find an element larger than pivot
        while (arr[i] <= pivot && i <= high-1) {
            i++;
        }
        // Decrement j until we find an element smaller than or equal to pivot
        while (arr[j] > pivot && j >= low+1) {
            j--;
        }
        // If i and j have not crossed, swap arr[i] and arr[j]
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot with arr[j] (which is the correct position of the pivot)
    swap(arr[low], arr[j]);
    return j; // Return the pivot index
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);  // Sort elements before pivot
        quickSort(arr, pIndex + 1, high); // Sort elements after pivot
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
