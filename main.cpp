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
#include "function.cpp"
#include "timerSystem.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 10000;                      //int for controlling array size
const int MIN_LETTER = 97, MAX_LETTER = 122;    //ints for creating a random letter between a and z (lower case only)
const int MIN_NUM = 0, MAX_NUM = 100000;        //ints for creating a random number between 0 and 100000

int main() {

    //padding all the number outputs to 9 decimal points
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(9);

    ofstream output;
    ifstream input;

    int myArray[ARRAY_SIZE];
    string help;

    output.open("10000sorted.txt");
    input.open("10000random.txt");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        getline(input, help);
        myArray[i] = stoi(help);
    }

    shellSort(myArray, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        output << myArray[i] << endl;
    }
    

    /*srand(5);

    TimerSystem timer; //timer for seeing how long each algorithm takes

    
    int intArray[ARRAY_SIZE];

    //Filling array with random numbers between 0 and 100000
    for (int i = 0; i < ARRAY_SIZE; i++)
        intArray[i] = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

    cout << endl;

    timer.startClock();
    quickSort(intArray, 0, (ARRAY_SIZE - 1));

    cout << timer.getTime() << " seconds \n";

    cout << endl;*/

    system("pause");
}