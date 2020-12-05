#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int *a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int *a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int *a, int n);

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int *a, int n);

void GenerateData(int *a, int n, int dataType);

//1
void BubbleSort(int *a, int size);

//2
void SelectionSort(int *a, int size);

//3
void InsertionSort(int *a, int size);

//4
int BinarySearch(int *a, int data, int left, int right);
void BinaryInsertionSort(int *a, int size);

//5
void merge(int *a, int start, int mid, int stop);
void MergeSort(int *a, int start, int stop);

//6
int partition(int *a, int start, int stop);
void QuickSort(int *a, int start, int stop);

//7
int getMax(int *a, int size);
void CountingSort(int *a, int size);

//8
void ShakerSort(int *a, int size);

//9
void ShellSort(int *a, int size);

//10
void Heapify(int *a, int left, int right);
void HeapSort(int *a, int size);

//11
void rsCountingSort(int *a, int size, int exp);
void RadixSort(int *a, int size);

//12
void FlashSort(int *a, int size);
void sorts_experiments();

#endif