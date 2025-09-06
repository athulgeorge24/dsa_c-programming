#include <stdio.h>
#define MAX 100
int main()
{
    char infix[MAX],postfix[MAX],stack[MAX];
    int i=0,j=0,top=-1;
    char ch;
    printf("Enter the Expressiom(no whitespace):");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if((ch>='A'&& ch<='Z')||(ch>='a' && ch<='z')||(ch>='0'&&ch<='9'))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            stack[++top]=ch;
        }
        else if(ch==')')
        {
            while(top!=-1 && stack[top]!='(')
                {
                    postfix[j++]=stack[top--];
                }
                if(top!=-1)
                {
                    top--;
                }
        }
        else 
        {
            while (top !=-1 && ((stack[top]=='^'&&ch != '^') || (stack[top]=='*'||stack[top]=='/')
                    || (stack[top]=='+'||stack[top]=='-')&&(ch=='+'||ch=='-'))) 
                {
                postfix[j++] = stack[top--];
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
