#include <stdlib.h>
#include <stdio.h>
const int MAX_LEN = 100;

typedef struct Phoneaddress{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(){
    FILE *fptr = fopen("Contact.dat", "r+b");
    phoneaddress contact[MAX_LEN];
    int i,  code;
    code = fread(contact, sizeof(phoneaddress), 3, fptr);
    printf("*** Contact ***");
    for(i = 0 ; i < 3; i++){
        printf("\nName: %s\nTel: %s\nEmail: %s", contact[i].name, contact[i].tel, contact[i].email);
    };
}