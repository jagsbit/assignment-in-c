#include <stdio.h>
#include <stdlib.h>
// dob structure
struct DOB
{
    int date;
    int month;
    int year;
};
// address structure
struct address
{
    int pincode;
    char address[30];
};
// strudentRecord structure
struct studentRecord
{
    int rollNo;
    char name[20];
    float marks;
    struct address add;
    struct DOB dob;
};
void main()
{

    int n = 100, c = 0, roll, dltcountr = 0, k;
    // dynamically allocating memory
    struct studentRecord *s = (struct studentRecord *)malloc(n * sizeof(struct studentRecord));
    int choice;
    while (1)
    {
        printf("Enter your choice \n1.Add Record\n2.Display Record\n3.Display All Record\n4.Remove record\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            /* Addd record*/

            // roll no
            printf("Enter student roll no: ");
            scanf("%d", &s[c].rollNo);
            // name
            printf("Enter student name: ");
            fflush(stdin);
            scanf("%[^\n]", &s[c].name);
            // marks
            printf("Enter student marks: ");
            scanf("%f", &s[c].marks);
            // address
            printf("Enter student address: ");
            fflush(stdin);
            scanf("%[^\n]", &s[c].add.address);
            printf("Enter student pincode: ");
            scanf("%d", &s[c].add.pincode);
            // date of birth;
            printf("Enter student date of birth\n");
            printf("date:");
            scanf("%d", &s[c].dob.date);
            printf("month:");
            scanf("%d", &s[c].dob.month);
            printf("year:");
            scanf("%d", &s[c].dob.year);
            printf("Strudent Record Adde\n");
            c++;
            dltcountr++;
            break;
        case 2:
            // Display single Record
            if (dltcountr == 0)
            {
                printf("No Record in the Database\n");
            }
            else
            {

                printf("Enter the student roll no: ");
                scanf("%d", &roll);
                k = 0;
                for (int i = 0; i < c; i++)
                {
                    if (s[i].rollNo == roll)
                    {
                        printf("----------------------------STUDENT RECORD---------------------------------------\n");
                        printf("======|=============|========|=============|==========|=============\n");
                        printf("Rollno|\t\tName|\tMarks|\t    Address|\t   Pin|\t     D.O.B\n");
                        printf("======|=============|========|=============|==========|=============\n");
                        printf("%6d|\t%12s|\t%5.2f|\t%11s|\t%d|\t %d.%d.%d\n", s[i].rollNo, s[i].name, s[i].marks, s[i].add.address, s[i].add.pincode, s[i].dob.date, s[i].dob.month, s[i].dob.year);
                        printf("======|=============|========|=============|==========|=============\n");
                        k = 1;
                        break;
                    }
                }
                if (k == 0)
                {
                    printf("Roll No does not exist in the database\n");
                }

                break;

            case 3:
                // Display All record
                if (dltcountr == 0)
                {
                    printf("No Record in the Databse\n");
                }
                else
                {
                    printf("----------------------------STUDENT RECORD---------------------------------------\n");
                    printf("======|=============|========|=============|==========|=============\n");
                    printf("Rollno|\t\tName|\tMarks|\t    Address|\t   Pin|\t     D.O.B\n");
                    for (int i = 0; i < c; i++)
                    {
                        if (s[i].rollNo == -1)
                        {
                            continue;
                        }
                        printf("======|=============|========|=============|==========|=============\n");
                        printf("%6d|\t%12s|\t%5.2f|\t%11s|\t%d|\t %d.%d.%d\n", s[i].rollNo, s[i].name, s[i].marks, s[i].add.address, s[i].add.pincode, s[i].dob.date, s[i].dob.month, s[i].dob.year);
                    }
                    printf("======|=============|========|=============|==========|=============\n");
                }
                break;
            case 4:
                // delete record
                if (dltcountr == 0)
                    printf("Student Record is Empty\n");
                else
                {
                    printf("Enter the student roll no: ");
                    scanf("%d", &roll);
                    for (int i = 0; i < c; i++)
                    {
                        if (s[i].rollNo == roll)
                        {
                            s[i].rollNo = -1;
                        }
                    }
                    dltcountr--;
                }

                break;

            case 5:
                printf("*Thank You*");
                exit(0);
            default:
                printf("Enter correct choice:\n");
                break;
            }
        }
    }
}