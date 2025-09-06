#include <stdio.h>
#include <string.h>
#define MAX 100
int precedence(char op) 
{
    if(op=='^') return 3;
    if(op=='*'||op=='/') return 2;
    if(op=='+'||op=='-') return 1;
    return 0;
}
int isRightAssociative(char op)
{
    return (op=='^');
}
int isOperand(char ch) 
{
    return((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'));
}
int main()
{
    char infix[MAX],postfix[MAX],stack[MAX];
    int i=0,j=0,top=-1;
    char ch;
    printf("Enter the Expression(no whitespace):");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isOperand(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(') 
        {
            stack[++top]=ch;
        }
        else if(ch==')') 
        {
            while(top!=-1&&stack[top]!='(') 
            {
                postfix[j++]=stack[top--];
            }
            if(top!=-1&&stack[top]=='(') top--;
        }
        else 
        {
            while(top!=-1&&stack[top]!='('&&
            (precedence(stack[top])>precedence(ch)||
            (precedence(stack[top])==precedence(ch)&&!isRightAssociative(stack[top])))) 
            {
                postfix[j++]=stack[top--];
            }
            stack[++top]=ch;
        }
        i++;
    }
    while(top!=-1)
    {
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
    printf("Postfix Expression: %s\n",postfix);
    return 0;
}
