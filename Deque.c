#include <stdio.h>
#define SIZE 100

int dq[SIZE];
int front=-1;
int rear=-1;

int full()
{
    return (front==0&&rear==SIZE-1);
}

int empty()
{
    return front==-1;
}
void insertfront(int item)
{
    if(full())
    {
        printf("Deque Overflow");
        return;
    }
   if(empty())
   {
        front=rear=0;
    }
    else if(front>0)
    {
        front--;
    }
    else
    {
        for (int i=rear;i>=front;i--)
        {
            dq[i+1]=dq[i];
        }
        rear++;
    }
    dq[front]=item;
    printf("Inserted at front : %d ",item);
}
void deletefront()
{
    if(empty())
    {
        printf("Queue Underflow");
        return ;
    }
    printf("Delete from front: %d",dq[front]);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void insertrear(int item)
{
    if(full())
    {
        printf("Deque Overflow");
        return;
    }
    if(empty())
    {
        front=rear=0;
    }
    else if(rear<SIZE-1)
    {
        rear++;
    }
    dq[rear]=item;
    printf("Inserted at rear %d",item);
}
void deleterear()
{
    if(empty())
    {
        printf("Queue Underflow");
        return;
    }
    printf("Delete from rear: %d",dq[rear]);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    if(empty())
    {
        printf("Deque is empty");
        return;
    }
    printf("Deque Elements : ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",dq[i]);
    }
    printf("\n");
}
int main()
{
    int choice,element;
    while(1)
    {
        printf("\nChoose an operation:\n");
        printf("1.Insert front\n");
        printf("2.delete front\n");
        printf("3.Insert rear\n");
        printf("4.delete rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the item ,inserted at front : ");
            scanf("%d",&element);
            insertfront(element);
        }
        else if(choice==2)
        {
            deletefront();
        }
        else if(choice==3)
        {
            printf("Enter the item,inserted at rear");
            scanf("%d",&element);
            insertrear(element);
        }
        else if(choice==4)
        {
            deleterear();
        }
        else if(choice==5)
        {
            display();
        }
        else if(choice==6)
        {
            printf("Exit program...");
            break;
        }
        else
        {
            printf("Invalid choice");
        }
    }
    return 0;
}
