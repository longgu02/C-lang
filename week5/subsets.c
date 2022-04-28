#include <stdio.h>
#include <stdlib.h>
int a[100], n, m;
void PrintSolution(int a[100]){
    int i = 0;
    for(i = 1; i <= m; i++){
        printf("%d ", a[i]);
    };
    printf("\n");
};

void Try(int k){ //Sk = {a[k-1] + 1, a[k - 1] + 2,... n - m +k} -> {1,2,3,..., n - m + k}
    for(int i = a[k-1] +1; i <= n-m+k; i++){
        a[k] = i;
        if(k == m) PrintSolution(a);
        else Try(k+1);
    }
}

int main(){
    n =5; m =3;
    // a[0] = 0
    Try(1);
}