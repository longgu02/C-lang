#include <stdlib.h>
#include <stdio.h>

int size;

int Product(int list[], int k){
    if(k == size - 1) return list[k];
    return list[k]*Product(list, k + 1);
}

int main(){
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int A[size];
    for(int i = 0; i < size; i++){
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int result = Product(A, 2);
    printf("Product of A is %d\n", result);
    return 0;
}