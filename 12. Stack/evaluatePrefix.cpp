//This code works for single digit values only. Ex : '+ 2 6'
#include <iostream>
#include <stack>
using namespace std;
int performOperation(char operation, int operand1, int operand2)
{
    if (operation == '+')
        return operand1 + operand2;
    else if (operation == '-')
        return operand1 - operand2;
    else if (operation == '*')
        return operand1 * operand2;
    else if (operation == '/')
        return operand1 / operand2;
    else
        exit(1);
}
bool isValidOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? true : false;
}
bool isValidNumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}
int evaluatePrefix(string expression)
{
    stack<int> s;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;
        else if (isValidOperator(expression[i]))
        {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();
            s.push(performOperation(expression[i], operand1, operand2));
        }
        else if (isValidNumber(expression[i]))
            s.push(expression[i] - '0');
    }
    return s.top();
}
int main()
{
    string expression;
    getline(cin, expression);
    cout << evaluatePrefix(expression);
    return 0;
}
