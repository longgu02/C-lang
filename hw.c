#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define  N 100
typedef struct phoneaddress_t {
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(){
    int start, end, irc;
    phoneaddress *list=(phoneaddress*)malloc(N*sizeof(phoneaddress));
    FILE *fp;
    printf("Enter the start and end of the block: ");
    scanf("%d %d", &start, &end);
    if ((fp = fopen("phonebook.dat","r+")) == NULL){
        printf("Can not open %s.\n", "phonebook.dat");
    }
    
    fseek(fp, (start-1)*sizeof(phoneaddress), SEEK_SET);
    irc = fread(list, sizeof(phoneaddress), (end-start), fp);
    printf(" fread return code = %d\n", irc);
    printf("**** Data of contacts **** \n");
    for (int i=0; i<(end-start+1); i++)
        printf("Name: %s ; Tel: %s ; Email: %s\n",list[i].name,list[i].tel,list[i].email);
    free(list);

    int n, num;
    phoneaddress *pp=(phoneaddress*)malloc(N*sizeof(phoneaddress));
    fseek(fp, 0,SEEK_SET);
    num = fread(pp, sizeof(phoneaddress), N, fp);
    printf("Enter the position of contact: ");
    scanf("%d", &n);
    printf("Enter new Name, Tel and Emaill: ");
    scanf("%s %s %s", pp[n].name, pp[n].tel, pp[n].email);
    fwrite(pp, sizeof(phoneaddress),num,fp);
    for (int i=0; i<num; i++)
        printf("Name: %s ; Tel: %s ; Email: %s\n",pp[i].name,pp[i].tel,pp[i].email);
    free(pp);
    fclose(fp);
}