#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "modul.h"

/* Автор: Галкин Р.Р.
 * Задача
 * Дан файл с данными об учиниках: имя фамилия класс буква. Нужно проверить есть ли однофамильцы в каком-нибудь классе.
 */

int main() {

setlocale(LC_ALL, "Russian");
char URL[200];


printf("Отправьте путь файла\n");
scanf("%199s",&URL);

NamesakesInClass(URL);      
//Получает файл и проверяет данные об учинеках а наличие однофамильцев

while (getchar()!='\n');
getchar();

return 0;
}