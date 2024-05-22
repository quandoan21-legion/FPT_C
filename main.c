#include <stdio.h>
#include <stdlib.h>

void createArray(int *arrayPointer, int size);
void readArray(int *arrPointer, int size);
int comparator_function(const void *a, const void *b);
int sumOfElementInArr(int *arrPointer, int size);
void insertionSortAscArray(int *arrPointer, int size);
void insertionSortDescArray(int *arrPointer, int size);
void sortArrByOrder(int *arrPointer, int size);
void searchElement(int *arrPointer, int size);

int main(void)
{
    int size, sum;
    printf("Size of your array?\n");
    scanf("%i", &size);
    int arr[size];
    int *arrPointer = arr;
    // Create an array
    createArray(arrPointer, size);

    // Read all elements in side an array
    readArray(arrPointer, size);

    // Calculate the sum of array
    sum = sumOfElementInArr(arrPointer, size);
    printf("The sum of all of your elements is: %i\n", sum);

    // Sort array
    sortArrByOrder(arrPointer, size);
    readArray(arrPointer, size);
    searchElement(arrPointer, size);
}

void sortArrByOrder(int *arrPointer, int size)
{
    // asking the user which order they want their array to be sort
    int sortOrder;
    do
    {
        printf("Which order do you want your array to be sorted?\n");
        printf("1. ASC\n");
        printf("2. DESC\n");
        scanf("%i", &sortOrder);
    } while (sortOrder != 1 && sortOrder != 2);

    if (sortOrder == 1)
    {
        insertionSortAscArray(arrPointer, size);
        return;
    }
    insertionSortDescArray(arrPointer, size);
    return;
}

void insertionSortDescArray(int *arrPointer, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = *(arrPointer + i);
        int j = i - 1;
        while ((j >= 0) && (key > *(arrPointer + j)))
        {
            *(arrPointer + j + 1) = *(arrPointer + j);
            j--;
        }
        *(arrPointer + j + 1) = key;
    }
}

void insertionSortAscArray(int *arrPointer, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = *(arrPointer + i);
        int j = i - 1;
        while ((j >= 0) && (key < *(arrPointer + j)))
        {
            *(arrPointer + j + 1) = *(arrPointer + j);
            j--;
        }
        *(arrPointer + j + 1) = key;
    }
}

void createArray(int *arrayPointer, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Value of No.%i of your array is: ", i + 1);
        scanf("%d", arrayPointer + i);
    }
}

void readArray(int *arrPointer, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(arrPointer + i));
    }
    printf("\n");
}

int comparator_function(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int sumOfElementInArr(int *arrPointer, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *(arrPointer + i);
    }
    return sum;
}

void searchElement(int *arrPointer, int size)
{
    int numb;
    printf("What is the number you want to find ?\n");
    scanf("%d", &numb);
    for (int i = 0; i < size; i++)
    {
        if (*(arrPointer + i) == numb)
        {
            printf("Found\n");
            return;
        }
    }
    printf("Not Found\n");
}