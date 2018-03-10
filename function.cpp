/*Author: Your-Name
Class: CSI-281-04
Assignment: PA 3
Date Assigned: 9/12/17
Due Date: 9/29/17 11:00am
Description:
This program has several different sorting arrays that will be able to sort arrays of any type of data
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)*/

#include "header.h"
#include <iostream>
#include <limits>

using namespace std;

// PURPOSE: This function will simply swap two numbers
// PRE:     Two values
// POST:    The values will be swapped
template<class T>
void mySwap(T &x, T &y) {

    T temp = x;
    x = y;
    y = temp;

}

// PURPOSE: Print array will simply print out the contents of an array in a easily readable way
// PRE:     An array, and the size of the array
// POST:    The array will be printed in a human readable way
template<class T>
void printArray(T list[], int size) {

    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            cout << list[i];
        else
            cout << list[i] << ", ";
    }

}

// PURPOSE: Bubble sort will sort out the elements of an array by checking number by number and switching the smaller to the left
// PRE:     An array full of data, and the size of the array
// POST:    The given array will be sorted afterwards
template<class T>
void bubbleSort(T list[], int size) {

    bool swapped = true;
    int counter = 0;

    while (swapped) {
        swapped = false;
        counter++;
        for (int i = 0; i < size - counter; i++) {
            if (list[i] > list[i + 1]) {
                mySwap(list[i], list[i + 1]);
                swapped = true;
            }
        }
    }


}

// PURPOSE: Insertion sort will search through the array, find the smallest number, and move it to the front of the array, sorting it
// PRE:     An array full of data, and the size of the array
// POST:    The array will be sorted afterwards
template<class T>
void insertionSort(T list[], int size) {


    for (int i = 1; i < size; i++) {

        int value = list[i];
        int swapNum = i - 1;

        while (swapNum >= 0 && list[swapNum] > value) {
            list[swapNum + 1] = list[swapNum];
            swapNum--;
        }

        list[swapNum + 1] = value;
    }

    //cout << "After insertion sort: " << endl;

}
// PURPOSE: Selection sort handles the unordered portion of the list, and with each pass through will shrink the unordered portion by 1
//          by finding the smallest element in the remaining array and moving it to the front
// PRE:     A data filled arrray, and the size of the array
// POST:    All the data in the array will be sorted
template<class T>
void selectionSort(T list[], int size) {

    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[minIndex])
                minIndex = j;
        }

        if (list[minIndex] != i)
            mySwap(list[i], list[minIndex]);
    }


}

// PURPOSE: Merge is used by mergeSort to recombine the arrays into one sorted array
// PRE:     An array full of data, the upper and lower bounds, along with the mid point of the array
// POST:    Afterwards the information will be sorted back into its array
template<class T>
void merge(T list[], int lb, int mid, int ub) {
    //create sizes for arrays
    int size1 = mid - lb + 1;
    int size2 = ub - mid;

    //create temp arrays 
    T* temp1 = new T[size1 + 1];
    T* temp2 = new T[size2 + 1];

    //filling arrays with their data
    for (int i = 0; i < size1; i++)
        temp1[i] = list[lb + i];
    for (int j = 0; j < size2; j++)
        temp2[j] = list[mid + j + 1];

    //setting indexs back to 0
    int i = 0;
    int j = 0;

    //sorting the information of the lists into one
    for (int k = lb; k < ub; k++) {
        if (temp1[i] <= temp2[j]) {
            if (i != size1) {
                list[k] = temp1[i];
                i++;
            }
        }
        else {
            if (j != size2) {
                list[k] = temp2[j];
                j++;
            }
        }
    }
}

// PURPOSE: Merge sort will break the array into multiple smaller arrays and order the information from the smaller arrays back into the main array
// PRE:     An array of data, and the upper and lower bounds
// POST:    The array will be sorted afterwards
template<class T>
void mergeSort(T list[], int lb, int ub) {

    int mid = (lb + ub) / 2;

    if (lb < ub) {
        mergeSort(list, lb, mid);
        mergeSort(list, mid + 1, ub);

        merge(list, lb, mid, ub);
    }


}
//PURPOSE:  Shell sort will break up the list into many smaller sublists and then sort the sublists
//PRE:      A data filled array, and the size of the array
//POST:     The information in the array will be sorted
template <class T>
void shellSort(T list[], int size) {

    int gap = size / 2;

    while (gap > 0) {
        for (int i = 0; i < size - gap; i++) {
            int j = i + gap;
            T temp = list[j];

            while (j >= gap && temp < list[j - gap]) {
                list[j] = list[j - gap];
                j = j - gap;
            }
            list[j] = temp;
        }

        gap = gap / 2;
    }


}

// PURPOSE: Quick sort will create a pivot and sort information arround the pivot, fuilly sorting an array
// PRE:     A data filled array, along with the lower bound and the upper bound of the array
// POST:    The array will be sorted
template <class T>
void quickSort(T list[], int lb, int ub) {

    //Creating the numbers to handle moving in the array and the pivot point
    int i = lb, j = ub;
    T pivot = list[ (ub + lb) / 2];

    //Partition
    while ( i <= j ) {
        while(list[i] < pivot)
            i++;
        while(list[j] > pivot)
            j--;

        if ( i <= j ) {
            mySwap(list[i], list[j]);
            i++;
            j--;
        }
    }

    //recursivly sorting the array
    if(lb < j)
        quickSort(list, lb, j);
    if(ub > i)
        quickSort(list, i, ub);

}