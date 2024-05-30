#include <stdio.h>
#include <stdlib.h>

// Prototypes of function will be call upon below
int elementQuantity(void);
void addElementInArray(float *pointer, int quantity);
void findSmallestElementInArray(float *pointer, int quantity);

int main(void)
{
    int quantity = elementQuantity();
    float array[quantity];
    addElementInArray(array, quantity);
    findSmallestElementInArray(array, quantity);
}

int elementQuantity(void)
{
    int quantity = 0;
    while (quantity < 1)
    {
        printf("How many numbers do you want to add in your array? ");
        scanf("%d", &quantity);
        printf("-------------------------------\n");
    }
    return quantity;
}

void addElementInArray(float *pointer, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        printf("What is your No.%d element value ?\n", i + 1);
        printf("Value: ");
        scanf("%f", &pointer[i]);
        printf("-------------------------------\n");
    }
}

void findSmallestElementInArray(float *pointer, int quantity)
{
    float smallest = pointer[0];       // Initialize with the first element
    for (int i = 1; i < quantity; i++) // Start from the second element
    {
        if (pointer[i] < smallest)
        {
            smallest = pointer[i];
        }
    }
    printf("The smallest number in array is: %f\n", smallest);
}
