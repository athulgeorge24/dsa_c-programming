#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
struct Node
{
    char data;
    struct Node* next;
};
struct ExprNode
{
    char data;
    struct ExprNode* left;
    struct ExprNode* right;
};
struct Node* newNode(char data)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}
struct ExprNode* newExprNode(char data)
{
    struct ExprNode* node=(struct ExprNode*)malloc(sizeof(struct ExprNode));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
void push(struct Node** top,char ch)
{
    struct Node* node=newNode(ch);
    node->next=*top;
    *top=node;
}
char pop(struct Node** top)
{
    if(*top==NULL)
    {
        return'\0';
    }
    struct Node* temp=*top;
    char ch=temp->data;
    *top=temp->next;
    free(temp);
    return ch;
}
char peek(struct Node* top)
{
    return(top!=NULL)?top->data:'\0';
}
int precedence(char ch)
{
    if(ch=='^')return 3;
    if(ch=='*'||ch=='/')return 2;
    if(ch=='+'||ch=='-')return 1;
    return 0;
}
struct ExprNode* buildExpressionTree(char infix[MAX])
{
    struct Node* stack=NULL;
    struct ExprNode* expStack[MAX];
    int top=-1;
    int i=0;
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(isalnum(ch))
        {
            expStack[++top]=newExprNode(ch);
        }
        else if(ch=='(')
        {
            push(&stack,ch);
        }
        else if(ch==')')
        {
            while(peek(stack)!='(')
            {
                char op=pop(&stack);
                struct ExprNode* right=expStack[top--];
                struct ExprNode* left=expStack[top--];
                struct ExprNode* node=newExprNode(op);
                node->left=left;
                node->right=right;
                expStack[++top]=node;
            }
            pop(&stack);
        }
        else
        {
            while(stack!=NULL&&precedence(peek(stack))>=precedence(ch))
            {
                char op=pop(&stack);
                struct ExprNode* right=expStack[top--];
                struct ExprNode* left=expStack[top--];
                struct ExprNode* node=newExprNode(op);
                node->left=left;
                node->right=right;
                expStack[++top]=node;
            }
            push(&stack,ch);
        }
        i++;
    }
    while(stack!=NULL)
    {
        char op=pop(&stack);
        struct ExprNode* right=expStack[top--];
        struct ExprNode* left=expStack[top--];
        struct ExprNode* node=newExprNode(op);
        node->left=left;
        node->right=right;
        expStack[++top]=node;
    }

    return expStack[top];
}
void printExprTree(struct ExprNode* root)
{
    if(root==NULL)return;
    printExprTree(root->left);
    printExprTree(root->right);
    printf("%c",root->data);
}
void infixToPostfix(char infix[MAX],char postfix[MAX])
{
    struct Node* stack=NULL;
    int i=0,j=0;
    char ch;
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(&stack,ch);
        }
        else if(ch==')')
        {
            while(stack!=NULL&&peek(stack)!='(')
            {
                postfix[j++]=pop(&stack);
            }
            pop(&stack);
        }
        else
        {
            while(stack!=NULL&&precedence(peek(stack))>=precedence(ch))
            {
                postfix[j++]=pop(&stack);
            }
            push(&stack,ch);
        }
        i++;
    }
    while(stack!=NULL)
    {
        postfix[j++]=pop(&stack);
    }
    postfix[j]='\0';
}
int main()
{
    char infix[MAX],postfix[MAX];
    struct ExprNode* exprTree;
    printf("Enter the Expression (no whitespace): ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("Postfix Expression: %s\n",postfix);
    exprTree=buildExpressionTree(infix);
    printf("Expression Tree: ");
    printExprTree(exprTree);
    printf("\n");

    return 0;
}