#include <iostream>
#include <time.h>

using namespace std;
void GenerateRandomData(int *a, int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        swap(a[r1], a[r2]);
    }
}

void GenerateData(int *a, int n, int dataType)
{
    switch (dataType)
    {
    case 0: // ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1: // có thứ tự
        GenerateSortedData(a, n);
        break;
    case 2: // có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    case 3: // gần như có thứ tự
        GenerateNearlySortedData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}

void InsertionSort(int *a, int size)
{
    int selected, index;
    for (int i = 1; i < size; ++i)
    {
        selected = a[i], index = i - 1;
        while (a[index] >= selected && index >= 0)
        {
            a[index + 1] = a[index];
            --index;
        }
        a[index + 1] = selected;
    }
}

int partition(int *a, int start, int stop)
{
    swap(a[start], a[(start + stop) / 2]);
    int pivotValue = a[start], i = start + 1, j = stop;

    while (i <= j)
    {
        while (a[i] < pivotValue)
            ++i;

        while (a[j] > pivotValue)
            --j;

        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    swap(a[start], a[j]);
    return j;
}

void QuickSort(int *a, int start, int stop)
{
    if (start >= stop)
        return;
    int pivotindex = partition(a, start, stop);
    QuickSort(a, start, pivotindex - 1);
    QuickSort(a, pivotindex + 1, stop);
}

void flash_sort(int *a, int size)
{
    double result;
    const int m = 1000;
    int max = a[0], min = a[0], i, j, k;
    int count[m]{}, count_copy[m]{};
    int **classify_arr = new int *[m];

    //Find min max of the array

    for (i = 1; i < size; ++i)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    //Classification

    for (i = 0; i < size; ++i)
    {
        j = (m - 1) * ((float)(a[i] - min) / (max - min));
        //cout << j << " ";
        ++count[j];
        ++count_copy[j];
    }

    for (i = 0; i < m; ++i)
        classify_arr[i] = new int[count[i]];

    //Put array value into corresponding class
    for (i = 0; i < size; ++i)
    {
        j = (m - 1) * ((float)(a[i] - min) / (max - min));
        classify_arr[j][--count_copy[j]] = a[i];
    }

    for (i = 0; i < m; ++i)
        InsertionSort(classify_arr[i], count[i]);

    k = 0;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < count[i]; ++j)
            a[k++] = classify_arr[i][j];
    }

    for (i = 0; i < m; ++i)
        delete[] classify_arr[i];

    delete[] classify_arr;
    return;
}

int main()
{
    int size = 10000;
    int *a = new int[size];
    GenerateData(a, size, 0);
    flash_sort(a, size);
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    delete[] a;
    return 0;
}