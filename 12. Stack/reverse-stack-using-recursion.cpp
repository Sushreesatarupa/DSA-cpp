// Question - we need to reverse the given stack using recursion
// Input = 60, 50, 40, 30, 20, 10
// Outout = 10, 20, 30, 40, 50, 60
// Time complexity - O(n^2)

#include<iostream>
#include<stack>

using namespace std;

// This function is used to insert the 
// element at the bottom of stack 
void insertAtBottom(stack<int>& st, int num) {
    // if stack is empty then we insert the 
    // num at the bottom of stack
    if(st.empty()) {
        st.push(num);
        return;
    }
    // All elements are held by the function call stack until stack is empty
    int top_ele = st.top();
    st.pop();
    insertAtBottom(st, num);
    // after inserting the num we will insert the all elements 
    // one by one which is held by function call stack 
    st.push(top_ele);
}

// this is function which revrse the stack using insertAtBottom 
void reverse(stack<int>& st) {
    // Holding all the element in function until stack is empty
    if(st.empty()) {
        return;
    }
    int num = st.top();
    st.pop();
    reverse(st);

    // Inserting all the element one by one 
    // which is held by reverse function
    insertAtBottom(st, num);
}

// Traversing the stack using while loop
void traverse(stack<int> st) {
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    stack<int> st;  // stack declaration using C++ STL
    // insertion in stack 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout<<"Stack before reversing: ";
    traverse(st);   // display the elements of stack 
    cout<<endl;

    // function used to reverse the stack
    reverse(st);

    cout<<"Stack after reversing : ";
    traverse(st);   // display the elements of stack 
    
    return 0;
}