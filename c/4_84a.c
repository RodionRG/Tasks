#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Вычислить значение по данной формуле и переменным n и x
 */

int main() {

setlocale(LC_ALL, "Russian");

int n;
float x,o; // o переменная для ответа

printf("Введите переменные \n");
printf("n = ");
scanf("%d", &n);

printf("x = ");
scanf("%f", &x);

o = 0;

for (int i = 1; i <=n; i++) {
o=o+pow(sin(x),i);
}

printf("Сумма равна: %.3f",o);

while (getchar()!='\n');
getchar();

return 0;
}