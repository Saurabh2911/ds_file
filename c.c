/* C program that uses stack operations to convert a given
infix expression into its postfix Equivalent. */

#include<stdio.h>
char stack[10];
int top=-1 ;
void push(char x)
{
    top++;
    stack[top]=x ;
}
void pop()
{
    printf("%c",stack[top]);
    top-- ;
}
int main()
{
    char str[20];
    printf("enter infix expresion");
    gets(str);
    printf("given expresion are:");
    puts(str);
    printf("postfix form of expresion are:");
    for(int i=0;str[i]!=NULL;i++)
    {
    if(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' || str[i]=='4' || str[i]=='5' || str[i]=='6' || str[i]=='7' || str[i]=='8' || str[i]=='9')
        printf("%c",str[i]);
    else
    {
        if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'  || str[i]=='%') && top==-1)
        {
            push(str[i]);
        }
        else if (str[i]=='(')
        {
            push(str[i]);
        }
        else if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'  || str[i]=='%') &&(stack[top]=='('))
        {
            push(str[i]);

        }
          else if((str[i]=='*' || str[i]=='/' || str[i]=='^' || str[i]=='%')&&(stack[top]=='+' || stack[top]=='-'))
          {
           push(str[i]);
          }
          else if( (str[i]=='^')&&(stack[top]=='*' || stack[top]=='/' || stack[top]=='%'))
          {
        push(str[i]);
          }
        else if((str[i]=='+' || str[i]=='-')&& (stack[top]=='+' || stack[top]=='-' || stack[top]=='*' || stack[top]=='/' || stack[top]=='%' || stack[top]=='^'))
        {
                while(top!=-1 && stack[top]!='(')
                pop();
                push(str[i]);
        }
        else if((str[i]=='*' || str[i]=='/' || str[i]=='%')&&(stack[top]=='/' || stack[top]=='*' || stack[top]=='%'))
            {
                while(top!=-1 && stack[top]!='(' )
                pop();
                push(str[i]);
            }
        else if(str[i]==')')
        {
            while(stack[top]!='(')
                    pop() ;
                    top-- ;
        }
    }
    }
     while(top!=-1)
        pop();
    return 0;

}
