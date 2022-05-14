#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct Stack {
    int top;
    unsigned capacity;
    float* array;
}Stack;
 
Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (float*)malloc(stack->capacity * sizeof(float));
    return stack;
}
 
float isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
float isEmpty(Stack* stack)
{
    return stack->top == -1;
}
 
void push(Stack* stack, float item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
float pop(Stack* stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top--];
}

float peek(Stack* stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top];
}

typedef struct Profile {
    char id[8];
    float gradeM;
    float gradeC;
    float gradeP;
    float Total;
    struct Profile *next;
}Profile;

Profile *first, *last;

Profile *createProfile(char id[8], float Math, float Chem, float Phys){
    Profile* newNode = (Profile*)malloc(sizeof(Profile));
    strcpy(newNode->id, id);
    newNode->gradeM = Math;
    newNode->gradeC = Chem;
    newNode->gradeP = Phys;
    newNode->Total = Math + Chem + Phys;
    newNode->next = NULL;
    return newNode;
}

float getMinTotalGrade(int k){
    Profile *currentProfile = first;
    Stack *minTotalStack = createStack(k), *waitingStack = createStack(k);
    push(minTotalStack, currentProfile->Total);
    currentProfile = currentProfile->next;
    while(currentProfile != last){
        if(!isFull(minTotalStack)){
            if(currentProfile->Total <= peek(minTotalStack)){
                push(minTotalStack, currentProfile->Total);
            }else{
                while(currentProfile->Total > peek(minTotalStack) && !isEmpty(minTotalStack)){
                    push(waitingStack, peek(minTotalStack));
                    pop(minTotalStack);
                }
                push(minTotalStack, currentProfile->Total);
                while(!isEmpty(waitingStack)){
                    push(minTotalStack, peek(waitingStack));
                    pop(waitingStack);
                }
            }
        }else{
            while(peek(minTotalStack) <= currentProfile->Total && !isEmpty(minTotalStack)){
                push(waitingStack, peek(minTotalStack));
                pop(minTotalStack);
            }
            push(minTotalStack, currentProfile->Total);
            while(!isEmpty(waitingStack)){
                push(minTotalStack, peek(waitingStack));
                pop(waitingStack);
            }
        }
        currentProfile = currentProfile->next;
    }
    printf("Min total of top %d: %.2f\n",k, peek(minTotalStack));
    return peek(minTotalStack);
}

void appendProfile(char id[8], float Math, float Chem, float Phys){
    Profile *profile = createProfile(id, Math, Chem, Phys);
    if(!first){
        first = profile;
        last = profile;
    }else{
        last->next = profile;
        last = profile;
    }
}

void printProfile(){
    Profile *currentProfile = first;
    float max = 0;
    printf("===================STUDENT LIST===================\n")
    while(currentProfile != last){
        printf("%s %.2f %.2f %.2f %.2f\n", currentProfile->id, currentProfile->gradeM, currentProfile->gradeC, currentProfile->gradeP, currentProfile->Total);
        if(currentProfile->Total > max){
            max = currentProfile->Total;
        }
        currentProfile = currentProfile->next;
    }
    printf("Maximum total: %.2f\n", max);
}

void readFileAndStore(char filename[100]){
    FILE *file = fopen(filename, "r");    
    char *id[8];
    float gradeM, gradeC, gradeP;
    while(fscanf(file,"%s %f %f %f ", id, &gradeM, &gradeC, &gradeP) == 4){
        appendProfile(id, gradeM, gradeC, gradeP);
    }
        appendProfile(id, gradeM, gradeC, gradeP);
    fclose(file);
    
}

int main(){
    char filename[100];
    int numOfAdd;
    printf("Enter file name: \n");
    scanf("%s", filename);
    readFileAndStore(filename);
    printProfile();
    printf("Insert number of student need addmissions\n");
    scanf("%d", &numOfAdd);
    getMinTotalGrade(numOfAdd);
}