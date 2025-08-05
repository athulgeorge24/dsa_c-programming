#include <stdio.h>

#define SIZE 100

int cq[SIZE];
int front=-1;
int rear=-1;

int full()
{
    return (front==(rear+1)%SIZE);
}
int empty()
{
    return front==-1;
}
void enqueue(int item)
{
    if (full())
    {
        printf("Queue Overflow");
        return;
    }
    if(empty())
    {
        front=rear=0;
    } 
    else
    {
        rear=(rear+1)%SIZE;
    }
    cq[rear]=item;
    printf("Enqueued item: %d\n",item);
}
int dequeue()
{
    if(empty())
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int item=cq[front];
    if(front==rear)
    {
        front=rear=-1;
    } 
    else
    {
        front=(front+1)%SIZE;
    }
    return item;
}
void display()
{
    if(empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular queue elements: \n");
    int i=front;
    while(1)
    {
        printf("%d\t",cq[i]);
        if(i==rear)
        {
        break;
        }
        i=(i+1)%SIZE;
    }
    printf("\n");
}
int main()
{
    int choice,item,dequeueValue;

    while (1) {
        printf("\nChoose an operation\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display queue\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element to enqueue: ");
            scanf("%d",&item);
            enqueue(item);
        } 
        else if(choice==2)
        {
            dequeueValue=dequeue();
            if (dequeueValue!=-1)
            {
                printf("Dequeued:%d\n",dequeueValue);
            }
        } 
        else if(choice==3)
        {
            display();
        } 
        else if(choice==4)
        {
            printf("Exiting Program\n");
            break;
        } 
        else
        {
            printf("Invalid choice\n");
        }
    }
return 0;
}