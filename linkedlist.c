#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

Student* head = NULL;

// Add Student
void addStudent() {

    Student* newNode = (Student*)malloc(sizeof(Student));

    printf("\nEnter Roll Number: ");
    scanf("%d", &newNode->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    // If list is empty
    if(head == NULL) {
        head = newNode;
    }
    else {
        Student* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent Added Successfully!\n");
}

// Display Students
void displayStudents() {

    Student* temp = head;

    if(temp == NULL) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    while(temp != NULL) {

        printf("\nRoll Number : %d", temp->roll);
        printf("\nName        : %s", temp->name);
        printf("\nMarks       : %.2f\n", temp->marks);

        temp = temp->next;
    }
}

// Search Student
void searchStudent() {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    Student* temp = head;

    while(temp != NULL) {

        if(temp->roll == roll) {

            printf("\nStudent Found!\n");

            printf("Roll Number : %d\n", temp->roll);
            printf("Name        : %s\n", temp->name);
            printf("Marks       : %.2f\n", temp->marks);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(found == 0) {
        printf("\nStudent Not Found!\n");
    }
}

// Update Student
void updateStudent() {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    Student* temp = head;

    while(temp != NULL) {

        if(temp->roll == roll) {

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("\nRecord Updated Successfully!\n");

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(found == 0) {
        printf("\nStudent Not Found!\n");
    }
}

// Delete Student
void deleteStudent() {

    int roll;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    Student *temp = head;
    Student *prev = NULL;

    // Delete first node
    if(temp != NULL && temp->roll == roll) {

        head = temp->next;

        free(temp);

        printf("\nRecord Deleted Successfully!\n");

        return;
    }

    // Search for node
    while(temp != NULL && temp->roll != roll) {

        prev = temp;
        temp = temp->next;
    }

    // Not found
    if(temp == NULL) {

        printf("\nStudent Not Found!\n");

        return;
    }

    // Delete node
    prev->next = temp->next;

    free(temp);

    printf("\nRecord Deleted Successfully!\n");
}

// Sort Students by Marks
void sortStudents() {

    Student *i, *j;
    Student temp;

    if(head == NULL) {
        printf("\nNo Records to Sort!\n");
        return;
    }

    for(i = head; i != NULL; i = i->next) {

        for(j = i->next; j != NULL; j = j->next) {

            if(i->marks < j->marks) {

                // Swap roll
                temp.roll = i->roll;
                i->roll = j->roll;
                j->roll = temp.roll;

                // Swap name
                strcpy(temp.name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp.name);

                // Swap marks
                temp.marks = i->marks;
                i->marks = j->marks;
                j->marks = temp.marks;
            }
        }
    }

    printf("\nRecords Sorted Successfully!\n");
}
