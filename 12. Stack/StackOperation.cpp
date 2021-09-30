#include <iostream>
using namespace std;
class Stackoverflow : public exception
{
};
class Stackunderflow : public exception
{
};

class Stack
{
    int size;
    int top = -1;
    int *stk;

public:
    Stack(int sz)
    {
        size = sz;
        stk = new int[size];
    }
    void push(int x)
    {
        if (top == size - 1)
        {
            throw Stackoverflow();
        }
        top++;
        stk[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            throw Stackunderflow();
        }
        return stk[top--];
    }
};
int main(int argc, char const *argv[])
{
    try
    {
        Stack s1(5);
        s1.push(44);
        s1.pop();
        s1.pop();
    }
    catch (Stackunderflow e)
    {
        cout << "stack underflow";
    }
    catch (Stackoverflow e)
    {
        cout << "stack overflow";
    }

    return 0;
}
