#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Дана последовательность чисел. ужно взять числа по одному из каждой группы равных.
 */

int main() {

setlocale(LC_ALL, "Russian");

unsigned int n,k; //k переменная для приссваивания в массив o

printf("Введите n = ");
scanf("%u",&n);

int x[n]; //Массив с вводимыми числами
int o[n]; //Массив с отобранными числами

printf("Вводите числа массива\n");
for (int i = 0; i<=n-1; i++){  //Ввод чисел в массив
 printf("x[%d] = ",i+1);
 scanf("%d",&x[i]);
}

k=0;
int alr_repeat = 0;
for (int i = 0; i<=n-1; i++){
    alr_repeat = 0;
    for (int j = 0; j<i; j++){
      if (x[i] == x[j]){
       alr_repeat = 1;
       break;
      }
    }
    if (!alr_repeat){o[k] = x[i];k++;}
}

for (int i = 0; i<k;i++){
printf("%d ",o[i]);
if (i%10==9){puts("");}
}

while (getchar()!='\n');
getchar();

return 0;
}
