#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int boardtest[9][9] = { 
    { 3, 7, 8, 9, 2, 6, 4, 1, 5 }, 
    { 4, 2, 9, 1, 5, 0, 0, 6, 0 },
    { 5, 6, 1, 3, 4, 0, 9, 2, 0 }, 
    { 1, 9, 6, 7, 0, 5, 2, 8, 4 }, 
    { 7, 4, 5, 2, 8, 1, 0, 9, 0 },
    { 0, 0, 2, 4, 6, 9, 0, 5, 7 }, 
    { 9, 8, 4, 5, 1, 3, 6, 7, 2 }, 
    { 2, 5, 7, 6, 9, 4, 0, 3, 1 },
    { 6, 1, 3, 8, 7, 2, 5, 4, 0 } 
};
bool markRow[9][9] = {false}, markCol[9][9] = {false}, markMatrix[3][3][9] = {false};

void printResult(){
    for(int i = 0; i < 9; i++) {
        for(int j =0; j < 9; j++){
            printf("%d ", boardtest[i][j]);
        };
        printf("\n");
    }
}

void Try(int row, int col){
    if(col < 9 && row < 9){
        if(boardtest[row][col] == 0){
            for(int i = 1; i <= 9; i++){
                if(!markRow[row][i-1] && !markCol[col][i-1] && !markMatrix[row/3][col/3][i-1]){
                    markRow[row][i-1] = true;
                    markCol[col][i-1] = true;
                    markMatrix[row/3][col/3][i-1] = true; 
                    boardtest[row][col] = i;
                    Try(row, col + 1);
                    markRow[row][i-1] = false;
                    markCol[col][i-1] = false;
                    markMatrix[row/3][col/3][i-1] = false; 
                    boardtest[row][col] = 0;
                }
            }
        }else{
            Try(row, col + 1);
        }
    }else if(row < 9 && col >= 9){
        Try(row + 1, 0);
    }else{
        printResult();
        exit(0);
    }
}



int main(){

    // Marking Array
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int currentNumber = boardtest[i][j];
            if (currentNumber != 0) {
                markRow[i][currentNumber - 1] = true;
                markCol[j][currentNumber - 1] = true;
                markMatrix[i/3][j/3][currentNumber - 1] = true;
            }
        }
    }
    Try(0,0);
}