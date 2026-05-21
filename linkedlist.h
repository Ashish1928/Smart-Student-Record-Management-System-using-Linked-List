#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
} Student;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortStudents();

#endif