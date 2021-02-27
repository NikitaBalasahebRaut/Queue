//Queue operations ie Enqueue and dequeue

#include<iostream>
using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
}NODE,*PNODE;

class Queue
{
private:
        PNODE  Head;
        int iSize;

public:
       Queue();
       ~Queue();
       void Enqueue(int);
       int Dequeue();
       int Count();
       void Display();	   
};

Queue::~Queue()
{
	
}
Queue::Queue()
{
	Head = NULL;
	iSize = 0;
}
void Queue::Enqueue(int value)        //insert last
{
   PNODE newn = NULL;
   newn = new NODE;           //memory allocation
  
   newn->data = value;       //member initilization
   newn->next = NULL;
   
   if(Head == NULL)
   {
	   Head = newn;
   }
   else
   {
	   PNODE temp = Head;
	   
	   while(Head->next != NULL)
	   {
		   temp = temp->next;
	   }
	   temp->next = newn;
   }
   iSize++;
   
}

int Queue::Dequeue()
{	
  if(Head == NULL)
  {
     cout<<"Queue is empty\n";
	 return -1;
  }
  else
  {
	  int no = 0;
	PNODE temp = Head;
	
	 Head = Head->next;
	 no = temp->data;
	 delete temp;
	 
	 iSize--;
	 
	  return no;
  }	  
 
}

void Queue::Display()
{
	PNODE temp = Head;
	
	while(temp != NULL)
	{
		cout<<temp->data<<"\n";
		temp = temp->next;
	}
	cout<<"\n";
}

int Queue::Count()
{
	return iSize;
}


int main()
{
	Queue obj;
	int no = 0;
	int iRet = 0;
	
	cout<<"Enter The Number\n";
	cin>>no;
	obj.Enqueue(no);
	
		cout<<"Enter The Number\n";
	cin>>no;
	obj.Enqueue(no);
	
	cout<<"Elements are:\n";
	obj.Display();
	
	iRet = obj.Dequeue();
	cout<<"Removed Element is:"<<iRet<<"\n";
	
	iRet = obj.Count();
	cout<<"Number of elements are:"<<iRet<<"\n";
	
	return 0;
}

/*
output 
Enter The Number
10
Enter The Number
20
Elements are:
10
20

Removed Element is:10
Number of elements are:1
*/