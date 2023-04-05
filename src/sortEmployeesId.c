#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL)
{
    struct employee * current = headLL;
    int count = 0;

    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }

    while (current != NULL)
    {
        count ++;
        current = current->nextEmployee;

    }

    struct employee* employeeArr[count];
    current = headLL;

    for( int i = 0; i < count; i++)
    {
        employeeArr[i] = current;
        current = current->nextEmployee;
    }

    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = 0; j < count - i - 1; j++) 
        {
            if (employeeArr[j]->empId > employeeArr[j+1]->empId) 
            {
                struct employee* temp = employeeArr[j];
                employeeArr[j] = employeeArr[j+1];
                employeeArr[j+1] = temp;
            }
        }
    }


    for (int i = 0; i < count; i++)
    {
        current = employeeArr[i];
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
    printf("\n");

}
