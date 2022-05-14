#include <stdio.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *node;
node *create(int x){
    node temp;
    temp = (node)malloc(sizeof(struct node)); 
    temp->next = NULL;
    temp->data = x; 
    return temp;
}
void printlinkedlist(struct node *head){
    struct node *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
}

node *addElement(struct node *ptr, int x){
    struct node *temp = create(x);
    ptr->next = temp;
    return temp;
}

void displayMenu(struct node *ptr){
    int choice;
    while(true){
        printf("1. Append elements\n");
        printf("2. Push elements\n");
        printf("3. Print List\n");
        printf("Your choice is: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                
        }
    }
}

int main(){
   int n,x;
   scanf("%d",&n);
   scanf("%d", &x);
   struct node *head = create(x);
   struct node *ptr = head;
   for (int i = 1; i < n ; i++){
       scanf("%d", &x);
       ptr = addElement(ptr,x);
   }
   printlinkedlist(head);
   free(ptr);
   return 0;
}