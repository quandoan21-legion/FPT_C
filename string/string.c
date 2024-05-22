#include <stdio.h>
#include <string.h>

int strSize = 20;
int arrSize = 5;

void createArrayElement(char arrPointer[][strSize], int size);
void readArray(char arrPointer[][strSize], int size);
void sortArray(char arrPointer[][strSize], int size);

int main(void)
{
    printf("How many element inside your array?\nDefault: 5\n");
    scanf("%d", &arrSize);
    printf("The size of string in your array?\nDefault: 20\n");
    scanf("%d", &strSize);
    getchar();
    char arrPointer[arrSize][strSize];
    createArrayElement(arrPointer, arrSize);
    // readArray(arrPointer, arrSize);
    sortArray(arrPointer, arrSize);
    readArray(arrPointer, arrSize);
}

void createArrayElement(char arrPointer[][strSize], int size)
{
    char str[strSize];
    for (int i = 0; i < size; i++)
    {
        printf("Your No.%d string is?\n", i + 1);
        fgets(str, strSize, stdin);
        printf("You entered: %s\n", str);
        strcpy(arrPointer[i], str);
    }
}

void readArray(char arrPointer[][strSize], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("The No.%d in array is: %s\n", i + 1, arrPointer[i]);
    }
}

void sortArray(char arrPointer[][strSize], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (strlen(arrPointer[i]) < strlen(arrPointer[j])))
        {
            strcpy(arrPointer[j], arrPointer[j + 1]);
            j--;
        }
        strcpy(arrPointer[j + 1], arrPointer[i]);
    }
}