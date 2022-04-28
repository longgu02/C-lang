#include <stdlib.h>
#include <stdio.h>

int binarySearch(int low, int high, int S[], int key){
    if(low < high){
        int mid = (low + high) / 2;
        if(S[mid] == key){
            return mid;
        }else if(key < S[mid]){
            return binarySearch(low, mid - 1, S, key);
        }else{
            return binarySearch(mid + 1, high, S, key);
        }
    }
    else return -1;
}

int main(){
    int S[10] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = 8, key = 4;
    int result = binarySearch(0,n,S,key);
    if(result == -1) printf("Value not found");
    else printf("Value found at index %d",result);
}