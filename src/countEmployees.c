#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL)
{
    int count = 0;
    struct employee * current = headLL;

    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return -1;
    }

    while (current != NULL)
    {
        count++;
        current = current->nextEmployee;   
    }

    return count;
}
