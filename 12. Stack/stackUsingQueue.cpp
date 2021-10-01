#include<iostream>
using namespace std;

class queue{
private:
    int arry[50], front = -1, rear = -1, temp, returnNum;
    int *F = arry;
    int *R = arry;
public:
    void enQueue(int num){
        if(rear > 48){
            cout << "\nQueue OverFlow\n";
        }
        else{
            if(front == -1 && rear == -1){
                *R = num;
                R++;
                front++;
                rear++;
            }
            else{
                *R = num;
                R++;
                rear++;
            }
        }
    }
    int deQueue(){
        if( (front > rear) || front < 0){
            //cout << "\nQueue UnderFlow\n";
            front = -1;
            rear = -1;
            F = arry;
            R = arry;
            return -1;
        }
        else{
            returnNum = *F;
            F++;
            front++;
            return returnNum;
        }
        return -1;
    }
    void display(){
        if(front > rear){
            cout << "\nThe Queue is Empty.\n";
        }
        else{
            //cout <<"\n" << front << " | " << rear;
            cout << "\nThe Queue is as Follows: ";
            for(int i = rear; i >= front; i--){
                cout << arry[i] << " ";
            }
        }
    }
};

class stack{
public:
    queue q1, q2;
    int selected = 1;


    void push(int num){
        int x = 0;
        if(selected == 1){
            q1.enQueue(num);
            while (x != -1){
                x = q2.deQueue();
                if(x != -1)
                    q1.enQueue(x);
            }
            x = 0;
            selected = 2;
        }
        else{
            q2.enQueue(num);
            while (x != -1){
                x = q1.deQueue();
                if(x != -1)
                    q2.enQueue(x);
            }
            x = 0;
            selected = 1;
        }

    }
    int pop(){
        if(selected == 1){
            cout << "\nThe Deleted element is : " << q2.deQueue();
        }
        else{
            cout << "\nThe Deleted element is : " << q1.deQueue();
        }
    }
    int display(){
        if(selected == 1){
            q2.display();
        }
        else{
            q1.display();
        }
    }

};

int main(){
    int n;
    char c;
    stack s1;

    while(1){
        cout << "\nEnter 1 for push and 2 for pop : ";
        cin >> c;

        switch (c){
        case '1':
            cout << "\nEnter the Num: ";
            cin >> n;
            s1.push(n);
            s1.display();
            break;
        case '2':
            s1.pop();
            s1.display();
            break;
        default:
            cout << "You Entere a wrong Choice, Try Again:";
            break;
        }

    }
}