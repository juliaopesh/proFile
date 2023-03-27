#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL)
{
    char yn = 'y';
    char tempfn[MAX_LENGTH], templn[MAX_LENGTH];
    int count = 0;
    int empId = 0;

    struct employee *newEmp = (struct employee*)malloc(sizeof(struct employee));
    printf("Enter the first name of the employee: ");
    scanf("%s", tempfn);
    strcpy(newEmp->fname, tempfn);

    printf("Enter the last name of the employee: ");
    scanf("%s", templn);
    strcpy(newEmp->lname, templn);

    printf("\n");

    do
    {
        count++;
        printf("Enter the name of dependant #%d:",count);
        newEmp->dependents[count] = malloc(sizeof(char)*MAX_LENGTH);
        scanf("%s", newEmp->dependents[count]);
        printf("Do you have any more dependants? ");
        scanf(" %c", &yn);
        yn = tolower(yn);

        printf("\n");
    }
    while(yn!= 'n');

    printf("You have %d dependants.\n", count);

    empId = generateId(newEmp->fname, newEmp->lname, *headLL);
    printf("Your computer-generated empId is %d\n", empId);

}