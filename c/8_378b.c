#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Даны 8 действительных чисел. Нужно составиь матрицу в 
 * которой с каждой строчкой степень будет увеличиваться на один начиная с нуля.
 */

int main() {

setlocale(LC_ALL, "Russian");
float x[8]; // так как массив локальный и не является динамическим - является автоматическим 
float matr[8][8];

printf("Введите 8 действительных чисел\n");  // Ввод чисел
for (unsigned int i =0; i<=7; i++){
    printf("x[%d] = ",i+1);
    scanf("%f", &x[i]);
}

for (unsigned int i =0; i<=7; i++){         //Ввод в матрицу по заданному правилу
    for (unsigned int j =0; j<=7; j++){
        matr[i][j] = pow(x[j],i);
    }
}

for (unsigned int i =0; i<=7; i++){         //Вывод на экран
    for (unsigned int j =0; j<=7; j++){
        printf("%.2f ", matr[i][j]);
    }
    puts("");
}

while (getchar()!='\n');
getchar();

return 0;
}