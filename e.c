/* C program that uses functions to perform the following:
a.	Create a binary search tree of characters.
b.	Traverse the above Binary search tree recursively in Postorder, inorder and Preorder. */

#include <stdio.h>
struct node
    {
        char data;
        struct node *left;
        struct node *right;
    }*root=NULL;
void insert(char n)
{
 struct node *t=root;
 struct node *q,*r;
 if(root==NULL)
 {
     q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     root=q;
     return;
 }
 while(t!=NULL)
 {
     r=t;
     if(n<t->data)
        t=t->left;
   else  if(n>t->data)
        t=t->right ;
     else
        return ;
 }
 q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     if(n<r->data)
        r->left=q;
     else
        r->right=q;
}
void inorder(struct node *t)
{
    if(t)
    {
    inorder(t->left);
    printf("%c \t",t->data);
    inorder(t->right);
    }
}
void preorder(struct node *t)
{
    if(t)
    {
    printf("%c \t",t->data);
    preorder(t->left);
    preorder(t->right);
    }
}
void postorder(struct node *t)
{
    if(t)
    {
    postorder(t->left);
    postorder(t->right);
    printf("%c \t",t->data);
    }
}
int main()
{
    int n;
    char numb;
printf("Enter the no of elements that you want to insert in binary search tree \n");
scanf("%d",&n);
printf("NOTE-First element that you enter will act as Root node\n");
printf("Enter the character datas to insert in binary  search tree \n");
for (int i = 0; i <n+1;i++)
	{
		scanf("%c",&numb);
		insert(numb);
		fflush(stdin);
	}
printf("Binary search tree of character input are created \n");
printf("Inorder transversal of tree are: ");
inorder(root);
printf("\nPreorder transversal of tree are: ");
preorder(root);
printf("\nPostorder transversal of tree are: \n\t");
postorder(root);
return 0;
}

