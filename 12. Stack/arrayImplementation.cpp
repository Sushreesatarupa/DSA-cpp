#include <iostream>
using namespace std;
#define size 10
class Stack
{
    int arr[size];
    int top = -1;
public:
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow !" << endl << "Exiting..." << endl;
            exit(1);
        }
        arr[++top] = data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow !" << endl << "Exiting..." << endl;
            exit(2);
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack empty !" << endl << "Exiting..." << endl;
            exit(3);
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    void display()
    {
        if (isEmpty())
            cout << "Stack empty !";
        else
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
        cout << endl;
    }
    
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.display();
    return 0;
}
