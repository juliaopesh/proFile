#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100])
{
    int pos = 0;
    int spaces = 0;
    struct employee *current = headLL;
    char str [100];

    if (headLL == NULL) 
    {
        printf("The linked list is empty.\n");
        return -1;
    }
    

    for (int i = 0; i < strlen(whichName); i++)
    {
        if(whichName[i] == ' ')
        {
            spaces++;
        }
    }

    // Search for employee with matching full name
    while (current != NULL) 
    {
        // Concatenate first name, required number of spaces, and last name into str
        strcpy(str, current->fname);

        for (int i= 0; i < spaces; i ++)
        {
            strcat(str," ");
        }

        strcat(str,current->lname);

        pos++;

        if (strcmp(whichName, str) == 0)
        {
            return pos;
        }
        current = current->nextEmployee;
    }
    //if no match found
    return -1;
}
