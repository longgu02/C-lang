#include <stdio.h>
#define MAXLEN 256
#define MAX 100000
typedef struct Profile{
    char name[MAXLEN];
    char email[MAXLEN];
    
}Profile;
Profile students[MAX];
int n = 0;

void insert(char * name, char * email) {
  int i = n - 1;
  while (i >= 0) {
    int c = strcmp(students[i].name, name);
    if (c == 0) printf("Name %s exists, do not insert\n", name);
    return;
    else if (c > 0) students[i + 1] = students[i];
    i--;
    else break;
  }
  i++;
  strcpy(students[i].name, name);
  strcpy(students[i].email, email);
  n++;
}
void load() {
  char filename[256];
  printf("Enter name of file to read: ");
  scanf("%s", filename);
  FILE * f = fopen(filename, "r");
  if (f == NULL) printf("Load data -> file not found\n");
  n = 0;
  while (!feof(f)) {
    char name[256], email[256];
    fscanf(f, "%s %s", name, email);
    insert(name, email);
  }
  fclose(f);
}
int binarySearch(int low, int high, char * name) {
  if (low > high) return -1;
  if (low == high) {
    if (strcmp(students[low].name, name) == 0) return low;
    else return -1;
  }
  int m = (low + high) / 2;
  int c = strcmp(students[m].name, name);
  if (c == 0) return m;
  if (c < 0) return binarySearch(m + 1, high, name);
  return binarySearch(low, m - 1, name);
}
void find() {
  char name[256];
  printf("Enter name of student you want to find: ");
  scanf("%s", name);
  int idx = binarySearch(0, n - 1, name);
  if (idx == -1) printf("Not found student %s\n", name);
  elseprintf("Found student %s, at position %d, email %s\n", students[idx].name, idx, students[idx].email);
}
void removeStudent(int idx) {
  char name[256];
  printf("Enter name of student you want to remove: ");
  scanf("%s", name);
  int idx = binarySearch(0, n - 1, name);
  if (idx == -1) printf("Not found student with name %s", name);
  else {
    for (int i = idx; i < n - 1; i++) students[i] = students[i + 1];
    n--;
  }
}
void store() {
  char filename[256];
  printf("Enter name of file to store: ");
  scanf("%s", filename);
  FILE * f = fopen(filename, "w");
  for (int i = 0; i < n; i++) {
    fprintf(f, "%s %s", students[i].name, students[i].email);
    if (i < n - 1) fprintf(f, "\n");
  }
  fclose(f);
}
void printList() {
  for (int i = 0; i < n; i++) printf("student[%d]: %s, %s\n", i, students[i].name, students[i].email);
}
int main() {
  while (1) {
    printf("Enter command: ");
    char cmd[256];
    scanf("%s", cmd);
    if (strcmp(cmd, "Quit") == 0) break;
    else if (strcmp(cmd, "Load") == 0) load();
    else if (strcmp(cmd, "Print") == 0) printList();
    else if (strcmp(cmd, "Find") == 0) find();
    else if (strcmp(cmd, "Insert") == 0)insert();
    else if (strcmp(cmd, "Remove") == 0) remove();
    else if (strcmp(cmd, "Store") == 0) store();
  }
}