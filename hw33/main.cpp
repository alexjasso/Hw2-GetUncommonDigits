/**
 * Program Name: cis25Fal2016AlejandroRHw3Ex1.cpp
 * Discussion:   Homework #3
 * Written By:   Alejandro R
 * Due Date:     2016/10/04
 */

#include <iostream>
using namespace std;

void menu03AlejandroRamirez(void);
void setUpExtractUncommonDigit(void);
int** setUp2D(int);
void extractDigitInfo(int* dataAry, int size, int**);
int* extractUncommonDigit(int**, int);

int main() {
    
    cout << "CIS 25 - C++ Programming\n"
        "Laney College\n"
        "Alejandro R\n\n"
    
        "Assignment Information --\n"
        "  Assignment Number:  Homework #3\n"
        "                      Coding Assignment -- Exercise #1\n"
        "  Written by:         Alejandro R\n"
        "  Submitted Date:     2016/10/04\n";
    
    menu03AlejandroRamirez();
    
    return 0;
}


void menu03AlejandroRamirez() {
    int option;
    
    do {
        cout << "\n\n************************************************"
            "\n*           MENU - Homework #3                 *"
            "\n* 1. Calling extractUncommonDigitAlejandroR()  *"
            "\n* 2. Quit                                      *"
            "\n************************************************";
        
        cout << "\nSelect an option (1 or 2): ";
        cin >> option;
        
        switch (option) {
            case 1:
                setUpExtractUncommonDigit();
                
                break;
                
            case 2:
                cout << "\n  Fun exercise ..." << endl;
                
                break;
                
            default:
                cout << "\n  WRONG OPTION!\n";
        }
        
    } while (option != 2);
}

void setUpExtractUncommonDigit() {
    int size;
    int* dataAry = nullptr;
    int** iPtrPtrAry = nullptr;
    int* uncommonAry = nullptr;
    int i;
    
    cout << "\n  How many integers? ";
    cin >> size;
    
    dataAry = new int[size];
    
    for (i = 0; i < size; i++) {
        cout << "    Enter integer #" << i << ": ";
        cin >> *(dataAry + i);
    }
    
    cout << "\n  The original array:";
    for (i = 0; i < size; i++) {
        cout << "\n    " << *(dataAry + i);
    }
    
    cout << "\n\nCalling extractUncommonDigitAlejandroR() -";
    
    iPtrPtrAry = setUp2D(size);
    
    extractDigitInfo(dataAry, size, iPtrPtrAry);
    
    uncommonAry = extractUncommonDigit(iPtrPtrAry, size);
    
    cout << "\n\nDisplaying after returning the array -- "
        "The Uncommon Digits:"
        "\n  There is/are " << *(uncommonAry + 0) <<
        " uncommon digit(s)\n";
    
    for (i = 1; i < (*(uncommonAry + 0) * 2 + 1); i += 2){
        cout << "    {" << *(uncommonAry + i) << "," <<
            *(uncommonAry + i + 1) << "}" << endl;
    }
    
    delete[] dataAry;
    dataAry = nullptr;
    
    for (i = 0; i < size; i++) {
        delete[] *(iPtrPtrAry + i);
        *(iPtrPtrAry + i) = nullptr;
    }
    delete[] iPtrPtrAry;
    iPtrPtrAry = nullptr;
    
    delete[] uncommonAry;
    uncommonAry = nullptr;
}


int** setUp2D(int size) {
    int** iPtrPtr = nullptr;
    int i;
    
    iPtrPtr = new int*[size];
    
    for (i = 0; i <size; i++) {
        *(iPtrPtr + i) = new int[10]();
    }
    
    return iPtrPtr;
}

void extractDigitInfo(int* dataAry, int size, int** digitInfoAry) {
    int tmp;
    int i;
    
    for (i = 0; i < size; i++) {
        tmp = (*(dataAry + i) < 0) ? -(*(dataAry + i)) : *(dataAry + i);
        
        do {
            *(*(digitInfoAry + i) + tmp % 10) = 1;
            
            tmp /= 10;
        } while (tmp != 0);
    }
}

int* extractUncommonDigit(int** iPtrPtr, int size) {
    int* allDigitOcc = new int[20](); //
    int* uncommAry;
    int uncDigitCnt = 0;
    int uncommonEvenCnt = 0;
    //int uncommonOddCnt = 0;
    int i, j, k;
    
    for (i = 0; i < size; i++) {
        for (j = 0, k = 0; j < 10 || k < 20; j ++, k += 2) {
            if (*(*(iPtrPtr + i) + j) > 0) {
                *(allDigitOcc + k) += *(*(iPtrPtr + i) + j); // Adds & stores occurrences
                                                             // of each digit in all the ints.
                *(allDigitOcc + k + 1) = i; // Stores index in which the digit last occurres
            }                               // in the next member of the array.
        }
    }
    
    for (i = 0; i < 20; i += 2) {
        if (*(allDigitOcc + i) == 1)
            uncDigitCnt++; // Counts and stores # of occurred uncommon digits.
    }
    
    uncommAry = new int[uncDigitCnt * 2 + 1]();
    
    *(uncommAry + 0) = uncDigitCnt;
    
    
    for (i = 0, j = 1; i < 20; i += 4) { // Even uncommon digits.
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i / 2; // i/2 gives digit to be worked with
            j++;
            *(uncommAry + j) = *(allDigitOcc + i + 1);
            j++;
            uncommonEvenCnt++;
        }
    }
    
    for (i = 2, j = (uncommonEvenCnt * 2 + 1); i < 20; i += 4) { // Odd digits uncommon digits.
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i / 2;
            j++;
            *(uncommAry + j) = *(allDigitOcc + i + 1);
            j++;
        }
    }
    
    return uncommAry;
}

/* Program Output
 CIS 25 - C++ Programming
 Laney College
 Alejandro R
 
 Assignment Information --
   Assignment Number:  Homework #3
                       Coding Assignment -- Exercise #1
   Written by:         Alejandro R
   Submitted Date:     2016/10/04
 
 
 ************************************************
 *           MENU - Homework #3                 *
 * 1. Calling extractUncommonDigitAlejandroR()  *
 * 2. Quit                                      *
 ************************************************
 Select an option (1 or 2): 4
 
   WRONG OPTION!
 
 
 ************************************************
 *           MENU - Homework #3                 *
 * 1. Calling extractUncommonDigitAlejandroR()  *
 * 2. Quit                                      *
 ************************************************
 Select an option (1 or 2): 1
 
   How many integers? 3
     Enter integer #0: 32965
     Enter integer #1: -275721
     Enter integer #2: 3028063
 
   The original array:
     32965
     -275721
     3028063
 
 Calling extractUncommonDigitAlejandroR() -
 
 Displaying after returning the array -- The Uncommon Digits:
   There is/are 5 uncommon digit(s)
     {0,2}
     {8,2}
     {1,1}
     {7,1}
     {9,0}
 
 
 ************************************************
 *           MENU - Homework #3                 *
 * 1. Calling extractUncommonDigitAlejandroR()  *
 * 2. Quit                                      *
 ************************************************
 Select an option (1 or 2): 1
 
   How many integers? 4
     Enter integer #0: 32965
     Enter integer #1: -275721
     Enter integer #2: 3028063
     Enter integer #3: 10789
 
 The original array:
   32965
   -275721
   3028063
   10789
 
 Calling extractUncommonDigitAlejandroR() -
 
 Displaying after returning the array -- The Uncommon Digits:
   There is/are 0 uncommon digit(s)
 
 
 ************************************************
 *           MENU - Homework #3                 *
 * 1. Calling extractUncommonDigitAlejandroR()  *
 * 2. Quit                                      *
 ************************************************
 Select an option (1 or 2): 2
 
   Fun exercise ...
 */

/* Comments
 
 */
