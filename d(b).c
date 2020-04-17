/* C programs to implement a double ended queue ADT using  Doubly linked list  */

#include<stdio.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Node;

Node *front=NULL;
Node *rear=NULL;

void createfirstnode()
{
     int data;
     front=(Node*)malloc(sizeof(Node));
     if(front==NULL)
     {
         printf("Memory not allocated");
         return;
     }
     printf("\nEnter first node data : ");
     scanf("%d",&data);
     front->data=data;
     front->prev=NULL;
     front->next=NULL;
     rear=front;
}

void insertFront()
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    if(front==NULL && rear==NULL)
    {
        createfirstnode();
        return ;
    }
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=front;
    temp->prev=NULL;
    front->prev=temp;
    front=temp;
}

void insertRear()
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    if(front==NULL && rear==NULL)
    {
        createfirstnode();
        return ;
    }
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=rear;
    rear->next=temp;
    rear=temp;
    if(front==NULL)
        front=temp;
}

void deleteFront()
{
    if(front==NULL)
    {
        printf("\n Queue is Underflow ");
        return ;
    }
    Node *temp=front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        free(temp);
        printf("\nNow Queue is empty ");
        return;
    }
    front=temp->next;
    front->prev=NULL;
    free(temp);
}

void deleteRear()
{
    if(rear==NULL)
    {
        printf("\nQueue is Underflow !!!");
        return ;
    }
    Node *temp=rear;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        free(temp);
        printf("\nNow Queue is empty ");
        return;
    }
    rear=temp->prev;
    rear->next=NULL;
    free(temp);
}

void traverse()
{
	Node *temp=front;
    printf("\nElements in Queue are : ");
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main()
{
	int opt;
    createfirstnode();
    do
  {
    printf("1.Insert at rear end\n");
    printf("2.Insert at front end\n");
    printf("3.Delete from front end\n");
    printf("4.Delete from rear end\n");
    printf("5.Display the data in queue\n");
    printf("6.Exit from program\n");
    printf("Enter your option :");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
          insertRear();
          break;
      case 2:
          insertFront();
          break;
      case 3:
          deleteFront();
          break;
      case 4:
          deleteRear();
          break;
      case 5:
          traverse();
          break;
      }
  }while(opt!=6);
return 0;
}
