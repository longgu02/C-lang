#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *frptr, *fwptr;
    int c;
    frptr = fopen("docfile.txt", "r");
    fwptr = fopen("Ghifile.txt", "w+");
    while((c = fgetc(frptr)) != EOF){
        fputc(c, fwptr);
        putchar(c);
    }
    fclose(frptr);
    fclose(fwptr);
}