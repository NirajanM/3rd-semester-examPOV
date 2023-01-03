#include <stdio.h>
#include <stdbool.h> // for boolean
#include <stdlib.h>  // for exit func

#define SIZE 5 // size of queue

int front = -1, back = -1; // front and back of queue
bool isFull()
{
    if (back == (SIZE - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int *stk)
{
    if (isFull())
        printf("can't push, queue is full!\n");
    else
    {
        int data;
        printf("enter data:");
        scanf("%d", &data);
        stk[++back] = data;
        printf("pushed %d to rear of queue\n", data);
    }
}

void pop(int *stk)
{
    if (isEmpty())
        printf("can't pop, queue is empty!\n");
    else
    {
        printf("poped %d from front of queue\n", stk[front++]);
    }
}

void traverse(int *stk)
{
    printf("queue data:\n");
    for (int i = front; i <= back; i++)
    {
        printf("%d\n", stk[i]);
    }
}

int main()
{
    printf("%d %d", front, back);
    int queue[SIZE];
    while (1)
    {
        printf("\n\n");
        printf("1-> check full\n2-> check empty\n3-> push data\n4-> pop data\n5-> traverse queue\n6-> exit\n");
        int n;
        printf("enter number:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            isFull(queue) ? printf("queue is full\n\n") : printf("queue is not full\n\n");
            break;
        case 2:
            isEmpty(queue) ? printf("queue is empty\n\n") : printf("queue is not empty\n\n");
            break;
        case 3:
            push(queue);
            break;
        case 4:
            pop(queue);
            break;
        case 5:
            traverse(queue);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("wrong input!");
            break;
        }
    }
    return 0;
}