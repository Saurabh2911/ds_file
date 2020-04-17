/* C program that to calculate:	Number of Leaf and non Leaf node in a Binary Tree */

#include <stdio.h>
  struct node
            {
                int data;
                struct node *left;
                struct node *right;
            }*root;
struct node *create()
{
 int x;
struct node *newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter the integer data for the nodes(-1 for no data)");
 scanf("%d", &x);
 if(x==-1)
 {
     return NULL;
      }
      newnode->data=x;
      printf("Enter the left child data rooted at %d \n",newnode->data);
      newnode->left=create();
      printf("Enter the right child data rooted at %d\n",newnode->data);
      newnode->right=create();
      return newnode;
}
int NoOfLNode(struct node *t)
{
    if(t==NULL)
    {
        return 0;
    }
     if(t->left==NULL && t->right==NULL)
    {
        return 1;
    }
    else
    return (NoOfLNode(t->left)+NoOfLNode(t->right));
}
int NoOfNonLNode(struct node *t)
{
   if(t==NULL)
    {
        return 0;
    }
    else if(t->left==NULL && t->right==NULL)
    {
        return 0;
    }
    else
    return (1+NoOfNonLNode(t->left)+NoOfNonLNode(t->right));
}
int main()
{
    int n,m;
struct node *root=create();
printf("Binary tree are created");
struct node *t=root ;
n=NoOfLNode(t);
printf("\nNo. of Leaf node in binary tree are %d",n);
m=NoOfNonLNode(t);
printf("\nNo. of Non Leaf node in binary tree are %d",m);
return 0;
}

