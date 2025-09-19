#include <stdio.h>

const int LEN = 6;
int main(void){
    int arr[LEN] = {107, 6, 8, 15, 23, 18};
    int pairInd = 0;
    int sizeOfPair = 1;

    while(pairInd < LEN){
        int indElem = 0;
        while(indElem < sizeOfPair){
            if(arr[pairInd + indElem] > arr[pairInd + indElem + 1]){
                int temp = arr[pairInd + indElem];
                arr[pairInd + indElem] = arr[pairInd + indElem + 1];
                arr[pairInd + indElem + 1] = temp;
            }
        }

        pairInd += 2;
    }

    for(int i = 0; i < LEN; i++){
        printf("%d\n", arr[i]);
    }
    
    
    
}

