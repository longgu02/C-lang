#include <stdio.h>
#include <stdlib.h>

typedef struct phoneaddress
{
    char name[20];
    char tel[20];
    char email[20];
} phoneaddress;

void printContact(phoneaddress *Contacts, int start, int end)
{
    int i=start;
    while(i >= start && i <= end){
            printf("Name: %s\nTel: %s\nEmail: %s\n", (Contacts + i)->name, (Contacts + i)->tel, (Contacts + i)->email);
            i++;
    }
}

void getContact(char *filename, phoneaddress *storage, int start, int end)
{
    char nothing[100];
    FILE *file = fopen(filename, "rb");
    phoneaddress contact[100];
    int count =0, code;
    if(file == NULL){
        printf("Deo vao dc file");
    }
    for (int i = 0; i < end; i++)
    {   
        if (i >= start && i <= end)
        {
            // code = fscanf(file, "%s %s %s", &((storage+count)->name), &((storage+count)->tel), &((storage+count)->email));
            // code = fscanf(file, "%s", &nothing);
            code = fread(contact, sizeof(phoneaddress), 5, file);
            count++;
            printf("%d", code);
            // printf("%s", nothing);
            // printContact(storage, start, end);
            fclose(file);
        }else{
            fscanf(file, "%s", &nothing);
        }   
    }
        printf("\nName: %s\nTel: %s\nEmail: %s", contact[0].name, contact[0].tel, contact[0].email);

}
int main()
{
    int start, end;
    char filename[100] = "phonebook.dat";
    phoneaddress *Contacts;
    printf("Insert the begin and the end of the contacts: ");
    scanf("%d %d", &start, &end);
    Contacts = (phoneaddress *)malloc(sizeof(phoneaddress) * (end - start + 1));
    getContact(filename, Contacts, start, end);
    return 0;
}