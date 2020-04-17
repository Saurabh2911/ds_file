/* C programs to implement a double ended queue ADT using array */

#include<stdio.h>
#define MAX 20
int arr[MAX];
int front=-1,rear=-1;

void insertRear()
{
  int num;
  printf("Enter the value \n");
  scanf("%d",&num);
  if( (front==0 && rear==MAX-1) || (front==rear+1) )
  {
   printf("queue is OVERFLOW\n");
  }
  if(front==-1)
  {
   front=0;
   rear=0;
 }
  else
  {
   if(rear==MAX-1)
   rear=0;
   else
   rear=rear+1;
  }
  arr[rear]=num;
}

void insertFront()
{
  int num;
  printf("Enter the value \n");
  scanf("%d",&num);
  if( (front==0 && rear==MAX-1) || (front==rear+1) )
  {
   printf("queue is OVERFLOW\n");
  }
   if(front==-1)
  {
   front=0;
   rear=0;
  }
  else
  {
   if(front==0)
    front=MAX-1;
   else
    front=front-1;
  }
  arr[front]=num;
}

void deleteRear()
{
  if(front==-1)
  {
   printf("queue UNDERFLOW\n");
   return;
  }
  printf("The deleted element is %d\n", arr[rear]);
  if(front==rear)
 {
   front=-1;
   rear=-1;
 }
  else
 {
   if(rear==0)
   rear=MAX-1;
  else
   rear=rear-1;
 }
}
void deleteFront()
{
 if(front==-1)
 {
  printf("queue UNDERFLOW\n");
  return;
 }
 printf("The deleted element is %d\n", arr[front]);
 if(front==rear)
 {
  front=-1;
  rear=-1;
 }
 else
 {
  if(front==MAX-1)
   front=0;
  else
   front=front+1;
 }
}

void traverse()
{
 if(front==-1)
 {
  printf("Queue is Empty\n");
  return;
 }
 printf("Elements in  queue are:\n");
 if(front<=rear)
 {
  while(front<=rear)
  {
   printf("%d\t",arr[front]);
   front++;
  }
 }
 else
 {
  while(front<=MAX-1)
  {
   printf("%d\t",arr[front]);
   front++;
  }
  front=0;
  while(front<=rear)
  {
   printf("%d\t",arr[front]);
   front++;
  }
 }
 printf("\n");
}

int main()
{
  int option;
  do
  {
    printf("1.Insert at rear end\n");
    printf("2.Insert at front end\n");
    printf("3.Delete from front end\n");
    printf("4.Delete from rear end\n");
    printf("5.Display the data in queue\n");
    printf("6.Exit\n");
    printf("Enter your option :");
    scanf("%d",&option);
    switch(option)
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
  }while(option!=6);
return 0;
}
