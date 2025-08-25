#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node* next;
};
struct node *createnode(int coeff,int expo)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    return newnode;
}
struct node *insrtnode(struct node *head,int coeff,int exp)
{
    struct node *newnode=createnode(coeff,exp);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
/*
~modified insrt node structure (fix jumbled order issue) ~

struct node *insrtnode(struct node *head, int coeff, int exp) {
    struct node *newnode = createnode(coeff, exp);
    
    // If list is empty or the new term has a higher exponent than the head, insert at the beginning
    if (head == NULL || head->expo < exp) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node *temp = head;
        // Traverse the list to find the correct position for the new node
        while (temp->next != NULL && temp->next->expo >= exp) {
            temp = temp->next;
        }
        // Insert the new node in the correct position
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}*/

void display(struct node* head)
{
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->expo);
        if(temp->next!=NULL)
        {
        printf("+");
        }
        temp=temp->next;
    }
    printf("\n");
}

struct node *add(struct node *p1,struct node *p2)
{
    struct node *result=NULL;

    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->expo>p2->expo)
        {
            result=insrtnode(result,p1->coeff,p1->expo);
            p1=p1->next;
        }
        else if(p2->expo>p1->expo)
        {
            result=insrtnode(result,p2->coeff,p2->expo);
            p2=p2->next;
        }
        else
        {
            int sum=p1->coeff+p2->coeff;
            if(sum!=0)
            {
                result=insrtnode(result,sum,p1->expo);
            }
            p1=p1->next;
            p2=p2->next;
        }
    }
    while (p1!=NULL)
    {
        result=insrtnode(result, p1->coeff, p1->expo);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        result=insrtnode(result,p2->coeff,p2->expo);
        p2=p2->next;
    }
    return result;
}
void main()
{
    struct node *p1=NULL,*p2=NULL,*sum=NULL;
    int n,m,coeff,expo,i;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter coefficient and exponent for term %d:",i+1);
        scanf("%d%d",&coeff,&expo);
        p1 = insrtnode(p1,coeff,expo);
    }
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        printf("Enter coefficient and exponent for term %d: ",i+1);
        scanf("%d%d",&coeff,&expo);
        p2=insrtnode(p2,coeff,expo);
    }
    printf("\nFirst Polynomial: ");
    display(p1);
    printf("Second Polynomial: ");
    display(p2);
    sum=add(p1,p2);
    printf("\nSum of Polynomials: ");
    display(sum);
}