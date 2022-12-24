#include <stdio.h>
#include <stdlib.h> //contains malloc,calloc,realloc,free....etc functions required for dynamic memory allocations

int main()
{
    int n;    // to hold number of block required
    int *ptr; // to hold dynamically allocated memory space of type integer

    printf("enter the number of block you want to reserve:\t");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int)); // malloc works for all type including structure because it doesnot get data in block and datatype form, rather it ask for total size of memory space and return initial address

    // storing data in allocated memory
    printf("\n\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    // printing just stored data and its location
    printf("\n\n\ndata you just entered with it's address:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t%d\n", ptr[i], &ptr[i]);
    }

    // reallocating same space
    printf("\n\n\n");
    printf("enter another number of block to reallocate same memory used before:\t");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));

    // storing data in reallocated memory
    for (int i = 0; i < n; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    // printing just stored data and its address
    printf("\n\n\ndata you just entered with it's address:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t%d\n", ptr[i], &ptr[i]);
    }

    free(ptr);

    // try printing same data - will face error
    printf("\n\n\n");
    printf("data and address of ptr[0] after free command on ptr:\n");
    printf("%d \t%d", ptr[0], &ptr[0]);

    return 0;
}