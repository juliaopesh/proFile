#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne)
{
    struct employee * current = headLL;
    int index = 1;

    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }

    while (current != NULL && index < whichOne)
    {
        current = current -> nextEmployee;
        index++;

    }

    if (current!= NULL && index == whichOne)
    {
        printf("\n");
        printf("\tEmployee ID: %d\n", current->empId);
        printf("\tFirst name: %s\n", current->fname);
        printf("\tLast name: %s\n", current->lname);
        printf("\tNumber of dependents: %d\n", current->numDependents);
        printf("\tDependents[%d]: ", current -> numDependents);
        for (int j = 0; j < current-> numDependents; j++)
        {
            printf("%s, ", current->dependents[j]);
        }
        printf("\n");
    }
    else 
    {
        printf("Employee not found at position %d.\n", whichOne);
    }
    
}
