/*A C program that uses functions to perform the following:
a.	Create a singly linked list of integers.
b.	Delete a given integer from the above linked list.
c.	Display the contents of the above list after deletion. */

#include<stdio.h>
struct node
            {
                int i;
                struct node *link;
            }*head;
void create(int n)
 {
    int a ;
     struct node *temp;
    head=(struct node*)malloc(sizeof(struct node));
                 if(head == NULL)
                 {
                     printf("Memory not allocated ");
                     return;
                 }
     printf("Enter data ");
     scanf("%d", &a);
     temp=head;
     head-> i =a;
     head->link=NULL;
        for(int i=2; i<=n; i++)
        {
            struct node  *NewNode=(struct node *)malloc(sizeof(struct node));
                if(NewNode== NULL)
                {
                    printf("Memory not allocated ");
                            break;
                }
                    printf("Enter data ");
                    scanf("%d", &a);
                    NewNode->i=a;
                    NewNode->link=NULL;
                    temp->link=NewNode;
                    temp = temp->link;
                }
        printf("List created successfuly!\n");
      }
 void deletedata(int n)
 {
     struct node *temp=head;
     if(temp->i==n)
     {
         head=temp->link;
         free(temp);
     }
     else
     {
      while(temp->link->i!=n)
    {
     temp=temp->link;
    }
    struct node *temp1=temp->link;
  temp->link=temp1->link;
  free(temp1);
     }
  printf("Data delete sussesfully !\n");
 }
void traverse()
 {
     struct node *temp=head;
     printf("List data are: ");
      while(temp)
     {
         printf("%d \t",temp->i);
         temp=temp->link ;
    }
    printf("\n");
 }
int main()
{
    int n,m;
    printf("Enter the no of node in linked list you want ");
    scanf("%d",&n);
    create(n);
     traverse();
     printf("Enter the data that you want to delete ");
     scanf("%d",&m);
     deletedata(m);
     printf("After deletion ");
     traverse();
   return 0;
}
