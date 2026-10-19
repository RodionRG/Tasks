#include <stdio.h>
#include <vector>
#include <cmath>
#include "1mModul.h"
using namespace std;

void choice();

int main() {

    choice();

    while (getchar()!='\n');
    getchar();

    return 0;
}

void Gauss(){
    vector<vector<double>> matrix;
    vector<double> x(5);
    const double e = 0.0001;

    x = {0, 0, 0, 0, 0, 0};

    printf("\n\nНажмите enter для начала работы программы\n(Числа матрици будут соответственны числам в задании)\n");

    while (getchar()!='\n');
    getchar();

    matrix.resize(5);
    for (unsigned int i = 0; i < 5; i++) matrix[i].resize(6);
    fillMatrix(matrix);

    printf("\n\nНачальная матрица:\n");
    printm(matrix);


    for (int k = 0; k < 5; k++) {
        if (abs(matrix[k][k]) < e) {
            for (unsigned int i = k + 1; i < 5; i++) {
                if (abs(matrix[i][k]) >= e) {
                    swap(matrix[k], matrix[i]);
                    break;
                }
            }
        }

        for (unsigned int i = k + 1; i < 5; i++) {
            for (unsigned int j = k + 1; j <= 5; j++) {
                matrix[i][j] = ((matrix[i][j] * matrix[k][k]) - (matrix[i][k] * matrix[k][j])) / matrix[k][k];
            }
        }

        for (unsigned int i = k + 1; i < 5; i++) matrix[i][k] = 0;

        for (int j = 5; j >k-1; j--) matrix[k][j] /= matrix[k][k];
    }

    printf("\n\nПолученная матрица:\n");
    printm(matrix);

    x[4]=matrix[4][5];

    for (int k = 4; k >= 0; k--)
    {
     double sum = 0;
        for (unsigned int i = k + 1; i < 5; i++){
            sum += matrix[k][i]*x[i];
        }
        x[k] = (matrix[k][5]-sum);
        
    }
    
    printf("\n\nОтвет:\n");
    for (unsigned int i = 0; i < 5; i++){printf("x[%u] = %.3f\n",i,x[i]);}

    return;
}

void Jordan_Gauss(){
    vector<vector<double>> matrix;
    vector<double> x(5);
    const double e = 0.0001;

    x = {0, 0, 0, 0, 0, 0};

    printf("\n\nНажмите enter для начала работы программы\n(Числа матрици будут соответственны числам в задании)\n");

    while (getchar()!='\n');
    getchar();

    matrix.resize(5);
    for (unsigned int i = 0; i < 5; i++) matrix[i].resize(6);
    fillMatrix(matrix);

    printf("\n\nНачальная матрица:\n");
    printm(matrix);


    for (int k = 0; k < 5; k++) {
        if (abs(matrix[k][k]) < e) {
            for (unsigned int i = k + 1; i < 5; i++) {
                if (abs(matrix[i][k]) >= e) {
                    swap(matrix[k], matrix[i]);
                    break;
                }
            }
        }

        for (int i = k - 1; i >= 0; i--) {
            for (unsigned int j = k + 1; j <= 5; j++) {
                matrix[i][j] = ((matrix[i][j] * matrix[k][k]) - (matrix[i][k] * matrix[k][j])) / matrix[k][k];
            }
        }

        for (unsigned int i = k + 1; i < 5; i++) {
            for (unsigned int j = k + 1; j <= 5; j++) {
                matrix[i][j] = ((matrix[i][j] * matrix[k][k]) - (matrix[i][k] * matrix[k][j])) / matrix[k][k];
            }
        }

        for (int i = k - 1; i >= 0; i--) matrix[i][k] = 0;
        for (int i = k + 1; i < 5; i++) matrix[i][k] = 0;

        for (int j = 5; j >k-1; j--) matrix[k][j] /= matrix[k][k];
    }

    printf("\n\nПолученная матрица:\n");
    printm(matrix);

    x[4]=matrix[4][5];

    for (int k = 4; k >= 0; k--) x[k]=matrix[k][5];
    
    printf("\n\nОтвет:\n");
    for (unsigned int i = 0; i < 5; i++){printf("x[%u] = %.3f\n",i,x[i]);}

    return;
}


    void choice(){
        printf("Введите:\nМетод Гаусса - [1]\nМетод Жордана-Гаусса - [2]\n");
        int c = getchar();
        if (c == '1'){Gauss();return;}
        else {if (c == '2'){Jordan_Gauss();return;}
        else {printf("Неверный ввод!");choice(); }}   
}