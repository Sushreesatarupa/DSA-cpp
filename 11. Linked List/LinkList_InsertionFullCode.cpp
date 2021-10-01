#include <stdio.h>
#include <stdlib.h>

//Structure for node
struct node
{
    int data;
    struct node *next;
};


//Traversal code for Link List
void linkListTraversal(struct node *ptr)
{
    printf("------------------------------\n");
    while (ptr != NULL)
    {
        printf("Element %d", ptr->data);
        ptr = ptr->next;
        printf("\n");
    }
}

//code for insertion at beginning
struct node *insertatbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


//code for insertion at given index
struct node *insertatIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next; // 34 4 5
    p->next = ptr;
    return head;
}

//code for insertion at end
struct node * insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
 
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}


//Main code
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    int ch;

   
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = NULL;

    linkListTraversal(head);
label:
    //printf("\nUpdate Link list is:\n");
    //linkListTraversal(head);

    printf("          \n-------------> Link List By Vishal Aggarwal   <-------------\n\nEnter corresponding number for your Choices:\n\nEnter 1 for insertion at beginning\n\nEnter 2 for insertion at Index\n\nEnter 3 for enter at end\n\nEnter 4 for enter after given node\n\nEnter 5 to display\n\n0 for Exit\n\n");
    printf("\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
        break;
    case 1:
    {
        int data;
        printf("Enter data to insert in beginning: ");
        scanf("%d", &data);
        head = insertatbeg(head, data);
        printf("\n\n---------Updated Link List is---------\n\n");
        linkListTraversal(head);
        goto label;
    }

    case 2:
    {
        int data,ind;
        printf("Enter data to insert ");
        scanf("%d", &data);
        printf("Enter index ");
        scanf("%d",&ind);
        head = insertatIndex(head, data,ind);
        printf("\n\n---------Updated Link List is---------\n\n");
        linkListTraversal(head);
        goto label;
    }

     case 3:
    {
        int data;
        printf("Enter data to insert at end ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);
        printf("\n\n---------Updated Link List is---------\n\n");
        linkListTraversal(head);
        goto label;
    }

    case 5:
    {
        linkListTraversal(head);
        goto label;
    }
    }

    linkListTraversal(head);
}
