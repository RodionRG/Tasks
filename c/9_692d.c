#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include "modul.h"
/* Автор: Галкин Р.Р.                                                                ______
 * Задача                                                                           |######|
 * Дана действительая квадратная матрица. Нужно найти наибольший елемент среди      |  ##  |
 * элементов верхнего и нижнего треугольника квадрата                               |######|
 *///                                                                               
int main() {

setlocale(LC_ALL, "Russian");

unsigned int n;
unsigned int length = 0;  //Переменная кол-во чисел, найденых в заштрихованной области

printf("Введите порядок матрицы.\nn = ");
scanf("%u",&n);

float** matr = CreMatrFloat(n,n);
VvodMatrFloat("Вводите значения матрицы", matr,"Элемент ",n,n);

printf("Ваша матрица:\n");

 for (unsigned int i = 0; i<n;i++){
         for (unsigned int j = 0; j<n;j++){
            printf("%.0f ",matr[i][j]);
         } puts("");
        }

float* elem = MassElemMatr(matr,n,n,&length);


printf("Наибольшее число = %.3f", MaxFloat(elem,length));


freeMatrFloat(matr,n);
free(elem);
while (getchar()!='\n');
getchar();

return 0;
}