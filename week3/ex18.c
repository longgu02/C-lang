#include <stdlib.h>
#include <stdio.h>

const int MAX_LEN = 100;

typedef struct Phoneaddress{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(){
    phoneaddress contact[MAX_LEN];
    int i, n, code;
    FILE *fptr;
    printf("How many contacts do you want to enter (<100)?: ");
    scanf(" %d", &n);
    if((fptr = fopen("Contact.txt", "w+")) == NULL){
        printf("Can not open file");
        return -1;
    }
    for(i = 0; i < n; i++){
        printf("***** Input data for the contact number %d *****", i+1);
        printf("Name: "); scanf("%s", contact[i].name);
        printf("Tel: "); scanf("%s", contact[i].tel);
        printf("Email: "); scanf("%s", contact[i].email);
    };
    code = fwrite(contact, sizeof(phoneaddress), n, fptr);
    printf("fwrite return code = %d\n", code);
    fclose(fptr);
}