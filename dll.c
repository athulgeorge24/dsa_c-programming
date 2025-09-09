#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char *url;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*newnode=NULL,*current=NULL;
void visit(const char *url)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->url=(char *)malloc(strlen(url)+1);
    strcpy(newnode->url,url);
    newnode->prev=current;
    newnode->next=NULL;
    if(current!=NULL)
    {
        current->next=newnode;
    }
    if(head==NULL)
    {
        head=newnode; 
    }
    current=newnode;
    printf("Visited: %s\n",newnode->url);
}
void go_back()
{
    if(current==NULL||current->prev==NULL)
        printf("Cannot go back\n");
    else
    {
        current=current->prev;
        printf("Moved back to %s\n",current->url);
    }
}
void go_forw()
{
    if(current==NULL||current->next==NULL)
        printf("Cannot go forward\n");
    else
    {
        current=current->next;
        printf("Move forward to %s\n",current->url);
    }
}
void dis_curr()
{
    if(current==NULL)
        printf("No page listed..\n");
    else
    {
        printf("Current page is %s\n",current->url);
    }
}
int main()
{
    int choice;
    char url[100];
    while(1)
    {
        printf("\nChoose an operation:\n");
        printf("1.Visit a new page\n");
        printf("2.Go back\n");
        printf("3.Go forward\n");
        printf("4.Display current page\n");
        printf("5.Exit\n");
        scanf("%d",&choice);
        
        if(choice==1)
        {
            printf("Enter a url to visit : \n");
            scanf("%s",url);
            visit(url);
        }
        else if(choice==2)
        {
            go_back();
        }
        else if(choice==3)
        {
            go_forw();
        }
        else if(choice==4)
        {
            dis_curr();
        }
        else if(choice==5)
        {
            printf("Exiting the program...\n\n");
            return 0;
        }
        else
        {
            printf("Invalid choice!!! try again...\n\n");
        }
    }
}