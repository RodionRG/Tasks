#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Проверить находится ли точка с кординатами x и y в заштрихованной области (круг радиусом 1 и центром в начале координат)
 */

int main() {

setlocale(LC_ALL, "Russian");

float x;

printf("Введите x =");
scanf("%f",&x);

printf("Целая часть x = %d\n", (int)x);
printf("Округление x = %.0f\n", x);
printf("Число x без дробных цифр = %d", (int)floor(x));

while (getchar()!='\n');
getchar();

return 0;
}