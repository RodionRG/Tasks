#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "modul.h"

/* Автор: Галкин Р.Р.
 * Задача
 * Дан файл f, компоненты которого яляются целыми числами.
 * Нужно получить в файле g все компоненты файла f являющиеся чётными числами
 */

int main() {

    setlocale(LC_ALL, "Russian");

    char in[200]; 
    char out[200];

    printf("Отправьте путь файла in и out\n");
    printf("in: \n");
    scanf("%199s",&in);
    printf("out: \n");
    scanf("%199s",&out);

    EvenNum(in,out); // Переносить чётные числа из файла in в файл out      !!!!!


    while (getchar()!='\n');
    getchar();

    return 0;
}