#include <stdio.h>
#include <stdlib.h>

// Structure for Date of Birth
struct DOB
{
    int date;
    int month;
    int year;
};

// Structure for Address
struct address
{
    int pincode;
    char address[30];
};

// Structure for Student Record
struct studentRecord
{
    int rollNo;
    char name[20];
    float marks;
    struct address add;
    struct DOB dob;
    struct studentRecord *next;
};

// Function to insert a student record into a sorted linked list
void insertsorted(struct studentRecord **head, struct studentRecord *temp)
{
    if (*head == NULL)
    {
        // If the list is empty, set the new record as the head
        *head = temp;
        return;
    }

    struct studentRecord *curr = *head;

    if (temp->rollNo <= curr->rollNo)
    {
        // If the new record has a smaller roll number than the head, insert at the beginning
        temp->next = curr;
        *head = temp;
        return;
    }

    while (curr->next != NULL && temp->rollNo > curr->next->rollNo)
    {
        // Traverse the list to find the correct position for the new record
        curr = curr->next;
    }

    // Insert the new record at the correct position in the sorted list
    temp->next = curr->next;
    curr->next = temp;
}

int main()
{
    int roll, k=0;
    struct studentRecord *head = NULL;

    while (1)
    {
        int choice;
        // Menu for user interaction
        printf("\nEnter your choice \n1.Add Record\n2.Display Record\n3.Display All Record\n4.Update record\n5.Remove record\n6.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            // Add Record
            struct studentRecord *curr = (struct studentRecord *)malloc(sizeof(struct studentRecord));

            // Input from user
            printf("Enter student roll no: ");
            scanf("%d", &curr->rollNo);

            printf("Enter student name: ");
            fflush(stdin);
            scanf("%[^\n]", curr->name);

            printf("Enter student marks: ");
            scanf("%f", &curr->marks);

            printf("Enter student address: ");
            fflush(stdin);
            scanf("%[^\n]", curr->add.address);

            printf("Enter student pincode: ");
            scanf("%d", &curr->add.pincode);

            printf("Enter student date of birth\n");
            printf("date:");
            scanf("%d", &curr->dob.date);
            printf("month:");
            scanf("%d", &curr->dob.month);
            printf("year:");
            scanf("%d", &curr->dob.year);

            curr->next = NULL;
            insertsorted(&head, curr);
            printf("Record Added Successfully\n");
            break;
        }
        case 2:
        {
            // Display Record
            if (head == NULL)
            {
                printf("No Record in the Database\n");
            }
            else
            {
                printf("Enter the student roll no: ");
                scanf("%d", &roll);
                k = 0;
                struct studentRecord *temp = head;

                while (temp != NULL)
                {
                    // Display the record if found
                    if (temp->rollNo == roll)
                    {
                        printf("----------------------------STUDENT RECORD---------------------------------------\n");
                        printf("======|=============|========|=============|==========|=============\n");
                        printf("Rollno|\t\tName|\tMarks|\t    Address|\t   Pin|\t     D.O.B\n");
                        printf("======|=============|========|=============|==========|=============\n");
                        printf("%6d|\t%12s|\t%5.2f|\t%11s|\t%d|\t %d.%d.%d\n", temp->rollNo, temp->name, temp->marks, temp->add.address, temp->add.pincode, temp->dob.date, temp->dob.month, temp->dob.year);
                        printf("======|=============|========|=============|==========|=============\n");
                        k = 1;
                        break;
                    }
                    temp = temp->next;
                }

                if (k == 0)
                {
                    printf("Roll No does not exist in the database\n");
                }

                break;
            }
        }
        case 3:
        {
            // Display All Record
            if (head == NULL)
            {
                printf("No Record in the Database\n");
            }
            else
            {
                struct studentRecord *temp = head;

                printf("----------------------------STUDENT RECORD---------------------------------------\n");
                printf("======|=============|========|=============|==========|=============\n");
                printf("Rollno|\t\tName|\tMarks|\t    Address|\t   Pin|\t     D.O.B\n");

                while (temp != NULL)
                {
                    // Display all records in the list
                    printf("======|=============|========|=============|==========|=============\n");
                    printf("%6d|\t%12s|\t%5.2f|\t%11s|\t%d|\t %d.%d.%d\n", temp->rollNo, temp->name, temp->marks, temp->add.address, temp->add.pincode, temp->dob.date, temp->dob.month, temp->dob.year);
                    temp = temp->next;
                }

                printf("======|=============|========|=============|==========|=============\n");
            }

            break;
        }
        case 4:
        {
            // Update Record
            if (head == NULL)
            {
                printf("Student Record is Empty\n");
            }
            else
            {
                printf("Enter the student roll no: ");
                scanf("%d", &roll);

                struct studentRecord *curr = head;
                while (curr != NULL)
                {
                    if (curr->rollNo == roll)
                    {
                        // Update the fields of the selected record
                        printf("Enter student name: ");
                        fflush(stdin);
                        scanf("%[^\n]", curr->name);

                        printf("Enter student marks: ");
                        scanf("%f", &curr->marks);

                        printf("Enter student address: ");
                        fflush(stdin);
                        scanf("%[^\n]", curr->add.address);

                        printf("Enter student pincode: ");
                        scanf("%d", &curr->add.pincode);

                        printf("Enter student date of birth\n");
                        printf("date:");
                        scanf("%d", &curr->dob.date);
                        printf("month:");
                        scanf("%d", &curr->dob.month);
                        printf("year:");
                        scanf("%d", &curr->dob.year);

                        break;
                    }
                    curr = curr->next;
                }
            }
            printf("Record Updated Successfully\n");
            break;
        }
        case 5:
        {
            // Remove Record
            if (head == NULL)
            {
                printf("Student Record is Empty\n");
            }
            else
            {
                printf("Enter the student roll no: ");
                scanf("%d", &roll);

                struct studentRecord *temp

 = head;

                if (roll == temp->rollNo)
                {
                    // Remove the first node if it matches the given roll number
                    head = temp->next;
                    free(temp);
                }
                else
                {
                    while (temp->next != NULL)
                    {
                        if (temp->next->rollNo == roll)
                        {
                            // Remove the node with the matching roll number
                            struct studentRecord *curr = temp->next;
                            temp->next = curr->next;
                            curr->next = NULL;
                            free(curr);
                            k=1;
                            break;
                        }
                        temp = temp->next;
                    }
                        if(k==1)
                              printf("Record Deleted Successfully\n");
                        else
                              printf("Rollno doesn't exist");
                }
            }
           
            break;
        }
        case 6:
        {
            // Free the allocated memory before exiting
            while (head != NULL)
            {
                struct studentRecord *temp = head;
                head = head->next;
                free(temp);
            }

            printf("*Thank You*\n");
            exit(0);
        }
        default:
            printf("Enter correct choice:\n");
            break;
        }
    }

    return 0;
}
