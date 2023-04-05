#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL)
{
    char yn;
    char tempfn[MAX_LENGTH], templn[MAX_LENGTH];
    int count = 0;
    int empId;

    struct employee *newEmp = (struct employee*)malloc(sizeof(struct employee));
    if (newEmp == NULL) 
    {
        printf("Error: unable to allocate memory for new employee\n");
        return;
    }
    printf("Enter the first name of the employee: ");
    scanf("%s", tempfn);
    strcpy(newEmp->fname, tempfn);

    printf("Enter the last name of the employee: ");
    scanf("%s", templn);
    strcpy(newEmp->lname, templn);

    printf("\n");

    printf("Enter name of dependent# 1: ");
    newEmp->numDependents = 1;
    newEmp->dependents = (char **) malloc(sizeof(char*));
    newEmp->dependents[0] = (char *) malloc(MAX_LENGTH * sizeof(char));
    scanf("%s", newEmp->dependents[0]);
    printf("\n");

    empId = generateId(newEmp->fname, newEmp->lname, *headLL);
    newEmp->empId = empId;

    do
    {
        printf("Do you have any more dependants? ");
        getchar();
        scanf(" %c", &yn);
        //yn = getc(stdin);
        yn = tolower(yn);
        if (yn == 'y')
        {
            newEmp->numDependents++;
            newEmp->dependents = (char **) realloc(newEmp->dependents, newEmp->numDependents * sizeof(char *));
            if (newEmp->dependents == NULL) 
            {
                printf("Error: unable to allocate memory for dependents\n");
                for (int i = 0; i < newEmp->numDependents-1; i++)
                {
                    free(newEmp->dependents[i]);
                }
                free(newEmp->dependents);
                free(newEmp);
                return;
            }
            newEmp->dependents[newEmp->numDependents - 1] = (char *) malloc(MAX_LENGTH * sizeof(char));
            count++;
            printf("Enter the name of dependant #%d:",newEmp->numDependents);
            scanf("%s", newEmp->dependents[count-1]);
        }

        printf("\n");
    }
    while(yn == 'y');

    printf("Your computer-generated empId is %d\n", empId);

    // Add new employee node to end of linked list
    newEmp->nextEmployee = NULL;
    if (*headLL == NULL) 
    {
        *headLL = newEmp;
    } 
    else 
    {
        struct employee *temp = *headLL;
        while (temp->nextEmployee != NULL) 
        {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newEmp;
    }

    printf("You have %d dependants.\n", newEmp->numDependents);


}