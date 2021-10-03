#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int v;
    node *next;
    node()
    {
        next= NULL;
    }
}*first, *save, *ptr, *newptr, *rear;
int m = 0;
node* createnode(int j)
{
    newptr = new node;
    newptr->v = j;
    newptr->next = NULL;
    return newptr;
}
void lib(node *p) //insert at beginning
{
    if(first == NULL)
    {
        first = p;
        rear = p;
    }   
    else
    {
        save = first;
        first = p;
        p->next = save;
    } 

    //cout<<rear->v<<" ";  
    m++;
}

void lie(node *p) //insert at end
{
     
    rear->next = p;
    rear = p;
    
    m++;
    //cout<<rear->v<<" ";
}

void lim(node *p, int pos) //insert in mid
{
    ptr = first;
    //cout<<ptr->v<<" ";
    int i = 1;
    while(i < pos-1)
    {
        i++;
        ptr = ptr->next;
    }
    
    save = ptr->next;
    ptr->next = p;
    p->next = save;
    
    m++;
}
void del(int x)
{
    ptr = first;
    int flag = 1;
    while(flag)
    {
        if(x == first->v)
            {
                save = ptr;
                first = first->next;
                delete(save);  
                m--;
                flag = 0;
            }
        else    
        if((ptr->next)->v == x)
        {

            save = ptr->next;
            if((ptr->next)->next == NULL)
                rear = ptr;
            ptr->next = (ptr->next)->next;
                
            delete(save);
            flag = 0;
            m--;
        
        }    
        else ptr = ptr->next;   
        if(ptr->next == NULL)
           break; 
    }
    if(flag)
      cout<<"Number doesn't exist\n";
}

void display()
{
    ptr = first;
    int flag = 1;
    while(flag)
    {
        cout<<ptr->v<<" ";
        if(ptr->next == NULL)
           break;
        ptr = ptr->next;
        
    }   
    cout<<endl; 

}

int main()
{
    //first = rear = NULL;
    char ch = 'y';
    while(tolower(ch) == 'y')
    {
        int n;
        cout<<"3 CHOICES:\n";
        cout<<"1. insert  2. delete 3. display\n";
        cout<<"Enter your choice- ";
        cin>>n;
        switch(n)
        {
            case 1: {cout<<"No of list elements- "<<m<<endl;
                    cout<<"Enter position of insertion : ";
                    int pos;
                    cin>>pos;
                    if(pos>m+1 || pos<1)
                       cout<<"Position doesn't exist\n";
                    else 
                    {
                        cout<<"Enter number to be inserted- ";
                        int j; cin>>j;
                        node *pp = createnode(j);
                        if(pos == 1)
                            lib(pp);
                       
                        else if(pos == m+1)
                            lie(pp);
                        else
                            lim(pp, pos);
                        

                    }}
                    break;

           
            case 2: {cout<<"Elements present: \n";
                    display();
                    cout<<"Enter number to be deleted: ";
                    int j; cin>>j;
                    del(j);}
                    break;

            case 3: display();                      
        }      
        cout<<"Do you want to continue? (n/y): ";
        cin>>ch;

    }
    return 0;
}