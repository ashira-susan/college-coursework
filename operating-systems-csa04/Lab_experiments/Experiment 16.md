##  Employee Database Using File Handling

### Problem Statement

Write a C program to create an employee database using file handling. The program should allow the user to:

1. Add employee details
2. Display employee details
3. Update employee details
4. Exit the program

Employee details should include **Employee ID, Employee Name, and Employee Salary**.

### Program

```c
#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int empId;
    char empName[50];
    float empSalary;
};

int main()
{
    FILE *filePtr;
    struct Employee emp;

    filePtr = fopen("employee.dat", "rb+");

    if (filePtr == NULL)
    {
        filePtr = fopen("employee.dat", "wb+");

        if (filePtr == NULL)
        {
            printf("Error creating the file.\n");
            return 1;
        }
    }

    int choice;

    do
    {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee Details\n");
        printf("3. Update Employee Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empId);

                printf("Enter Employee Name: ");
                scanf("%s", emp.empName);

                printf("Enter Employee Salary: ");
                scanf("%f", &emp.empSalary);

                fseek(filePtr,
                      (emp.empId - 1) * sizeof(struct Employee),
                      SEEK_SET);

                fwrite(&emp,
                       sizeof(struct Employee),
                       1,
                       filePtr);

                printf("Employee details added successfully.\n");
                break;

            case 2:
                printf("Enter Employee ID to display: ");
                scanf("%d", &emp.empId);

                fseek(filePtr,
                      (emp.empId - 1) * sizeof(struct Employee),
                      SEEK_SET);

                fread(&emp,
                      sizeof(struct Employee),
                      1,
                      filePtr);

                printf("Employee ID: %d\n", emp.empId);
                printf("Employee Name: %s\n", emp.empName);
                printf("Employee Salary: %.2f\n", emp.empSalary);
                break;

            case 3:
                printf("Enter Employee ID to update: ");
                scanf("%d", &emp.empId);

                fseek(filePtr,
                      (emp.empId - 1) * sizeof(struct Employee),
                      SEEK_SET);

                fread(&emp,
                      sizeof(struct Employee),
                      1,
                      filePtr);

                printf("Enter Employee Name: ");
                scanf("%s", emp.empName);

                printf("Enter Employee Salary: ");
                scanf("%f", &emp.empSalary);

                fseek(filePtr,
                      (emp.empId - 1) * sizeof(struct Employee),
                      SEEK_SET);

                fwrite(&emp,
                       sizeof(struct Employee),
                       1,
```
