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

bool checkRow(int row, int col, int num){
    for(int i = 0; i < 9; i++){
        if(boardtest[i][col] == num){
            return true;
        }
    }
    return false;
}

bool checkCol(int row, int col, int num){
    for(int i = 0; i < 9; i++){
        if(boardtest[row][i] == num){
            return true;
        }
    }
    return false;
}

bool checkMatrix(int row, int col, int num){
    if(row < 3){
        row = 0;
    }else if(row < 6){
        row = 3;
    }else{
        row = 6;
    }
    if(col < 3){
        col = 0;
    }else if(col < 6){
        col = 3;
    }else{
        col = 6;
    }
    for(int i = row; i < row + 3; i++){
        for(int j = col; j < col + 3; j++){
            if(boardtest[i][j] == num){
                return true;
            }
        }
    }
    return false;
}

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
                if(!checkRow(row, col, i) && !checkCol(row, col, i) && !checkMatrix(row, col, i)){
                    boardtest[row][col] = i;
                    Try(row, col + 1);
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
    Try(0,0);
}