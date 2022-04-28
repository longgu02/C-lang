#include <stdlib.h>
#include <stdio.h>
int cnt = 0;
void HanoiTower(int n, char start, char end, char spare){
    cnt++;
    if(n == 1) printf("%d Move disk from %c to %c\n",cnt, start, end);
    else {
        HanoiTower(n - 1, start, spare, end);
        HanoiTower(1, start, end, spare);
        HanoiTower(n - 1, spare, end, start);
        }
}

int main(){
    int n = 3; HanoiTower(n, 'a', 'c', 'b');
}