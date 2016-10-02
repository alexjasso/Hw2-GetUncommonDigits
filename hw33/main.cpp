/**
 * Program Name: cis25Fal2016AlejandroRHw3Ex1.cpp
 * Discussion:   Homework #2
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
    
    menu03AlejandroRamirez();
    
    return 0;
}


void menu03AlejandroRamirez() {
    int option;
    
    do {
        cout << "\n\n**********************************************"
        "\n*           MENU - Homework #2                 *"
        "\n* (1) Calling extractUncommonDigitAlejandroR() *"
        "\n* (2) Quit                                     *"
        "\n************************************************";
        
        cout << "\nSelect an option (1 or 2): ";
        cin >> option;
        
        switch (option) {
            case 1:
                setUpExtractUncommonDigit();
                
                break;
                
            case 2:
                cout << "\nFun exercise ..." << endl;
                
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
    
    cout << "\nHow many integers? ";
    cin >> size;
    
    dataAry = new int[size];
    
    for (i = 0; i < size; i++) {
        cout << "    Enter integer #" << i + 1 << ": ";
        cin >> *(dataAry + i);
    }
    
    cout << "\nThe original array:";
    for (i = 0; i < size; i++) {
        cout << "\n  " << *(dataAry + i);
    }
    
    cout << "\n\nCalling extractUncommonDigitAlejandroR() -" << endl;
    
    iPtrPtrAry = setUp2D(size);
    
    extractDigitInfo(dataAry, size, iPtrPtrAry);
    
    uncommonAry = extractUncommonDigit(iPtrPtrAry, size);
    
    for (i = 0; i < (*(uncommonAry + 0) * 2 + 1); i++){
        cout << "\n Index: " << i << " is " << *(uncommonAry + i);
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


int** setUp2D(int size) {     //addd a ptrtoptr in arg list
    int** iPtrPtr = nullptr;
    int i;
    
    iPtrPtr = new int*[size];   //iPtrPtr: ptr to #size ptrs to ints
    
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
    int* allDigitOcc = new int[20]();
    int* uncommAry;
    int unDigitCnt = 0;
    int uncommonEvenCnt = 0;
    int uncommonOddCnt = 0;
    int i, j, k;
    
    for (i = 0; i < size; i++) {
        for (j = 0, k = 0; j < 20; j += 2, k++) {
            if (*(*(iPtrPtr + i) + k) > 0) {
                *(allDigitOcc + j) += *(*(iPtrPtr + i) + k);
                *(allDigitOcc + j + 1) = i;
            }
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
    
    for (i = 2, j = (uncommonEvenCnt * 2 + 1); i < 20; i += 4) {
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
