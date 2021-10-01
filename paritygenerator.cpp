#include <iostream>

using namespace std;

int main()
{
    bool type;
    cout<<"Enter 0 for even parity check and 1 for odd parity check:";
    cin>>type;
    int s;
    cout<<"Enter message length:";
    cin>>s;
    cout<<"Enter Message:";
    int num;
    cin>>num;
    int input[s+1];
    int c=0;
    for(int i=s-1;i>=0;i--)
    {
        input[i]=num%10;
        num/=10;
        if(input[i])
            c++;
    }
    if((type && c%2==0)||(!type && c%2==1))
        input[s]=1;
    else
        input[s]=0;
    cout<<"Message to be transmitted:";
    for(int i=0;i<=s;i++)
        cout<<input[i];
    int msg;
    cout<<"\nEnter Recieved Message:";
    cin>>msg;
    int c1=0;
    for(int i=s;i>=0;i--)
    {
        int tem=msg%10;
        msg/=10;
        if(tem)
            c1++;
    }
    if(!(type ^ c1%2==1))
        cout<<"Received Message is Correct";
    else
        cout<<"Received Message is Incorrect";
    return 0;
}
