#include <stdio.h>
int M, N;
int coef[100];
int tmpSum;
int solution[100];

void print() {
    int i = 0;
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%d ", solution[i]);
    }   
}

void try (int k) {
    int i = 0;
    for (i = 0; i <= tmpSum / coef[k]; i++) {
        solution[k] = i;
        tmpSum -= i * coef[k];
        if (k == N-1) {
            if (tmpSum == 0) {
                print();
            }
        } else {
            try(k + 1);
        }
        tmpSum += i * coef[k];
    }
}

int main() {
    scanf("%d %d", &M, &N);
    tmpSum = M;
    int i;
    for(i=0; i < N; i++) {
        scanf("%d", &coef[i]);
    }
    try(0);
    return 0;
}