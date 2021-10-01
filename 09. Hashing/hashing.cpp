#include<iostream>
#include<conio.h>
#include<cstdlib>
#define max 10
using namespace std;
void insert();
void display();
int main()
{
	int ch;
	while(1)
	{
		cout<<"\n1.Insert Element\n2.Display\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
			default:
				cout<<"Wrong Choice :)";
		}
	}
}
struct node 
{
	int data;
	struct node *next;
};

struct node *head[max]={NULL},*c;

void insert()
{
	int i,key,ele;
	cout<<"\nEnter element\n";
	cin>>ele;
	i=ele%max;
	struct node *newnode=new node();
	newnode->data=ele;
	newnode->next = NULL;
	if(head[i]==NULL)
	head[i]=newnode;
	else
	{
		c=head[i];
		while(c->next!=NULL)
		{
			c=c->next;
		}
		c->next=newnode;
	}
}
void display()
{
	int i;
	for(i=0;i<max;i++)
{
	cout<<"\n";
	if(head[i]==NULL)
	{
		continue;
	}
	else
	{
		for(c=head[i];c!=NULL;c=c->next)
		{
			cout<<c->data<<"\t";
		}
	}
}

}