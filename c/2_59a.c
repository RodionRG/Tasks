#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Проверить находится ли точка с кординатами x и y в заштрихованной области (круг радиусом 1 и центром в начале координат)
 */

int main() {

setlocale(LC_ALL, "Russian"); 

float x,y; //Вводные координаты проверяемой точки

printf("Введите переменные \n");
printf("x = ");
scanf("%f", &x);

printf("y = ");
scanf("%f", &y);

if (pow(x,2)+pow(y,2)<=1) {
 printf("Точка принадлежит области");
} else {
 printf("Точка НЕ принадлежит области");
}

while (getchar()!='\n');
getchar();

return 0;
}