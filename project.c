// C program for the implementation of
// menu driven program for student
// management system

//created by Basak AKGUN

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>#include <stdio.h>
#include <string.h>
#include <conio.h>

int i,j;
int main_exit;
int createAccount_exit;
void menu();

// Variable to keep track of
// number of students
int i = 0;


typedef struct Student
{
    char studentName[50];
    char studentId[15];
    char studentDept[10];
    char studentAddress[100];
    char studentContactNum[15];
    float studentCGPA;
} Student;

void createAccount();
void displayInfo();
void updateInfo();
void deleteInfo();
void searchInfo();

//main menu function to select the tasks we want
void menu()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT DATABASE SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\t\t\t1. Create Student Account");
        printf("\n\t\t\t2. Display All Students Information");
        printf("\n\t\t\t3. Update Student Information");
        printf("\n\t\t\t4. Delete Student Information");
        printf("\n\t\t\t5. Search Student Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
            case '1':
                createAccount();
                break;
            case '2':
                displayInfo();
                break;
            case '3':
                updateInfo();
                break;
            case '4':
                deleteInfo();
                break;
            case '5':
                searchInfo();
                break;
            case '0':
                printf("\n\t\t\t====== Thank You ======");
                break;
            default:
                printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

void createAccount()
{   //program that will create a file studentInfo.bin with the following content
    FILE *fileOne = fopen("studentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t====== Create Student Account ======\n");

    printf("\n\t\t\tEnter Student's Name : ");
    getchar();
    gets(stundentInformation.studentName);
    printf("\t\t\tEnter Student's ID : ");
    gets(stundentInformation.studentId);
    printf("\t\t\tEnter Student's Department : ");
    gets(stundentInformation.studentDept);
    printf("\t\t\tEnter Student's Address : ");
    gets(stundentInformation.studentAddress);
    printf("\t\t\tEnter Student's Contact Number : ");
    gets(stundentInformation.studentContactNum);
    printf("\t\t\tEnter Student's Current CGPA : ");
    scanf("%f", &stundentInformation.studentCGPA);

    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");

    printf("\n\n\n\t\t\tPress any key to return to the Menu...");
    getch();
}

void displayInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t====== All Students Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-20s%-25s%-15s%-s\n", "Name", "ID", "Department", "Address", "Contact", "CGPA");
    printf("\t\t-------------------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-20s%-25s%-15s%-.2f", stundentInformation.studentName, stundentInformation.studentId, stundentInformation.studentDept, stundentInformation.studentAddress, stundentInformation.studentContactNum, stundentInformation.studentCGPA);
    }

    printf("\n\n\t\tPress any key to return to the Menu...");
    getch();

    fclose(fileOne);
}

void updateInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Students Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Dept.\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student Contact No.\n\t\t\t5.Update Student CPGA");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's Name to Update: ");
                getchar();
                gets(tempInformation.studentName);
                strcpy(studentInformation.studentName, tempInformation.studentName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Dept. to Update: ");
                getchar();
                gets(tempInformation.studentDept);
                strcpy(studentInformation.studentDept, tempInformation.studentDept);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Address to Update: ");
                getchar();
                gets(tempInformation.studentAddress);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Contact No. to Update: ");
                getchar();
                gets(tempInformation.studentContactNum);
                strcpy(studentInformation.studentContactNum, tempInformation.studentContactNum);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's CGPA to Update: ");
                scanf("%f", &tempInformation.studentCGPA);
                studentInformation.studentCGPA = tempInformation.studentCGPA;

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tPress any key to return to the Menu...");
    getch();
}

void deleteInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Student Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tPress any key to return to the Menu...");
    getch();
}

//function for searching student information
void searchInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    Student studentInformation;

    int choice, flag = 0;
    char studentID[20], studentDept[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search Student Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Dept.");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student ID : ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.studentId, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent Name : %s\n\t\t\tStudent ID : %s\n\t\t\tStudent Dept. : %s\n\t\t\tStudent Address : %s\n\t\t\tStudent Contact No. : %s\n\t\t\tStudent CGPA : %.2f\n", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t\xB2\xB2\xB2\ Search Student Information  \xB2\xB2\xB2\xB2");
        printf("\n\n\t\t\tEnter Student Dept. : ");
        getchar();
        gets(studentDept);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (stricmp(studentInformation.studentDept, studentDept) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tPress any key to return to the Menu...");
    getch();
}

//login screen for system opening
int main()
{

    system("color 9");

    char username[15];
    char password[12];
    int i=0;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT DATABASE SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\tEnter your username:");
    scanf("%s",&username);

    printf("\n\tEnter your password:");
    scanf("%s",&password);

    if(strcmp(username,"admin")==0){

        if(strcmp(password,"123")==0){


            printf("\n\n\n\n\n\n\n\n\n\tWelcome. Login Success!");
            system("cls");
            menu();
        }

    }else
    {   printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
        login_try:
        printf("\n\t\t\aTry Again = 1\t\t\aEXIT = 0:");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
            system("cls");
            main();
        }

        else if (main_exit==0)
        {
            system("cls");
            close();
        }
        else
        {   printf("\nInvalid!");
            system("cls");
            goto login_try;
        }

    }
    return 0;

}
