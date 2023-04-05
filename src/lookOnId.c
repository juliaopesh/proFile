#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId)
{
    //Check if head is null
    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return -1;
    }
    //initialize node current, points to head
    struct employee * current = headLL;
    int position = 1;

    //Loops through employee nodes until an employee ID matches the passed ID
    while (current != NULL)
    {
        if (current ->empId == whichEmpId)
        {
            //If found, return at which position
            return position;
        }
        //Point to next node
        current = current->nextEmployee;
        position++; //Increment position
    }
    return -1; 
}

