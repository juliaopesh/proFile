#include "../include/headerA3.h"

void printAll (struct employee * headLL)
{
    int i;
    struct employee *current = headLL;
    while (current != NULL)
    { 
        i++;
        printf("\n");
        printf("Employee # %d: ",i);
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
        current = current->nextEmployee;
    }

    printf("Currently, there are %d employees.", i);
    printf("\n");
}
