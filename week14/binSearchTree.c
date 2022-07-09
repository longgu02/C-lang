#include <stdio.h>

#define MAXLEN 256
#define MAX 100000
typedef struct Node {
  char name[MAXLEN];
  char email[MAXLEN];
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * root;
Node * makeNode(char * name, char * email) {
  Node * p = (Node * ) malloc(sizeof(Node));
  strcpy(p -> name, name);
  strcpy(p -> email, email);
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}
Node * insert(Node * r, char * name, char * email) {
  if (r == NULL) return makeNode(name, email);
  int c = strcmp(r -> name, name);
  if (c == 0) printf("Student %s exists, do not insert\n", name);
  return r;
  else if (c < 0) {
    r -> rightChild = insert(r -> rightChild, name, email);
    return r;
  } else {
    r -> leftChild = insert(r -> leftChild, name, email);
    return r;
  }
}
void load() {
  char filename[256];
  printf("Enter name of file to read: ");
  scanf("%s", filename);
  FILE * f = fopen(filename, "r");
  if (f == NULL) printf("Load data -> file not found\n");
  root = NULL;
  while (!feof(f)) {
    char name[256], email[256];
    fscanf(f, "%s%s", name, email);
    root = insert(root, name, email);
  }
  fclose(f);
}
Node * find(Node * r, char * name) {
  if (r == NULL) return NULL;
  int c = strcmp(r -> name, name);
  if (c == 0) return r;
  if (c < 0) return find(r -> rightChild, name);
  return find(r -> leftChild, name);
}

Node * removeStudent(Node * r, char * name) {
    if (r == NULL) return NULL;
    int c = strcmp(r -> name, name);
    if (c > 0) r -> leftChild = removeStudent(r -> leftChild, name);
    else if (c < 0) r -> rightChild = removeStudent(r -> rightChild, name);
    else {
      if (r -> leftChild != NULL && r -> rightChild != NULL) {
        Node * tmp = findMin(r -> rightChild);
        strcpy(r -> name, tmp -> name);
        strcpy(r -> email, tmp -> email);
        r -> rightChild = removeStudent(r -> rightChild, tmp -> name);
      } else {
        Node * tmp = r;
    if (r -> leftChild == NULL) /r = r->rightChild; else if (r->rightChild == NULL)  r = r->leftChild; free(tmp);}}return r;}

    Node* findMin(Node* r){
        if (r == NULL) return NULL;
        if (r->leftChild == NULL) return r;
        else return findMin(r->leftChild);
    }
void freeTree(Node * r) {
  if (r == NULL) return;
  freeTree(r -> leftChild);
  freeTree(r -> rightChild);
  free(r);
}