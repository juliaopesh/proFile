#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne)
{

    if (*headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }

    //Nodes
    a3Emp * current = *headLL;
    a3Emp * prev = NULL;

    int index = 1;

    //Check if the employee to be fired is at the head of the list

    if (whichOne == 1)
    {
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
        prev->nextEmployee = current->nextEmployee;
    }
    
    printf("Employee [Id: %d] fired.\n", current->empId);
    free(current);
}

