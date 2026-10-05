#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
void insert();
void reme();
void display();
void main()
{
    printf("1.INSERT \n2. DELETE \n3. DISPLAY \n4. EXIT\n");
    int choice;
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: insert();
                    break;
            case 2: reme();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default:
                    printf("\ninvalid input");
        }
    }
}

void insert()
{
    int ele;
    if (rear==max-1)
    {
        printf("\nQueue is full (OVERFLOW)");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        printf("\nEnter the element");
        scanf("%d",&ele);
        queue[rear]=ele;
        printf("\n%d is inersted succesfully",ele);
    }
    else
    {
        printf("\nEnter the element");
        scanf("%d",&ele);
        rear++;
        queue[rear]=ele;
        printf("\n%d is inersted succesfully",ele);
    }
}

void reme()
{
    if(front==-1)
    {
        printf("\nQueue is Empty (UNDERFLOW)");
    }
    else if(front==rear)
    {
        printf("\n%d is succesfully deleted",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d is succesfully deleted",queue[front]);
        front++;
    }
}

void display()
{
     if(front==-1 &&rear==-1)
    {
        printf("\nQueue is Empty (UNDERFLOW)");
    }
    else
    {
        for(int i=front ; i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}
