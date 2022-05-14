#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int matrixResult[4][4] = {0};

bool sameRow(int row, int col){
    for(int i = 0; i < 4; i++){
        if(matrixResult[row][i]){
            return true;
        }
    }
    return false;
}

bool sameCol(int row, int col){
    for(int i = 0; i < 4; i++){
        if(matrixResult[i][col]){
            return true;
        }
    }
    return false;
}

bool sameDiag(int row, int col){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matrixResult[i][j] && (row - i) == (col - j)){
                return true;
            }
        }
    }
    return false;
}

bool check(int row, int col){
    if(sameRow(row, col) || sameCol(row, col) || sameDiag(row, col)){
        return false;
    }
    return true;
}

void printMatrix(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matrixResult[i][j]);
        }
        printf("\n");
    }
}

int solveNQueen(int col){
    if(col >= 4){
        return true;
    }
    for(int row = 0; row < 4; row++){
        if(check(row, col)){ 
            matrixResult[row][col] = 1;
            if(solveNQueen(col + 1)) return true;
            matrixResult[row][col] = 0;
        };
    };
    return false;
}

int main(){
    solveNQueen(0);
    printMatrix();
    system("pause");
}