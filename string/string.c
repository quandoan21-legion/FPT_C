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
    readArray(arrPointer, arrSize);
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
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(arrPointer[j], arrPointer[j + 1]) > 0)
            {
                char tmp[strSize];
                strcpy(tmp, arrPointer[j]);
                strcpy(arrPointer[j], arrPointer[j + 1]);
                strcpy(arrPointer[j + 1], tmp);
            }
        }
    }
    printf("Array Sorted!\n");
}
