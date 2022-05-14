#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Profile{
    char id[20];
    char email[100];
    double grade;
    struct Profile* next;
}Profile;

Profile *first, *last;

Profile* makeProfile(char* id, char* email, double grade){
    Profile* newNode = (Profile*)malloc(sizeof(Profile));
    strcpy(newNode->id, id);
    strcpy(newNode->email, email);
    newNode->grade= grade;
    newNode->next=NULL;
    return newNode;
}

void insertLast(char* id, char* email, double grade){
    Profile* profile= makeProfile(id, email, grade);
    if(first==NULL) {first = profile; last =profile;}
    else{
        last->next = profile;
        last= profile;
    }
}

void loadFile(char filename[100]){
    // printf("Enter the name of file: ");
    FILE* f=fopen(filename,"r");
    if(f==NULL){ 
        printf("Load data -> file not found\n");
        exit(1);
    }
    while(!feof(f)){
        char id[20], email[100];
        double grade;
        fscanf(f,"%s %s %lf", id, email, &grade);
        insertLast(id, email, grade);
    }
    fclose(f);
}



void printList(){
    Profile* p= first;
    while (p!=NULL){
        printf("%s: %s, %lf\n",p->id, p->email, p->email);
    }
}
void findProfileAndEditGrade(char* studentID, double newGrade){
    Profile* found=NULL;
    for(Profile* cur= first; cur!=NULL; cur= cur->next){
        if(strcmp(cur->id, studentID)==0){
            found= cur; 
            break;
        }
    }
    if(found==NULL) printf("Not Found\n");
    else{
        found->grade=newGrade;
        printf("Changed %s grade to %d\n", found->id, found->grade);
    }
}


void FREE_MEM(){
    Profile* del = first;
    while (del != NULL){
        Profile* first = first->next;
        free(del);
        del = first;
    }
}
int main(){
    first = NULL; last =NULL;
    char file[100] = "studentProfile.txt";
    loadFile(file);
    findProfileAndEditGrade("20205161", 10);
    // printList();
    // while(1){
    //     char cmd[256];
    //     printf("Enter command: ");
    //     scanf("%s", cmd);
    //     if(strcmp(cmd,"Quit")==0) break;
    //     else if(strcmp(cmd,"Load")==0) loadFile();
    //     else if(strcmp(cmd,"Print")==0) printList();
    //     else if(strcmp(cmd,"Find")==0) findProfile();
    //     else if(strcmp(cmd,"Store")==0) storeFile();
    // }
    FREE_MEM();
}