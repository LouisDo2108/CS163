#include "sort_header.h"

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
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

void BubbleSort(int *a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = size; j > i; --j)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
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

void SelectionSort(int *a, int size)
{
    int min, minindex;
    for (int i = 0; i < size; ++i)
    {
        min = a[i];
        minindex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (a[j] <= min)
            {
                min = a[j];
                minindex = j;
            }
        }
        a[minindex] = a[i];
        a[i] = min;
    }
}

int BinarySearch(int *a, int data, int left, int right)
{
    if (left >= right)
        return (data <= a[left]) ? (left) : (left + 1);

    int mid = (left + right) / 2;

    if (data == a[mid])
        return mid + 1;

    if (data > a[mid])
        return BinarySearch(a, data, mid + 1, right);

    return BinarySearch(a, data, left, mid - 1);
}

void BinaryInsertionSort(int *a, int size)
{
    int selected, index, loc;

    for (int i = 1; i < size; ++i)
    {
        selected = a[i], index = i - 1;
        loc = BinarySearch(a, selected, 0, index);

        while (index >= loc)
        {
            a[index + 1] = a[index];
            --index;
        }
        a[index + 1] = selected;
    }
}

void ShakerSort(int *a, int size)
{
    bool swapped = true;
    int start = 0, end = size - 1, i;

    while (swapped)
    {
        swapped = false;

        for (i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        --end;

        for (i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void ShellSort(int *a, int size)
{
    for (int gap = (size / 2); gap > 0; gap /= 2)
    {

        for (int i = gap; i < size; ++i)
        {
            int temp = a[i], j;

            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

void Heapify(int *a, int left, int right)
{
    int i = left, j = (i * 2) + 1, x = a[i];
    while (j <= right)
    {
        if (j < right)
        {
            if (a[j] < a[j + 1])
                ++j;
        }
        if (x > a[j])
            break;
        a[i] = a[j];
        i = j;
        j = (i * 2) + 1;
    }
    a[i] = x;
}

void HeapSort(int *a, int size)
{
    int i, right = size - 1, mid = right / 2;
    for (i = mid; i >= 0; --i)
        Heapify(a, i, right);

    while (right > 0)
    {
        swap(a[0], a[right]);
        --right;
        Heapify(a, 0, right);
    }
}

void merge(int *a, int start, int mid, int stop)
{
    int *lst = new int[stop - start];
    int i = start, j = mid, index = 0;

    while (i < mid && j < stop)
    {
        if (a[i] < a[j])
            lst[index++] = a[i++];
        else
            lst[index++] = a[j++];
    }

    while (i < mid)
        lst[index++] = a[i++];

    for (int k = 0; k < index; ++k)
        a[start + k] = lst[k];

    delete[] lst;
}

void MergeSort(int *a, int start, int stop)
{
    if (start >= (stop - 1))
        return;

    int mid = (start + stop) / 2;
    MergeSort(a, start, mid);
    MergeSort(a, mid, stop);
    merge(a, start, mid, stop);
}

int partition(int *a, int start, int stop)
{
    swap(a[start], a[(start + stop) / 2]);
    int pivotValue = a[start], i = start + 1, j = stop;

    while (i <= j)
    {

        while (a[i] < pivotValue && i <= j)
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

int getMax(int *a, int size)
{
    int max = a[0];
    for (int i = 1; i < size; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

void CountingSort(int *a, int size)
{
    int max = getMax(a, size), i;

    int *count = new int[max + 1]{};
    int *output = new int[size];

    for (i = 0; i < size; ++i)
        ++count[a[i]];

    for (i = 1; i <= max; ++i)
        count[i] += count[i - 1];

    for (i = 0; i < size; ++i)
    {
        output[count[a[i]] - 1] = a[i];
        --count[a[i]];
    }

    for (i = 0; i < size; ++i)
        a[i] = output[i];

    delete[] count;
    delete[] output;
}

void rsCountingSort(int *a, int size, int exp)
{
    int *count = new int[10]{}, *output = new int[size], i;

    for (i = 0; i < size; ++i)
        ++count[(a[i] / exp) % 10];

    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (i = 0; i < size; ++i)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        --count[(a[i] / exp) % 10];
    }

    for (i = 0; i < size; ++i)
        a[i] = output[i];

    delete[] count;
    delete[] output;
}

void RadixSort(int *a, int size)
{
    int m = getMax(a, size);

    for (int exp = 1; (m / exp) > 0; exp *= 10)
        rsCountingSort(a, size, exp);
}

void FlashSort(int *a, int size)
{
    const int m = 0.42 * size;
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

void sorts_experiments()
{
    clock_t start, end;
    string data_order[4] = {"Random Order Data", "Sorted Data", "Reversed Data", "Nearly Sorted Data"};
    int data_size[5] = {3000, 10000, 30000, 100000, 300000}, size, *a;
    cout << "Sort experiments measure in seconds" << endl;
    for (int order = 0; order < 4; ++order)
    {
        cout << "------------------------------" << data_order[order] << "------------------------------" << endl;
        cout << "Size                3000          10000         30000         100000        300000";
        cout << endl;

        cout << "Bubble              ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            BubbleSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Shaker              ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            ShakerSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Selection           ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            SelectionSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Insertion           ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            InsertionSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Binary Insertion    ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            BinaryInsertionSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Shell               ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            ShellSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Merge               ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            MergeSort(a, 0, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Quick               ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            QuickSort(a, 0, data_size[size] - 1);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Heap                ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            HeapSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Counting            ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            CountingSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Radix               ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            RadixSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;

        cout << "Flash               ";
        for (size = 0; size < 5; ++size)
        {
            a = new int[data_size[size]];
            GenerateData(a, data_size[size], order);
            start = clock();
            FlashSort(a, data_size[size]);
            end = clock();
            cout << fixed << setprecision(5) << ((double)(end - start)) / double(CLOCKS_PER_SEC) << "       ";
            delete[] a;
        }
        cout << endl;
    }
}