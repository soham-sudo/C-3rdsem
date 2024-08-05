//002210501077
//  Write a program to store student information in a file and t do the following operations. Information 
// includes roll, name, and score in five subjects. Use may like to add record (ensure roll number is unique), 
// display all records showing roll, name and total score. User may search for the record against a roll. User 
// may edit the details a record. User may delete record. Deletion may be logical (by some means indicate it is 
// an invalid record and to be avoided in processing) and physical (file will not have the record)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
struct Student
{
    int roll;
    char name[50];
    float scores[5];
    int isDeleted; // Flag to mark a record as deleted
};

// Function to add a new student record
void addRecord(FILE *file)
{
    struct Student student;
    printf("Enter Roll Number: ");
    scanf("%d", &student.roll);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Scores for 5 Subjects:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.scores[i]);
    }
    student.isDeleted = 0; // Initialize the isDeleted flag

    // Write the record to the file
    fwrite(&student, sizeof(struct Student), 1, file);
}

// Function to display all student records
void displayRecords(FILE *file)
{
    struct Student student;

    printf("Student Records:\n");
    printf("Roll Number\tName\t\tTotal Score\n");
    while (fread(&student, sizeof(struct Student), 1, file) == 1)
    {
        if (!student.isDeleted)
        {
            float totalScore = 0;
            for (int i = 0; i < 5; i++)
            {
                totalScore += student.scores[i];
            }
            printf("%d\t\t%s\t\t%.2f\n", student.roll, student.name, totalScore);
        }
    }
}

// Function to search for a record by roll number
void searchRecord(FILE *file)
{
    int searchRoll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &searchRoll);

    struct Student student;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, file) == 1)
    {
        if (!student.isDeleted && student.roll == searchRoll)
        {
            printf("Roll Number: %d\n", student.roll);
            printf("Name: %s\n", student.name);
            printf("Scores:\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Subject %d: %.2f\n", i + 1, student.scores[i]);
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Record with Roll Number %d not found.\n", searchRoll);
    }
}

// Function to edit a record by roll number
void editRecord(FILE *file)
{
    int editRoll;
    printf("Enter Roll Number to edit: ");
    scanf("%d", &editRoll);

    struct Student student;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, file) == 1)
    {
        if (!student.isDeleted && student.roll == editRoll)
        {
            printf("Enter new Name: ");
            scanf("%s", student.name);
            printf("Enter new Scores for 5 Subjects:\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Subject %d: ", i + 1);
                scanf("%f", &student.scores[i]);
            }
            fseek(file, -sizeof(struct Student), SEEK_CUR);
            fwrite(&student, sizeof(struct Student), 1, file);
            found = 1;
            printf("Record with Roll Number %d updated.\n", editRoll);
            break;
        }
    }

    if (!found)
    {
        printf("Record with Roll Number %d not found.\n", editRoll);
    }
}

// Function to delete a record by roll number (logical deletion)
void deleteRecord(FILE *file, FILE *deletedFile)
{
    int deleteRoll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &deleteRoll);

    struct Student student;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, file) == 1)
    {
        if (!student.isDeleted && student.roll == deleteRoll)
        {
            student.isDeleted = 1; // Mark as deleted
            fseek(file, -sizeof(struct Student), SEEK_CUR);
            fwrite(&student, sizeof(struct Student), 1, file);
            found = 1;
            printf("Record with Roll Number %d marked as deleted.\n", deleteRoll);
            break;
        }
    }

    if (!found)
    {
        printf("Record with Roll Number %d not found.\n", deleteRoll);
        return;
    }

    // Update the count of logically deleted records in A.dat
    fseek(deletedFile, 0, SEEK_SET);
    int deletedCount;
    fread(&deletedCount, sizeof(int), 1, deletedFile);
    deletedCount++;
    fseek(deletedFile, 0, SEEK_SET);
    fwrite(&deletedCount, sizeof(int), 1, deletedFile);

    // Check if the count exceeds 10, and if so, perform physical deletion
    if (deletedCount > 10)
    {
        struct Student temp;
        FILE *tempFile = fopen("temp.dat", "wb");
        if (tempFile == NULL)
        {
            perror("Error opening temporary file");
            exit(1);
        }

        while (fread(&temp, sizeof(struct Student), 1, file))
        {
            if (!student.isDeleted)
            {
                fwrite(&temp, sizeof(int), 1, tempFile);
            }
        }
        fclose(file);
        file = fopen("student_records.dat", "w");
        fseek(tempFile, 0, 0);
        while (fread(&temp, sizeof(struct Student), 1, tempFile))
        {
            fwrite(&temp, sizeof(int), 1, file);
        }
        fclose(tempFile);
        fclose(file);
        file = fopen("student_records.dat", "a+");
        remove("A.dat");

        // Rename the temporary file to A.dat
        fclose(tempFile);
        rename("temp.dat", "A.dat");

        printf("Physical deletion of records performed.\n");
    }
}

int main()
{
    FILE *file;
    FILE *deletedFile;

    file = fopen("student_records.dat", "a+"); // Open or create the file in binary append mode
    deletedFile = fopen("A.dat", "a+");        // Open or create the deleted records file

    if (file == NULL || deletedFile == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int choice;
    do
    {
        printf("\nStudent Record Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Edit Record\n");
        printf("5. Delete Record (Logical)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addRecord(file);
            break;
        case 2:
            displayRecords(file);
            break;
        case 3:
            searchRecord(file);
            break;
        case 4:
            editRecord(file);
            break;
        case 5:
            deleteRecord(file, deletedFile);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    fclose(file);
    fclose(deletedFile);
    return 0;
}
