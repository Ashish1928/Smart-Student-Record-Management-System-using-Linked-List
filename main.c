#include <stdio.h>
#include "linkedlist.h"

int main() {

    int choice;

    while(1) {

        printf("\n====================================");
        printf("\n SMART STUDENT RECORD MANAGEMENT");
        printf("\n====================================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Sort Students");
        printf("\n7. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}