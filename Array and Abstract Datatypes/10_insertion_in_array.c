#include <stdio.h>
#include <windows.h>
#define CAP 100

// Code for index Insertion
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;

    return 1;
}

// code for Traversal
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    system("cls");
    int arr[CAP] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    display(arr, size);
    int message = indInsertion(arr, size, element, CAP, index);
    if (message == 1)
    {
        size += 1;
        printf("Successfully Inserted\n");
        display(arr, size);
    }

    return 0;
}