#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<long long> st; // Stack to store elements, potentially encoded to track minimum
    long long mini;      // Variable to store the minimum element in the stack

public:
    /** Initialize your data structure here. */
    MinStack() {
        // Clear the stack and initialize the minimum to maximum possible value
        while (!st.empty()) st.pop();
        mini = INT_MAX;
    }

    /** Push an element onto the stack. */
    void push(int value) {
        long long val = value; // Convert to long long to handle encoding and avoid overflow
        
        if (st.empty()) {
            // If stack is empty, directly push the value and set it as the minimum
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // If the new value is less than the current minimum:
                // Encode the new value and push it onto the stack
                st.push(2 * val * 1LL - mini);
                mini = val; // Update the minimum value
            } else {
                // Otherwise, push the value as it is
                st.push(val);
            }
        }
    }

    /** Remove the element on top of the stack. */
    void pop() {
        if (st.empty()) return; // If stack is empty, do nothing

        long long el = st.top(); // Get the top element
        st.pop(); // Remove the top element

        if (el < mini) {
            // If the popped element is encoded, recover the previous minimum
            mini = 2 * mini - el;
        }
    }

    /** Get the top element of the stack. */
    int top() {
        if (st.empty()) return -1; // Return -1 if stack is empty

        long long el = st.top();
        if (el < mini) {
            // If the top element is encoded, return the current minimum
            return mini;
        }
        return el; // Otherwise, return the element as is
    }

    /** Retrieve the minimum element in the stack. */
    int getMin() {
        return mini; // Return the current minimum
    }
};
int main() {
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(5);
    minStack.push(3);
    minStack.push(7);

    // Retrieve and display the minimum element
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 3

    // Get the top element
    cout << "Top: " << minStack.top() << endl; // Output: 7

    // Pop the top element
    minStack.pop();

    // Retrieve and display the minimum element after popping
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 3

    // Push a smaller element
    minStack.push(2);

    // Retrieve and display the minimum element
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 2
    
    return 0;
}