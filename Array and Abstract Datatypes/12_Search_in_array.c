// linear search is big O of N
// binary search is big O of log(N)

#include <stdio.h>
#include <windows.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        printf("Test case %d \n", i);
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    // start searching
    int i = 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("Test case %d \n", i++);
        if (arr[low] == element)
            return low;
        else if (arr[high] == element)
            return high;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            low = mid + 1;
        else if (arr[mid] > element)
            high = mid - 1;
    }

    // search ends
    return -1;
}

int main()
{
    system("cls");

    // int arr[] = {1, 3, 5, 8, 44, 55, 48, 75, 1465, 546, 5588, 4};  //for linear search
    int arr[] = {5, 8, 12, 17, 22, 25, 26, 28, 32, 34, 38, 48, 55, 56, 59, 71, 72, 74, 80, 89, 91, 102, 116, 123, 124, 132, 148, 149, 152, 153, 161, 163, 168, 173, 176, 178, 192, 198, 199, 200, 202, 212, 214, 220, 228, 229, 233, 238, 254, 257, 279, 287, 288, 290, 295, 296, 309, 312, 327, 335, 343, 344, 360, 361, 373, 387, 391, 393, 396, 397, 399, 412, 414, 418, 423, 424, 431, 437, 438, 450, 451, 458, 460, 477, 479, 480, 481, 485, 489, 509, 512, 515, 519, 527, 528, 532, 533, 534, 545, 552};
    int size = sizeof(arr) / sizeof(int);
    int element = 123;
    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d was found at index %d that have size %d \n", element, searchIndex, size);
    searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d that have size %d \n", element, searchIndex, size);

    return 0;
}
