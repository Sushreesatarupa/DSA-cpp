// Doubly Linked List All Functions in C - Sharoni Bose

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
    	struct node *prev;
    	struct node *next;
} *head, *last;
void createList()
{
	int n;
	printf("\nEnter Number of Nodes: ");
	scanf("%d", &n);
	struct node *ptr, *temp;
    	int i = 0, data;
    	head = (struct node *)malloc(sizeof(struct node));
    	if(head == NULL)
    	{
        	printf("\nMemory Not Allocated\n");
        	exit(0);
    	}
    	printf("\nEnter Data of Node %d: ", i + 1);
    	scanf("%d", &data);
    	head->data = data;
    	head->prev = NULL;
    	head->next = NULL;
    	temp = head;
    	for(i = 1; i < n; i++)  
    	{
        	ptr = (struct node *)malloc(sizeof(struct node));
        	if(ptr == NULL)
        	{
            		printf("\nMemory Not Allocated\n");
            		break;
        	}
        	printf("Enter Data of Node %d: ", i + 1);
        	scanf("%d", &data);
        	ptr->data = data;
        	ptr->next = NULL;
        	temp->next = ptr;
        	ptr->prev = temp;
        	temp = temp->next;
    	}
}
void traverseList()
{
	struct node *ptr;
    	if(head == NULL)
    	{
        	printf("\nList Is Empty\n");
        	return;
    	}
    	ptr = head; 
    	printf("\nList: ");
    	while(ptr != NULL)
    	{
        	printf("%d ", ptr->data);
        	ptr = ptr->next;
    	}
    	printf("\n");
}
void traverseListBackward()
{
	struct node *ptr;
 	ptr = last;
 	printf("\nList In Reverse Order: ");
 	while(ptr != NULL)
 	{
 		printf("%d ", ptr->data);
 		ptr = ptr->prev;
 	}
 	printf("\n");
}
void checkList()
{
	if(head == NULL)
		printf("\nList Is Empty\n");
	else
		printf("\nList Isn't Empty\n");
}
void insertAtBeginning()
{
	struct node *ptr;
    	int element;
    	printf("\nEnter Element To Add: ");
    	scanf("%d", &element);
    	ptr = (struct node *)malloc(sizeof(struct node));
    	ptr->data = element;
    	ptr->prev = NULL;
    	if(head == NULL)
    	{
    		ptr->next = NULL;
       		head = ptr;
    	}
    	else
    	{
      	 	ptr->next = head;
       		head = ptr;
    	}
}
void insertAtEnd()
{
	struct node *ptr;
	int element;
	printf("\nEnter Element To Add: ");
	scanf("%d", &element);
   	ptr = (struct node *)malloc(sizeof(struct node));
   	ptr->data = element;
   	ptr->next = NULL;
   	if(head == NULL)
   	{
      		ptr->prev = NULL;
      		head = ptr;
   	}
   	else
   	{
      		struct node *temp = head;
      		while(temp->next != NULL)
         	temp = temp->next;
      		temp->next = ptr;
      		ptr->prev = temp;
   	}
}
void insertAtPosition()
{
	struct node *ptr;
	int element, position;
	printf("\nEnter Element To Add: ");
	scanf("%d", &element);
	printf("Enter Position: ");
	scanf("%d", &position);
   	ptr = (struct node *)malloc(sizeof(struct node));
   	ptr->data = element;
   	if(head == NULL)
   	{
      		ptr->prev = ptr->next = NULL;
      		head = ptr;
   	}
   	else
   	{
      		struct node *temp1 = head, *temp2;
      		while(temp1->data != position)
      		{
         		if(temp1->next == NULL)
         		{
            			printf("\nElement Not Found\n");
				break;
         		}
         		else
            			temp1 = temp1->next;
         	}
      		temp2 = temp1->next;
      		temp1->next = ptr;
      		ptr->prev = temp1;
      		ptr->next = temp2;
      		temp2->prev = ptr;
	}
}
void deleteFromBeginning()
{
	if(head == NULL)
		printf("\nList Is Empty\n");
   	else
   	{
      		struct node *temp = head;
      		if(temp->prev == temp->next)
      		{
         		head = NULL;
         		free(temp);
      		}
      		else
      		{
         		head = temp->next;
         		head->prev = NULL;
         		free(temp);
      		}
   	}
}
void deleteFromEnd()
{
	if(head == NULL)
		printf("\nList Is Empty\n");
   	else
   	{
      		struct node *temp = head;
      		if(temp->prev == temp->next)
      		{
         		head = NULL;
         		free(temp);
      		}
      		else
      		{
         		while(temp->next != NULL)
            		temp = temp->next;
         		temp->prev->next = NULL;
         		free(temp);
      		}
   	}
}
void deleteFromPosition()
{
	int element, position;
 	if(checkList)
 	{
 		if(position == 1)
 		{
 			element = head->data;
 			printf("\nElement Deleted: %d\n", element);
 			head = head->next;
 			free(head->prev);
 			head->prev = NULL;
 		}
 		else if(position > 1)
 		{
 			struct node *temp = head;
 			int i;
 			for(i = 0; i < position - 1; i++)
 			temp = temp->next;
 			element = temp->data;
 			printf("\nElement Deleted: %d\n", element);
 			temp->next->prev = temp->prev;
 			temp->prev->next = temp->next;
 			free(temp);
 		}
 		else
 		{
 			printf("\nInvalid Position\n");
 			return;
 		}
 	}
 	else
 	{
 		printf("\nList Is Empty\n");
 		return;
 	}
}
void deleteAKey()
{
	int element;
	printf("\nEnter Element To Delete: ");
	scanf("%d", &element);
	if(head == NULL)
		printf("\nList Is Empty\n");
   	else
   	{
      		struct node *temp = head;
      		while(temp->data != element)
      		{
         		if(temp->next == NULL)
         		{
            			printf("\nElement Not Found\n");
				break;
			}
         		else
            			temp = temp->next;
      		}
      		if(temp == head)
      		{
         		head = NULL;
         		free(temp);
      		}
      		else
     	 	{
         		temp->prev->next = temp->next;
         		free(temp);   
      		}
      	}
}
void countNodes()
{
	int count = 0;
	struct node *ptr = head;
	while(ptr != NULL)
	{	
		count++;
		ptr = ptr->next;
	}
	printf("\nTotal Number of Nodes: %d\n", count);
}
void searchElement()
{
	int element, count = 0, flag = 0;
	printf("\nEnter Element To Find: ");
	scanf("%d", &element);
	struct node *ptr = head; 
	while(ptr != NULL)
	{
		count++;
		if(ptr->data == element)
		{
			printf("\nElement %d Is Present At Node %d\n", element, count);
			flag = 1;
			break;
		}
		ptr = ptr->next;
	}
	if(flag == 0)
		printf("\nElement Not Found\n");
}
int main()
{
  	int n, choice;
	while(1)
	{
		printf("1. Create List\n");
		printf("2. Traverse List Forward\n");
		printf("3. Traverse List Backward\n");
		printf("4. Check List\n");
		printf("5. Insert Node At Beginning\n");
		printf("6. Insert Node At End\n");
		printf("7. Insert Node At Given Position\n");
		printf("8. Delete Node From Beginning\n");
		printf("9. Delete Node From End\n");
		printf("10. Delete Node From Given Position\n");
		printf("11. Delete Node For Given Key\n");
		printf("12. Count Total Number of Nodes\n");
		printf("13. Search Element\n");
		printf("14. Exit\n\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
    				createList();
    				break;
    			case 2:
    				traverseList();
    				break;
    			case 3:
    				traverseListBackward();
    				break;
    			case 4:
    				checkList();
    				break;
    			case 5:
    				insertAtBeginning();
    				traverseList();
    				break;
    			case 6: 
    				insertAtEnd();
    				traverseList();
    				break;
    			case 7: 
    				insertAtPosition();
    				traverseList();
    				break;
    			case 8:
    				deleteFromBeginning();
    				traverseList();
    				break;
    			case 9: 
    				deleteFromEnd();
    				traverseList();
    				break;
    			case 10:
    				deleteFromPosition();
    				traverseList();
    				break;
    			case 11: 
    				deleteAKey();
    				traverseList();
    				break;
    			case 12:
    				countNodes();
    				break;
    			case 13: 
    				searchElement();
    				break;
    			case 14:
    				exit(0);
    		}
    		printf("\n");
	}
	return 0;
}