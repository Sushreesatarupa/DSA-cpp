/*
    This algorithm will take a mathmatical expression in the infix form and output
    the postfix form.

    Infix form is the human readable PEMDAS.
    Postfix is a more computer friendly format for computers.
    We will account for { +, −, ∗, /, ^ } 

*/

#include <iostream>
#include <locale>
#include <stack>

using namespace std;

// we order the operators by priority with 3 being the highest.
int precedence(char c) {
    if (c == '^') {
        return 3;              
    }
    if (c == '*' || c == '/') {
        return 2;            
    }
    if (c == '+' || c == '-') {
        return 1;           
    }
        return 0;
}

string InfixToPostfix(string infix_form) {
    stack<char> stack;
    stack.push('$'); // We add a buffer character to avoid underflow
    string::iterator itr;
    string post_fix_form = "";

    for (itr = infix_form.begin(); itr != infix_form.end(); itr++) {
        if (isalnum(char(*itr)))
            post_fix_form += *itr; // add to post_fix_form when char is lettr or num
        else if (*itr == '(')
            stack.push('(');
        else if (*itr == '^')
            stack.push('^');
        else if (*itr == ')') {
            while (stack.top() != '$' && stack.top() != '(') {
                post_fix_form += stack.top(); // store and pop until '(' has been found
                stack.pop();
            }
            stack.pop();          // '('  removed from the stack
        }
        else {
            if (precedence(*itr) > precedence(stack.top()))
                stack.push(*itr); // push if precedence is high
            else {
                while (stack.top() != '$' && precedence(*itr) <= precedence(stack.top())) {
                    post_fix_form += stack.top();        // store and pop until higher precedence is found
                    stack.pop();
                }
                stack.push(*itr);
            }
        }
    }

    return post_fix_form;
}

// test and output to console.
int main() {
    string infix = "x^y/(5*z)+2";
    cout << "Postfix Form Is: " << InfixToPostfix(infix) << endl;
}