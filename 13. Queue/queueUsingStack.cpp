#include <iostream>
using namespace std;

class stack{
private:
    int size, i = -1, temp, t;
    int arry[50];
    int *top = arry;

public:
    void push(int num){
        //cout << "| " << i << " |";
        if (i > 48){
            cout << "Stack Overflow";
        }
        else{
            *top = num;
            top++;
            i++;
            temp = i;
        }
    }
    char pop(){
        //i = temp;
        if(i <= -1){
            //cout << "Stack Underflow";
            return -1;
        }
        else{
            t = arry[i];
            top--;
            i--;
            return t;
        }
    }
    void display(){
        temp = i;
        //cout << "| " << i << " |";
        while (temp != -1){
            cout << arry[temp] << " ";
            temp--;
        }
    }
    stack copy(stack s) {
        stack st;
        temp = i;
        while (temp != -1){
            st.push(s.pop());
            //cout << "|-" << arry[temp] << " -| ";
            temp--;
        }
        return st;
    }
};

class queue{
public:
    stack s1,s2;
    void enqueue(int num){
        s1.push(num);
    }
    void dequeue(){
        int x = 0;
        //s2 = s1.copy(s1);
        while(x != -1){
            x = s1.pop();
            if(x != -1)
                s2.push(x);
        }
        s2.pop();
        //cout << "Deleted element: " << s2.pop();
        //while(s1.pop() != -1){}
        x = 0;
        while( x != -1){
            x = s2.pop();
            if(x != -1)
                s1.push(x);
        }
        //s1 = s2.copy(s2);
    }
    void display(){

        cout << "\n|-";
        s1.display();
        cout << "-|";

        cout << "\n<-";
        s2.display();
        cout << "->";
    }
};

int main(){
    int n;
    char c;
    queue q1;

    while(1){
        cout << "\nEnter 1 for enqueue and 2 for dequeue : ";
        cin >> c;

        switch (c){
        case '1':
            cout << "\nEnter the Num: ";
            cin >> n;
            q1.enqueue(n);
            q1.display();
            break;
        case '2':
            q1.dequeue();
            q1.display();
            break;
        default:
            cout << "You Entere a wrong Choice, Try Again:";
            break;
        }

    }
}