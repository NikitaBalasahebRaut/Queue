//queue implementation in c

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;


void Enqueue(PPNODE Head,int no)
{
	PNODE temp = *Head;
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

int Dequeue(PPNODE Head)
{
	PNODE temp = *Head;
	int no = 0;
	
	if(*Head == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		*Head = (*Head)->next;
		no = temp->data;
		free(temp);
		return no;
	}
}

void Display(PNODE Head)
{
	PNODE temp = Head;
	
	while(temp->next != NULL)
	{
		printf("%d<->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int Count(PNODE Head)
{
	int iCnt = 0;
	PNODE temp = Head;
	
	while(temp->next != NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}

int main()
{
	int no = 0;
	int iRet = 0;
	PNODE First = NULL;
	
	printf("Enter The Element\n");
	scanf("%d",&no);
	Enqueue(&First,no);
	
	printf("Enter The Element\n");
	scanf("%d",&no);
	Enqueue(&First,no);
	
	printf("Elements are :\n");
	Display(First);
	
	iRet = Dequeue(&First);
	printf("\n Removed Element is : %d", iRet);
	
	printf("\nElements are :\n");
	Display(First);
	
	iRet = Count(First);
	printf("\nNo of elements are : %d", iRet);
	return 0;
}