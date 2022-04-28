#include <stdlib.h>
#include <stdio.h>
int n = 3, a[100];
void PrintSolution(int a[100]){
    int i = 0;
    for(i = 1; i <= n; i++){
        printf("%d", a[i]);
    };
    printf("\n");
};

int check(int i, int k){
    if(a[k-1] + i <= 1) return 1;
    return 0;
}

void Backtracking(int k){
    int i;
    for(i = 0; i < 2; i++){     
        if(check(i, k)){
            a[k] = i;
            if(k == n){
                PrintSolution(a);
            }else {
                Backtracking(k + 1);
            }
        }
    };
}

int main(){
    Backtracking(1);
}