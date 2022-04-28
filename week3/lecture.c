#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    // char buff[255];
    // fp = fopen("vidu.txt", "r");
    // fscanf(fp, "%s", buff);
    // printf("1: %s\n", buff);

    // fgets(buff, 255, (FILE*)fp);
    // printf("2: %s\n", buff);

    // fgets(buff, 255, (FILE*)fp);
    // printf("3: %s\n", buff);
    // fclose(fp);
    char ch;
    fptr = fopen("baitapc.txt", "w+");
    for( ch = 'b'; ch <= 'z'; ch++){
        fputc(ch, fptr);
    }
    fclose(fptr);
    return 0;
}