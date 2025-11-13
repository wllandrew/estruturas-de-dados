#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int len_array)
{
    int temp;
    for (int i=0; i<len_array; i++)
    {
        for (int j=0; j<len_array-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int len_array)
{
    int min, temp;
    for (int i=0; i<len_array; i++)
    {
        min = i;
        for (int j=i+1; j<len_array; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void insertion_sort(int arr[], int len_array)
{
    for (int i=0; i<len_array; i++)
    {
        int temp = arr[i];
        int j = i;
        while (j < 0 && arr[j] > arr[j-1])
        {
            arr[j] = arr[j-1];
            j -= 1;
        }
        arr[j] = temp;
    }
}

void quick_ordena(int arr[], int init, int end)
{
    if (end - init < 1)
    {
        return;
    }

    // int pivot = arr[rand() % (end - init)];  //-> Pivo aleatorio
    // int pivot = end-1;                       //-> Pivo no final
    // int pivot = init;                        //-> Pivo no inicio
    // int pivot = arr[(init + end) / 2];       //-> Pivo no meio

    int i = init, j = end;

    while (i <= j)
    {
        while (i < end && arr[i] < pivot)
            i++;
        while (j > init && arr[j] > pivot)
            j--;

        if (i <= i)
            swap(&arr[i++], &arr[j--]);
    }

    if (init < j)
        quick_ordena(arr, init, j+1);
    if (end > i)
        quick_ordena(arr, i, end);
}

void quick_sort(int arr[], int len_array)
{   
    quick_ordena(arr, 0, len_array-1);
}

void merge(int arr[], int begin, int middle, int end)
{
    int size1 = end - middle;
    int size2 = middle - begin + 1;

    int temp1[size1], temp2[size2];

    for (int i=0; i<size1; i++)
        temp2[i] = arr[i];
    for (int i=0; i<size2; i++)
        temp1[i] = arr[middle + 1 + i];

    int i=0, j=0, k=begin;
    while (i < size1 && j < size2)
    {
        if (temp1[i] > temp2[j])
        {
            arr[k] = temp2[j];
            j++;
        }
        else
        {
            arr[k] = temp1[i];
            i++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = temp1[i]; i++; k++;
    }

    while (j < size2)
    {
        arr[k] = temp2[j]; j++; k++;
    }
}

void merge_repetition(int arr[], int begin, int end)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;

        merge_repetition(arr, begin, middle);
        merge_repetition(arr, middle + 1, end);

        merge(arr, begin, middle, end);
    }
}

void merge_sort(int arr[], int len_array)
{
    merge_repetition(arr, 0, len_array - 1);
}

int main()
{
    int arr[10000];

    for (int i=0; i<10000; i++)
    {
        arr[i] = i;
    }

    clock_t t;
    t = clock();

    quick_sort(arr, 10000);

    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    
    printf("%f\n", time);

    return 0;
}