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
    
    for (i = 0; i <= *(uncommonAry + 0) * 2 + 1; i++){
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
    int* allDigitOcc = new int[20]();
    int* uncommAry;
    int unDigitCnt = 0;
    int uncommonEvenCnt = 0;
    int uncommonOddCnt = 0;
    int i, j, k;
    
    for (i = 0; i < size; i++) {
        for (j = 0, k = 0; j < 20; j += 2, k++) {
            *(allDigitOcc + j) += *(*(iPtrPtr + i) + k);
            *(allDigitOcc + j + 1) = i;
        }
    }
    
    for (i = 0; i < 20; i += 2) {
        if (*(allDigitOcc + i) == 1)
            unDigitCnt++;
    }
    
    uncommAry = new int[unDigitCnt * 2 + 1]();
    
    *(uncommAry + 0) = unDigitCnt;
    
    
    for (i = 0, j = 1; i < 20; i += 4) {
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i/2;
            j++;
            *(uncommAry + j) = *(allDigitOcc + i + 1);
            j++;
            uncommonEvenCnt++;
        }
    }
    
    for (i = 2, j = uncommonEvenCnt + 1; i < 20; i += 4) {
        if (*(allDigitOcc + i) == 1){
            *(uncommAry + j) = i/2;
            j++;
            *(uncommAry + j) = *(allDigitOcc + i + 1);
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
        
        do {
            *(*(digitInfoAry + i) + tmp % 10) = 1;

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
    
    for (i = 0; i <size; i++) {
        *(iPtrPtr + i) = new int[10]();
    }
             
    return iPtrPtr;
}
