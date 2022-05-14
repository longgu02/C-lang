#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *nextNode;
}Node;

Node *createNode(int x){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->nextNode = NULL;
    return node;
}

Node *push(Node *headNode, int data){
    Node *node = createNode(data);
    node->nextNode = headNode;
    headNode = node;
    return headNode;
}

Node *append(Node *headNode, int data){
    Node *node = createNode(data);
    Node *previousNode = headNode;
    while(previousNode->nextNode != NULL){
        previousNode = previousNode->nextNode;
    };
    previousNode->nextNode = node;
    return node;
}

void printList(Node *list){
    Node *node = list;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->nextNode;
    };
};

double avg(Node *list){
    int sum = 0, counter = 0;
    double avg;
    Node *node = list;
    while(node != NULL){
        counter++;
        sum += node->data;
        node = node->nextNode;
    };
    avg = (double)sum/counter;
    printf("sum/counter %d", sum/counter);
    return avg;
}

int edit(Node *list, int oldValue, int newValue){
    Node *node = list;
    while(node != NULL){
        if(node->data == oldValue){
            node->data = newValue;
        }
        node = node->nextNode;
    };
    return 0;
}

void displayMenu(Node *list){
    int choice, data, oldVal, newVal;
    double average;
    while(true){
        printf("\n1. Append elements\n");
        printf("2. Push elements\n");
        printf("3. Print List\n");
        printf("4. Edit\n");
        printf("5. Average\n");
        printf("Your choice is: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Insert data: ");
                scanf("%d", &data);
                append(list,data);
                break;
            case 2: 
                printf("Insert data: ");
                scanf("%d", &data);
                push(list,data);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                printf("Insert old value: ");
                scanf("%d", &oldVal);
                printf("Insert new value: ");
                scanf("%d", &newVal);
                edit(list,oldVal, newVal);
                break;
            case 5:
                average = avg(list);
                printf("Avg: %d", average);
                break;
        }
    }
}


int main(){
    int n,x,data;
    printf("Insert number of elements: ");
    scanf("%d", &n);
    printf("Insert data for elements 1: ");
    scanf("%d", &x);
    Node *list = createNode(x);
    Node *previousNode = list;
    for(int i = 1; i < n; i++){
        printf("Insert data for elements %d: ", i+1);
        scanf("%d", &data);
        previousNode = append(list, data);
    }
    displayMenu(list);
    // printList(list);
    return 0;
}