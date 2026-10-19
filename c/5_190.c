#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Дан массив. Найти сумму положительных и число отрицательных.
 */

int main() {

setlocale(LC_ALL, "Russian");

unsigned int n,sum,k; //sum сумма положительных, k число отрицательных

printf("Введите n = ");
scanf("%u",&n);

int x[n];

printf("Вводите числа массива\n");
for (int i = 0; i<=n-1; i++){  //Ввод чисел в массив
 printf("x[%u] = ",i+1);
 scanf("%d",&x[i]);
}

sum=0;
k=0;

for (int i = 0; i<=n-1; i++){ //Подсчёт искомых чисел
   if (x[i]>=0){
    sum +=x[i];
  }
  else{
    k++;
  }
}

printf("Сумма положительных = %d\nЧисло отрицательных = %d",sum,k);

while (getchar()!='\n');
getchar();

return 0;
}