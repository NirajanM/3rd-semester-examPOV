#include <stdio.h>
#include <stdbool.h> // for boolean
#include <stdlib.h>  // for exit func

#define SIZE 5 // size of stack

int tos = -1; // top of stack, -1 for empty

bool isFull()
{
    if (tos == (SIZE - 1))
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
    if (tos == -1)
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
        printf("can't push, stack is full!\n");
    else
    {
        int data;
        printf("enter data:");
        scanf("%d", &data);
        stk[++tos] = data;
        printf("pushed %d to top of stack\n", data);
    }
}

void pop(int *stk)
{
    if (isEmpty())
        printf("can't pop, stack is empty!\n");
    else
    {
        printf("poped %d from top of stack\n", stk[tos--]);
    }
}

void traverse(int *stk)
{
    printf("stack data:\n");
    for (int i = 0; i <= tos; i++)
    {
        printf("%d\n", stk[i]);
    }
}

int main()
{
    int stack[SIZE];
    while (1)
    {
        printf("\n\n");
        printf("1-> check overflow\n2-> check underflow\n3-> push data\n4-> pop data\n5-> traverse stack\n6-> exit\n");
        int n;
        printf("enter number:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            isFull(stack) ? printf("stack is full\n\n") : printf("stack is not full\n\n");
            break;
        case 2:
            isEmpty(stack) ? printf("stack is empty\n\n") : printf("stack is not empty\n\n");
            break;
        case 3:
            push(stack);
            break;
        case 4:
            pop(stack);
            break;
        case 5:
            traverse(stack);
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