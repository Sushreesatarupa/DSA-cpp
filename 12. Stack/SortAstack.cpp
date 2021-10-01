
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s */


void SortedStack :: sort()
{
    priority_queue<int,vector<int>,greater<int>> q;  //max priority queue to store the elements of the stack from top to bottom one by one(decreasing order)
  while(!s.empty())
  {
      q.push(s.top());
      s.pop();
  }
  
  while(!q.empty())
  {
      s.push(q.top());   //pushing back the elements from the queue in the stack (now increasing order sorted)
      q.pop();
  }
}
