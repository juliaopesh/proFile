#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId)
{
    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return -1;
    }

    struct employee * current = headLL;
    int position = 1;

    while (current != NULL)
    {
        if (current ->empId == whichEmpId)
        {
            return position;
        }
        current = current->nextEmployee;
        position++;
    }
    return -1;
}

