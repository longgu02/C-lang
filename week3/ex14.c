#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *frptr, *fwptr;
    char buff[81];
    frptr = fopen("docfile.txt", "r");
    fwptr = fopen("Ghifile.txt", "w+");
    while(fgets(buff, 81, frptr) != NULL){
        int len = strlen(buff);
        fprintf(fwptr, "%d %s", len,  buff);
        printf("%d %s",len, buff);
    }
}