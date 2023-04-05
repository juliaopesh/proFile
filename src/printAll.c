#include "../include/headerA3.h"

void printAll (struct employee * headLL)
{
    int i = 0;

    //Initialize head of list
    struct employee *current = headLL;

    //check if null
    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }
    
    //Loop prints each node
    while (current != NULL)
    { 
        i++;
        printf("\n");
        printf("Employee # %d: ",i);
        printf("\tEmployee ID: %d\n", current->empId);
        printf("\tFirst name: %s\n", current->fname);
        printf("\tLast name: %s\n", current->lname);
        printf("\tDependents[%d]: ", current-> numDependents);
        //print dependants
        for (int j = 0; j < current-> numDependents; j++)
        {
            printf("%s ", current->dependents[j]);
            if(j != current->numDependents - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
        //point to next node
        current = current->nextEmployee;
    }

    printf("Currently, there are %d employees.", i);
    printf("\n");

}
