#include <stdlib.h>
#include <stdio.h>

int Palindrome(char str[10], int start, int end){
    if(start >= end) return 1;
    if(str[start] != str[end]) return 0;
    else return Palindrome(str, start+1, end-1);
};

int main(){
    char S[4] = "NOON";
    int start = 0, end = strlen(S);
    printf("%d", Palindrome(S, start, end));
}