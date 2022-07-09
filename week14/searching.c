#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input[100000];

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MAX_HEAPIFY(int A[], int i, int n){
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    int largest = i;
    if(leftChild < n && A[leftChild] > A[i]){ // Ai have leftChild
        largest = leftChild;
    }
    if(rightChild < n && A[rightChild] > A[largest]) largest = rightChild;
    if(largest != i){
        swap(&A[i], &A[largest]);
        MAX_HEAPIFY(A, largest , n);
    }
}

void buildMaxHeap(int A[], int n){
    for(int i = n/2 -1; i >= 0; i--){
        MAX_HEAPIFY(A, i, n);
    }
}


void heapSort(int A[], int size){
    buildMaxHeap(A, size);
    for(int i = size - 1; i >= 1; i--){
        swap(&A[0], &A[i]);
        MAX_HEAPIFY(A, 0 ,i);
    }
}

int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}

int inputGenerator(){
    srand(time(NULL));
    int max = 100000;
    int min = 0;
    for(int i = 0 ; i < 1000; i++){
        input[i] = rand() % (max - min + 1) + min;
    }
}

void brute_force(int *a,int n,int q){
    int count = 0;
    for(int i=0;i<n-1;i++)
        for(int j = i+1;j<n;j++)
            if(a[i] + a[j] == q) count++;
    printf("Count: %d",count);
}

void timeWait (float threshold) {
    float timeInitial, timeMeasured, timeDelta = 0;

    timeInitial = (float)clock();
    while (timeDelta < threshold) {
        timeMeasured = (float)clock();
        timeDelta = ((timeMeasured - timeInitial) / (float)CLOCKS_PER_SEC);
    }
    printf("%.2f - %.2f s have passed.", threshold, timeDelta);
}

void use_binary_search(int *a,int n,int q){
    int count = 0;
    qsort(a,n,sizeof(int),cmp);
    // for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++){
        if(a[i] > q/2) break;
        int aj = q-a[i];
        if(bsearch(&aj,a,n,sizeof(int),cmp)) count++;
    }
    printf("Count: %d",count);
}

int readFile(){
    FILE *file = fopen("test100K_binarySearch.txt", "r");
    int size; 
    fscanf(file,"%d",&size);
    printf("size: %d\n",size);
    for(int i = 0; i < size; i++){
        fscanf(file, "%d", &input[i]);
        printf("input: %d", input[i]);
    }
}

int main(){
    int size = 100000;
    int sum = 10;
    clock_t start_t, end_t;
    double total_t;
    int i;
    // inputGenerator();
    readFile();
    start_t = clock();
    brute_force(input,size,sum);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTime for brute force: %f\n", total_t  );
    start_t = clock();
    use_binary_search(input,size,sum);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTime for binary search: %f\n", total_t  );

}
