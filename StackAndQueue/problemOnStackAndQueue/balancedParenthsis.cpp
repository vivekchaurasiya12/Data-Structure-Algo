#include<bits/stdc++.h>
using namespace std;

// Function to check if the string of brackets is valid
bool isValid(string s) {
    stack<char> st;  // Declare a stack to store opening brackets
    
    // Iterate through each character in the string
    for(auto it: s) {
        // If the character is an opening bracket, push it onto the stack
        if(it == '(' || it == '{' || it == '[') {
            st.push(it);
        }
        else {
            // If the character is a closing bracket, check if there is a matching opening bracket
            if(st.size() == 0) return false;  // If stack is empty, there is no matching opening bracket
            
            char ch = st.top();  // Get the top element of the stack (the most recent opening bracket)
            st.pop();  // Remove the top element from the stack
            
            // Check if the closing bracket matches the top element of the stack
            // If not, return false
            if((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{')) {
                continue;  // If the brackets match, continue to the next character
            }
            else {
                return false;  // If the brackets don't match, return false
            }
        }
    }
    // If the stack is empty, it means all the opening brackets have been properly closed
    return st.empty();  // If stack is empty, the string is valid, else it's invalid
}

int main()
{
    string s = "()[{}()]";  // Example string with different types of brackets
    if(isValid(s))  // Call the isValid function to check if the string is valid
        cout << "True" << endl;  // If valid, print True
    else
        cout << "False" << endl;  // If invalid, print False
}
