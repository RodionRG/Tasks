#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Дана квадратная матрица n-ного порядка и 2 вектора y и y с n количеством переменных. Найти веткор A*(x+y)
 */

int main() {

setlocale(LC_ALL, "Russian");

unsigned int n;

printf("Введите n\n");
scanf("%u",&n);

int A[n][n]; 
int x[n];
int y[n];
int vec[n];
int answer[n]; //Названия транслитом нежелательны !!!!
int elem;
printf("Вводите элементы матрицы\n");       //Ввод матрицы
for (unsigned int i = 0; i<n; i++){
    for (unsigned int j = 0; j<n; j++){
        printf("A[%u][%u] = ", i+1, j+1);
        scanf("%d",&A[i][j]);
    }
}
printf("Ваша матрица:\n");              //Вывод матрцы
for (unsigned int i = 0; i<n; i++){
    for (unsigned int j = 0; j<n; j++){
        printf("%d ",A[i][j]);

    }
    puts("");
}
printf("Вводите элементы вектора x\n");
for (unsigned int i = 0; i<n; i++){
    printf("x[%u] = ", i+1);
    scanf("%d",&x[i]);
}

printf("Вводите элементы вектора y\n");
for (unsigned int i = 0; i<n; i++){
    printf("y[%u] = ", i+1);
    scanf("%d",&y[i]);
}

for (unsigned int i = 0; i<n; i++){     //Поиск вектора x+y
    vec[i]=x[i]+y[i];  
}

elem = 0;
for (unsigned int i = 0; i<n; i++){         //Поиск искомого вектора
    for (unsigned int j = 0; j<n; j++) {
        elem += A[i][j]*vec[j];
    } 
    answer[i]=elem;
    elem = 0;
}

printf("Итоговый вектор:\n");               //Вывод найденного вектора
for (unsigned int i = 0; i<n; i++){
    printf("%d ", answer[i]);
    if (i%10 == 9){puts("");}
}
while (getchar()!='\n');
getchar();

return 0;
}