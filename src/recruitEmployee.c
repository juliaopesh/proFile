#include "../include/headerA3.h"

//Allows user to manually enter employee data for a new employee, appended to end of linked list
void recruitEmployee (struct employee ** headLL)
{
    char yn = 'y';
    char tempfn[MAX_LENGTH], templn[MAX_LENGTH];
    int empId = 0;

    //Allocating memory for new employee
    struct employee *newEmp = malloc(sizeof(struct employee));

    if (newEmp == NULL) 
    {
        //check if null
        printf("Error: unable to allocate memory for new employee\n");
        return;
    }
    //Take employee information (first name, last name)
    printf("Enter the first name of the employee: ");
    scanf("%s", tempfn);
    strcpy(newEmp->fname, tempfn);

    printf("Enter the last name of the employee: ");
    scanf("%s", templn);
    strcpy(newEmp->lname, templn);

    printf("\n");
    
    empId = generateId(newEmp->fname, newEmp->lname, *headLL);

    //Set number of dependants to 0 initially
    newEmp->numDependents = 0;

    newEmp -> dependents = malloc(sizeof(char *));

    while(yn == 'y')
    {
        //Reallocates memory for additional dependants   
        newEmp->dependents = realloc(newEmp -> dependents, sizeof(char *) * (newEmp->numDependents + 1));

        //Allocate memory to store each dependant name
        newEmp->dependents[newEmp->numDependents] = malloc(MAX_LENGTH * sizeof(char));

        printf("Enter the name of dependant #%d:",(newEmp->numDependents+1));
        scanf("%s", newEmp->dependents[newEmp->numDependents]);
        
        newEmp -> dependents[newEmp->numDependents][strlen(newEmp -> dependents[newEmp->numDependents])] = '\0';

        newEmp -> dependents[newEmp->numDependents] = realloc(newEmp -> dependents[newEmp->numDependents], 
        sizeof(char)*(strlen(newEmp -> dependents[newEmp->numDependents]) + 1));

        printf("Do you have any more dependants? ");
        scanf(" %c", &yn);
        yn = tolower(yn);

        (newEmp->numDependents)++;
    }

    printf("Your computer-generated empId is %d\n", empId);

    // Add new employee node to end of linked list
    newEmp->nextEmployee = NULL;
    
    if (*headLL == NULL) 
    {
        *headLL = newEmp;
    } 
    else  //Traverse list to point to new node
    {
        struct employee *temp = *headLL;
        while (temp->nextEmployee != NULL) 
        {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newEmp;
    }
    //Print num dependants
    printf("You have %d dependants.\n", newEmp->numDependents);
}
