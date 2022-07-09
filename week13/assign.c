#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char firstN[100][10];
char middleN[100][10];
char lastN[100][10];
int date[100], month[100], year[100];

void genData(char* filename){

    FILE* f = fopen(filename, "w");

    srand(time(NULL));

    int i=0;

    while(1){

        i++;

        printf("The student %d: \n", i);

        char fullname[100];

        printf(" - Enter fullname: ");

        gets(fullname);

        fflush(stdin);

        if(strcmp(fullname,"#")==0) break;

        char s[5];

        int year = 1999+ rand()%5;

        int m = rand()%12+1;

        int d= rand()%28+1;

        sprintf(s, "%d-%d%d-%d%d", year, m/10, m%10, d/10, d%10);

        printf(" - Create random birthdate : %s\n", s);

        fprintf(f, "%s\n", fullname);

        fprintf(f,"%s\n", s);

    }

    fprintf(f, "#");

};

void nameSep(char *filename){
    int i = 0;
    FILE *file = fopen(filename,"r");
    while(1){
        fscanf(file, "%s %s %s", firstN[i], middleN[i], lastN[i]);
        if(strcmp(firstN[i], "#") == 0) break;
        fscanf(file, "%d-%d-%d", &year[i], &month[i], &date[i]);
        printf("%s %s %s\n", firstN[i], middleN[i], lastN[i]);
        printf("%d %d %d\n", year[i], month[i], date[i]);
        i++;
    }
}

int compareData(int id1, int id2){
    if(strcmp(firstN[id1], firstN[id2]) == 0){
        if(strcmp(middleN[id1], middleN[id2]) == 0){
            if(strcmp(lastN[id1], lastN[id2]) == 0){
                if(year[id1] == year[id2]){
                    if(month[id1] == month[id2]){
                        if(date[id1] == date[id2]){
                            return 0;
                        }else return date[id1] - date[id2];
                    }else return month[id1] - month[id2];
                }else return year[id1] - year[id2];
            }else return strcmp(lastN[id1], lastN[id2]);
        }else return strcmp(middleN[id1], middleN[id2]);
    }else return strcmp(firstN[id1], firstN[id2]);
}

void swap(int id1, int id2){
    int tempDate, tempMonth, tempYear;
    char tempFirstN[10], tempMiddleN[10], tempLastN[10];
    tempDate = date[id1];
    tempMonth = month[id1];
    tempYear = year[id1];
    strcpy(tempFirstN ,firstN[id1]);
    strcpy(tempMiddleN ,middleN[id1]);
    strcpy(tempLastN ,lastN[id1]);
    date[id1] = date[id2];
    month[id1] = month[id2];
    year[id1] = year[id2];
    strcpy(firstN[id1], firstN[id2]);
    strcpy(middleN[id1], middleN[id2]);
    strcpy(lastN[id1], lastN[id2]);
    date[id2] = tempDate;
    month[id2] = tempMonth;
    year[id2] = tempYear;
    strcpy(firstN[id2], tempFirstN);
    strcpy(firstN[id2], tempMiddleN);
    strcpy(firstN[id2], tempLastN);
    
}

void bubbleSort(){
    //repeatedly swapping the adjacent elements if they are in the wrong order
    int sorted;
    int size = sizeof(firstN)/sizeof(firstN[0]);
    for(int i=0; i< size-1; i++){
        sorted =1;
        for (int j =0; j< size-i -1 ; j++){
            if(compareData(i, j+1) > 0) {
                swap(i, j+1);
                sorted =0;
            }
        }
        if(sorted == 1 ) break;
    }
}

void selectionSort(){
    //sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning
    int size = sizeof(firstN)/sizeof(firstN[0]);
    for(int i =0; i< size-1; i++){
        int idx = i;
        for(int j=i+1; j< size; j++){
            if(compareData(i, idx) < 0) idx =j;
            swap(i, idx);
        }
    }
}

int main(){
    // genData("data");
    nameSep("testSorting.txt");
}

