#include <stdio.h>
#define SIZE 100

int q[SIZE];
int front=-1;
int rear=-1;

int full()
{
    return rear==SIZE-1;
}
int empty() 
{
    return (front==-1||front>rear);
}
void enqueue(int item)
{
    if(full())
    {
        printf("The queue is full\n");
        return;
    }
    if(front==-1)
    {
        front = 0;
    }
    rear++;
    q[rear] = item;
    printf("Enqueued element: %d\n",item);
}
int dequeue()
{
    if(empty())
    {
        printf("The queue is empty\n");
        return -1;
    }
    int item=q[front];
    front++;
    if(front>rear)
    {
        front=rear=-1;
    }
    return item;
}
void displayQ()
{
    if(empty())
    {
        printf("The queue is empty\n");
        return;
    }
    printf("The queue elements are:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",q[i]);
    }
    printf("\n");
}
int main()
{
    int choice,element;
    while(1)
    {
        printf("\nChoose an operation:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &choice);
        if(choice==1)
        {
            printf("Enter the element: ");
            scanf("%d", &element);
            enqueue(element);
        } 
        else if(choice==2)
        {
            element=dequeue();
            if (element!=-1)
            {
                printf("Dequeued element: %d\n",element);
            }
        } 
        else if (choice == 3)
        {
            displayQ();
        }
        else if (choice == 4)
        {
            printf("Exiting program...\n");
            break;
        } 
        else 
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}