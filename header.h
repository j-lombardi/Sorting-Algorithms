#pragma once

using namespace std;

template <class T>
void bubbleSort(T list[], int size);

template <class T>
void insertionSort(T list[], int size);

template <class T>
void selectionSort(T list[], int size);

template <class T>
void shellSort(T list[], int size);

template <class T>
void mergeSort(T list[], int lb, int ub);

template <class T>
void merge(T list[], int lb, int mid, int ub);

template<class T>
void printArray(T list[], int size);

template <class T>
void quickSort(T list[], int lb, int ub);
