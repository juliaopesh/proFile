#include "../include/headerA3.h"

int main (int argc, char *argv[])
{
    int choice, pos, id, idPos, empCount, fired, count;
    char whichName [MAX_LENGTH];
    char yn = 'n';

    //Initialize head of linked list
    struct employee *headLL = NULL;

    //Fill employee list from file
    loadEmpData(&headLL, "proFile.txt");

    do //prints menu
    {
        printf("1. Add a new employee \n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");

        //Validate input
        printf("Please select an option from the menu : ");
        if (scanf("%d", &choice) != 1 || getchar() != '\n') 
        {
            while (getchar() != '\n'); //clear input buffer
            choice = 0; //trigger default
        }

        printf("\n");

        switch (choice) //Switch case for menu options
        {
            case 1: 
                //Function call to add employee to list
                recruitEmployee(&headLL);
                printf("\n\n");
            
                break;
            
            case 2:
                //Function call to print all employees
                printAll(headLL);
                printf("\n\n");
            
                break;
            
            case 3:
                //Function call to return employee at given position
                printf("Enter a position: \n");
                scanf("%d", &pos);
                printOne(headLL, pos);
                printf("\n\n");
                break;

            case 4:
                //Prompt user for employee id to find in list
                printf("Enter an employee ID: ");
                scanf("%d", &id);
                //Save returned position of employee with given ID in idPos
                idPos = lookOnId(headLL,id);
                printf("\n");
                //If ID not found
                if (idPos != -1) 
                {
                    // Traverse the linked list to get the employee at the given position
                    struct employee *current = headLL;
                    for (int i = 1; i < idPos; i++) 
                    {
                        current = current->nextEmployee;
                    }

                    // Print the employee information
                    printf("Employee id: %d\n", current->empId);
                    printf("First name: %s\n", current->fname);
                    printf("Last name: %s\n", current->lname);
                    printf("Dependents: ");
                    for (int i = 0; i < current->numDependents; i++) {
                        printf("%s", current->dependents[i]);
                        if (i < current->numDependents - 1) 
                        {
                            printf(", ");
                        }
                    }
                    printf("\n\n");
                }
                else 
                {
                    printf("Employee not found with empId %d.\n", id);
                }

                break;

            case 5:
                //Prompt user for the employee name to enter
                printf("Enter the full name of the employee: \n");
                //take name with fgets
                fgets(whichName,100,stdin);
                printf("\n");
                whichName[strlen(whichName)-1] = '\0';
                //Pass name and list (head) 
                pos = lookOnFullName(headLL, whichName); //position of employee with the name saved in pos
                printf("\n");
                if (pos != -1) 
                {
                    // Traverse list to get the employee at the given position
                    struct employee *current = headLL;
                    for (int i = 1; i < pos; i++) 
                    {
                        current = current->nextEmployee;
                    }

                    // Print the employee information
                    printf("Employee id: %d\n", current->empId);
                    printf("First name: %s\n", current->fname);
                    printf("Last name: %s\n", current->lname);
                    printf("Dependents: ");
                    for (int i = 0; i < current->numDependents; i++) 
                    {
                        //print dependants
                        printf("%s", current->dependents[i]);
                        if (i < current->numDependents - 1) 
                        {
                            printf(", ");
                        }
                    }
                    printf("\n\n");
                }
                else 
                {
                    printf("Employee not found with full name %s.\n", whichName);
                    printf("\n\n");
                }
                break;

            case 6:
                //Function call to count employees, returned amount saved in empCount
                empCount = countEmployees(headLL);
                printf("\n");
                printf("Total number of employees = %d", empCount);
                printf("\n\n");
                break;
            
            case 7:
                //Function call to sort function, prints sorted list
                printf("After sorting on empId, the employees are as follows: \n\n");
                sortEmployeesId(headLL);
                printf("\n\n");
                
                break;
            
            case 8:
                //calls employee count to find number of employees
                count = countEmployees(headLL);
                if (count == -1) //if liste empty
                {
                    count = 0; //set to 0 employees
                }
                //prompts user to enter position at which to fire employee
                printf("Currently there are %d employees.\n", count);
                printf("Which employee do you wish to fire - enter a value between 1 and %d: ", count);
                scanf("%d", &fired);
                if (fired < 1 || fired > count) //Input validation
                {
                    printf("Invalid position, try again.\n");
                    printf("\n\n");
                }
                else
                {   
                    fireOne(&headLL, fired); //Function call to fire employee at position
                    count = countEmployees(headLL);
                    printf("There are now %d employees \n", count);
                    printf("\n\n");
                }
            
                break;
            
            case 9:
                //Prompts user to enter yes or no
                printf("Are you sure you want to fire everyone: \n");
                scanf(" %c", &yn);
                yn = tolower(yn);
                //If yes, function call to fireAll
                if (yn == 'y')
                {
                    fireAll(&headLL);
                }
                printf("\n\n");
                break;
            
            case 10:
                //Exit loop
                printf("You've chosen to exit. \n\n");
            
                break;

            default:
                //Invalid entry
                printf("Invalid choice. Please try again.");
                printf("\n\n");
                break;

        }

    } while (choice != 10);
    //Loop runs until user enters 10

    //Freeing the employees
    struct employee *current = headLL;
    struct employee *temp;
    while (current != NULL)
    {
        temp = current->nextEmployee;
        for (int i = 0; i < current->numDependents; i++)
        {
            free (current->dependents [i]) ;
        }
        free (current->dependents);
        free (current);
        current= temp;
    }
    

    return 0;
}
