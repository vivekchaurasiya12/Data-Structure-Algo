#include <bits/stdc++.h>
using namespace std;

class StackImplementation {
    int topIndex; // Renamed from `top` to avoid conflict
    int arr[40];

public:
    StackImplementation() : topIndex(-1) {} // Initialize `topIndex` in the constructor

    void push(int x) {
        if (topIndex == 39) { // Check for stack overflow
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) { // Check for stack underflow
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1; // Return an invalid value
        }
        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) { // Check if stack is empty
            cout << "Stack is empty!" << endl;
            return -1; // Return an invalid value
        }
        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    StackImplementation st;

    st.push(4);
    st.push(3);
    st.push(2);

    cout << "Top element: " << st.top() << endl; // 2
    cout << "Size of stack: " << st.size() << endl; // 3

    cout << "Popped element: " << st.pop() << endl; // 2
    cout << "Top element after pop: " << st.top() << endl; // 3
    cout << "Size of stack after pop: " << st.size() << endl; // 2

    return 0;
}
