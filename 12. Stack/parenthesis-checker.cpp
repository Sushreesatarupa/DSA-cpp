#include <iostream>
#include <stack>
using namespace std;
bool checkValidPair(char opening, char closing)
{
    if ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']'))
        return true;
    return false;
}
bool checkParenthesesBalanced(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            s.push(expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
            if (s.empty() || !checkValidPair(s.top(), expression[i]))
                return false;
            else
                s.pop();
    return s.empty() ? true : false;
}
int main()
{
    string expression;
    cin >> expression;
    if (checkParenthesesBalanced(expression))
        cout << "Balanced";
    else
        cout << "Not balanced";
    return 0;
}
