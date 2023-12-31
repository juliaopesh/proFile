#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL)
{
    if (*headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }
    //Initialize node current, points to head
    a3Emp *current = *headLL;
    while (current != NULL) 
    {
        // Free each dependent for the current employee
        for (int i = 0; i < current->numDependents; i++)
        {
            free(current->dependents[i]);
        }
        // Free the dependents array
        free(current->dependents);
        
        //point to next node so that we can access the rest of the list
        a3Emp *next = current->nextEmployee;
        free(current); //free each node
        current = next; //set current to next
    }
    // set the head to NULL to indicate an empty list
    *headLL = NULL; 
    printf ("All fired. Linked list is now empty.\n");
}
