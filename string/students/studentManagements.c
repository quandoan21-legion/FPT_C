#include <stdio.h>

// Declare the default length of student name
const int studentNameLength = 50;
// Declare the default length of student address
const int studentAddressLength = 100;

// Declare Student datatype
typedef struct student
{
    char name[studentNameLength];
    int age;
    char address[studentAddressLength];

} studentInfo;

// Declare function asking user how many student they want to input
void studentQuantity(void);

// Declare a function took the quantity of the students user want to create and crate them
studentInfo *createStudent(int quantity);

// Declare a function that show all of the students in the class
void readStudents(studentInfo student[], int quantity);

int main(void)
{
    studentQuantity();
}

studentInfo *createStudent(int quantity)
{
    studentInfo student[quantity];
    for (int i = 0; i < quantity; i++)
    {
        printf("What is No.%d student's name? ", i + 1);
        scanf("%s", student[i].name);
        printf("What is No.%d student's age? ", i + 1);
        scanf("%d", &student[i].age);
        printf("What is No.%d student's address? ", i + 1);
        scanf("%s", student[i].address);
        printf("----------------------------------------------------------------------------------------------------------\n");
    }

    printf("The total students in your class is: %d\n", quantity);
    printf("----------------------------------------------------------------------------------------------------------\n");
    readStudents(student, quantity);
    return student;
}

void readStudents(studentInfo student[], int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        printf("Name: %s, Age: %d, Address: %s\n", student->name, student->age, student->address);
        printf("----------------------------------------------------------------------------------------------------------\n");
    }
}

void studentQuantity(void)
{
    int studentQuantity = 0;
    printf("How many students do you want to create today?\n");
    scanf("%d", &studentQuantity);
    studentInfo *studentList = createStudent(studentQuantity);
}