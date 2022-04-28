#include <stdio.h>
#include <stdlib.h>
int a[100], n, m;
void PrintSolution(int a[100]){
    int i = 0;
    for(i = 1; i <= n; i++){
        printf("%d ", a[i]);
    };
    printf("\n");
};

int check(int i, int k){ // true when i != every a1,a2,a3,...,a[k-1]
    printf("check i from a[0] to a[%d]\n", k);
    for(int j = 0; j <= k-1; j++){
        if(i == a[j]){
            return 0;
        } 
    }
    return 1;

}

void Try(int k){ //Sk = {1,2,3,...,n} \ {a1, a2, ..., a[k-1]}
    for(int i = 0; i <= n; i++){
        if(check(i, k)){ // true when i != every a1,a2,a3,...,a[k-1]
            a[k] = i;
            if(k == n) PrintSolution(a);
            else Try(k+1);
        }
    }
}

int main(){
    n = 3;
    // a[0] = 0
    Try(1);
}