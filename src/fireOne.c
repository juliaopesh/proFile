#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne)
{
    //Check if null
    if (*headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }

    //Nodes
    a3Emp * current = *headLL; //head
    a3Emp * prev = NULL; 

    int index = 1;

    //Check if the employee to be fired is at the head of the list

    if (whichOne == 1)
    {
        for (int i = 0; i < current->numDependents; i++)
        {
            free(current->dependents[i]);
        }
        // Free the dependents array
        free(current->dependents);
        *headLL = current ->nextEmployee;
    }
    else
    {
        //Loop through list to count employees
        while (index != whichOne)
        {
            prev = current;
            current = current -> nextEmployee;
            index++;
        }
        for (int i = 0; i < current->numDependents; i++)
        {
            free(current->dependents[i]);
        }
        // Free the dependents array
        free(current->dependents);

        //point to next so that we can continue (not lose head)
        prev->nextEmployee = current->nextEmployee;
    }
    
    printf("Employee [Id: %d] fired.\n", current->empId);

    //Frees head
    free(current);
}

