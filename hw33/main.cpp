//
//  main.cpp
//  hw33
//
//  Created by Alejandro Ramirez Jasso on 9/26/16.
//  Copyright © 2016 Alejandro Ramirez Jasso. All rights reserved.
//

#include <iostream>
using namespace std;


//void menu3AlejandroRamirez(void):
//int* extractUncommonDigitArrayAlejandroR(int*, int);
int** setUp2D(int);
void extractDigitInfo(int* dataAry, int size, int**);
int* extractUncommonDigit(int**, int);

int main() {
    int** iPtrPtr = nullptr;
    int* dataAry = nullptr;
    int* uncommonAry;
    int size;
    int i, j;
    
    cout << "\nHow many elements? ";
    cin >> size;
    
    dataAry = new int[size];
    for (i = 0; i < size; i++) {
        cout << "\nEnter value for element of index " << i << " : ";
        cin >> *(dataAry + i);
    }
    
    iPtrPtr = setUp2D(size);
    
    extractDigitInfo(dataAry, size, iPtrPtr);
    
    uncommonAry = extractUncommonDigit(iPtrPtr, size);
    
    for (i = 0; i <= *(uncommonAry + 0); i++){
        cout << "\n Index: " << i << " is " << *(uncommonAry + i);
    }
    //for (i = 0; i < size; i++) {
    //    for (j = 0; j < 10; j++) {
    //    cout <<"\nElement of index " << j << " : "
    //    << *(*(iPtrPtr + i) + j) << endl;
    //    }
    //}
    
    return 0;
}

//	void menu3AlejandroRamirez() {}

int* extractUncommonDigit(int** iPtrPtr, int size) {
    int* allDigitOcc = new int[10]();
    int* uncommAry;
    int unDigitCnt = 0;
    int uncommonEvenCnt = 0;
    int uncommonOddCnt = 0;
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < 10; j++) {
            *(allDigitOcc + j) += *(*(iPtrPtr + i) + j);
        }
    }
    
    for (i = 0; i < 10; i++) {
        if (*(allDigitOcc + i) == 1)
            unDigitCnt++;
    }
    
    uncommAry = new int[unDigitCnt * 2 + 1]();
    
    *(uncommAry + 0) = unDigitCnt;
    
    
    for (i = 0, j = 1; i < 10; i += 2) {
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i;
            j++;
            uncommonEvenCnt++;
        }
    }
    
    for (i = 1, j = uncommonEvenCnt + 1; i < 10; i += 2) {
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i;
            j++;
            uncommonOddCnt++;
        }
    }
    
    return uncommAry;
}

void extractDigitInfo(int* dataAry, int size, int** digitInfoAry) {
    int tmp;
    int i, j;
    
    for (i = 0; i < size; i++) {
        tmp = (*(dataAry + i) < 0) ? -(*(dataAry + i)) : *(dataAry + i);
        
        for (j = 0; j < 10; j++) {
            //initialize values at *(*(iPtrPtr + i) + j) to 0
        }
        
        do {
            // TODO's
            *(*(digitInfoAry + i) + tmp % 10) = 1;
            //*(*(digitInfoAry + 0) + tmp % 10) = 1;

            tmp /= 10;
        } while (tmp != 0);
    }
}

int** setUp2D(int size) {
    int** iPtrPtr = nullptr;
    //int size;
    int i;
             
    //1.cout << "\nHow many int's? ";
    //1.cin >> size;
    
    iPtrPtr = new int*[size];   //iPtrPtr: ptr to #size ptrs to ints
    
    //2.iPtrPtr = new int*[1];
    //2.*(iPtrPtr + 0) = new int[10]();
    
    for (i = 0; i <size; i++) {
        *(iPtrPtr + i) = new int[10]();
    }
             
    return iPtrPtr;
}
