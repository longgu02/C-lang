#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*void insertionSort(int a[], int size){
    //Insertion sort iterates, consuming one input element each repetition, and grows a sorted output list
    int j, temp;
    for(int i=1; i< size; i++){
        //find corret place for a[i]
        temp = a[i];
        j = i-1;
        while(j >= 0 && a[j]> temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}*/

/*void selectionSort(int a[], int size){
    //sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning
    for(int i =0; i< size-1; i++){
        int idx = i;
        for(int j=i+1; j< size; j++){
            if(a[j] < a[idx]) idx =j;
            swap(&a[i], &a[idx]);
        }
    }
}*/

/*void bubbleSort(int a[], int size){
    //repeatedly swapping the adjacent elements if they are in the wrong order
    int sorted;
    for(int i=0; i< size-1; i++){
        sorted =1;
        for (int j =0; j< size-i -1 ; j++){
            if(a[j]> a[j+1]) {
                swap(&a[j], &a[j+1]);
                sorted =0;
            }
        }
        if(sorted == 1 ) break;
    }
}*/

//divide and conquer
void merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;//array 1
    int n2 = r - m; //array 2

    int L[n1], R[n2];
 
    // Copy
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[]
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[]
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r){
    if (l < r) {
        //middle
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        //combine
        merge(a, l, m, r);
    }
}

int partition(int A[], int low, int high){
	//Select A[low] as the pivot
	int pivot = A[low];
	int i = low +1, j = high;
	while(i<= j){
		while(i<= high && A[i] < pivot ) i++;
		while(j >= low && A[j] > pivot) j--;
		if(i < j) {
			swap(&A[i], &A[j]);
			i++;
			j--;
		}
		else break;
	}
	swap(&A[low], &A[j]);
	return j;
}

int partitionLast (int arr[], int low, int high)
{
    int pivot = arr[high];  
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionMid(int A[], int left, int right){
      int i = left, j = right;
      int tmp;
      int pivot = A[(left + right) / 2];
      while (i <= j) {
            while (A[i] < pivot)
                  i++;
            while (A[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = A[i];
                  A[i] = A[j];
                  A[j] = tmp;
                  i++;
                  j--;
            }
      };
      return i;
}

void quickSort(int A[], int low, int high){
	if(low < high){
		int indexPivot = partition(A, low, high);
		quickSort(A, low, indexPivot -1);
		quickSort(A, indexPivot+1, high);
	}
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

int main(){
	int i;
    int a[]={23, 78, 45, 8, 32, 56};
    int size = sizeof(a)/ sizeof(a[0]);

    //insertionSort(a, size);
    //selectionSort(a, size);
    //bubbleSort(a, size);
    //mergeSort(a, 0, size-1);
    // quickSort(a, 0, 5 );
    heapSort(a, 5);
    for( i=0; i< 6; i++){
    	printf("%d ", a[i]);
	}
        
}
