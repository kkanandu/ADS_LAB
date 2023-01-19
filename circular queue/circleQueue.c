#include <stdio.h>
#define MAX 5
void insert(int);
void deletion();
void display();
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue_arr[rear] = item;
    printf("inserted element is %d\n ",cqueue_arr[rear]);
    printf("rear is %d ", rear);
    printf("\n");
    printf("front %d \n",front);
}
void deletion()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("\nElement deleted from queue is : %d \n", cqueue_arr[front]);
    
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
    printf("rear is %d ", rear);
    printf("\n");
    printf("front %d \n", front);
}
void display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front_pos]);
                front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
int main()
{
    int choice, item;
    do
    {
        printf("1.Insertn \n 2.Deleten \n 3.Displayn \n 4.Quitn");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("\n%d", &item);
            insert(item);
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nWrong choicen");
        }
    } while (choice != 4);
    return 0;
}