/*C program that uses functions to perform the following:
a.	Create a doubly linked list of integers.
b.	Delete a given integer from the above doubly linked list.
c.	Display the contents of the above list after deletion */

#include<stdio.h>
 struct node
            {
                int i;
                struct node *prev;
                struct node *next;
            }*head;
 void create(int n)
 {
     struct node *temp;
     int x ;
    head=(struct node*)malloc(sizeof(struct node));
                 if(head == NULL)
                 {
                     printf("Memory not allocated ");
                     return;
                 }
     printf("Enter data ");
     scanf("%d", &x);
     temp=head;
     temp->prev=NULL;
     temp->next=NULL;
     temp->i = x;
     int k;
        for(int i=2; i<=n; i++)
            {

            struct node  *NewNode=(struct node *)malloc(sizeof(struct node));
                if(NewNode== NULL)
                    {
                        printf("Memory not allocated ");
                        break;
                    }
                    printf("Enter data ");
                    scanf("%d", &k);
                    NewNode->i=k;
                    temp->next=NewNode;
                    NewNode->next=NULL;
                    NewNode->prev=temp;
                    temp=temp->next;
                  }
        printf("List created successfuly!\n");
}
void deletedata(int n)
 {
     struct node *temp=head;
     if(temp->i==n)
     {
         head=temp->next;
         head->prev=NULL;
         free(temp);
     }
     else
 {
      while(temp->next->i!=n)
    {
     temp=temp->next;
    }
    if(temp->next->next==NULL)
    {
       struct node *temp2=temp->next;
       temp->next=NULL ;
       free(temp2);
    }
    else
    {
    struct node *temp1=temp->next;
  temp->next=temp1->next;
  temp1->next->prev=temp1->prev;
  free(temp1);
    }
 }
  printf("data delete sussesfully! \n");
}

void traverse()
 {
     struct node *temp=head;
     printf("list data are:");
      while(temp)
     {
         printf("%d \t",temp->i);
         temp=temp->next ;
    }
 }
int main()
{
    int x,m;
    printf("Enter the no. of node you want ");
    scanf("%d",&x);
    create(x);
    traverse();
    printf("\n enter the data that you want to delete ");
     scanf("%d",&m);
     deletedata(m);
     printf("After deletion ");
     traverse();
    return 0;
}

