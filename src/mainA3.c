#include "../include/headerA3.h"

int main (int argc, char *argv[])
{
    int choice;

    struct employee *headLL = NULL;

    loadEmpData(&headLL, argv[1]);

    do 
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

        printf("Please select an option from the menu :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 

                recruitEmployee(&headLL);
            
                break;
            
            case 2:

                printAll(headLL);
            
                break;
            
            case 3:
                printf("menu option. \n");
            
                break;

            case 4:
                printf("menu option. \n");
            
                break;

            case 5:
                printf("menu option. \n");
            
                break;

            case 6:
                printf("menu option. \n");
            
                break;
            
            case 7:
                printf("menu option. \n");
            
                break;
            
            case 8:
                printf("menu option. \n");
            
                break;
            
            case 9:
                printf("menu option. \n");
            
                break;
            
            case 10:
                printf("menu option. \n");
            
                break;
        }

    } while (scanf("%d", &choice) == 1 && choice != 10);

    return 0;
}