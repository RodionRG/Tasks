#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "modul.h"
/* Автор: Галкин Р.Р.
 * Задача
 * Дано натуралное число n и действительные числа a1 ... an. Вычислить a1^2+...+an^2;
 */

int main() {

setlocale(LC_ALL, "Russian");

unsigned int n;
float a;
float answer = 0.0f;
struct List* list = create_list();

printf("Введите число n\n");
scanf("%d",&n);
printf("Вводите числа по очереди действительные числа\n");
for(unsigned int i = 0; i<n; i++){              //Ввод чисел в список
    scanf("%f",&a);
    AddNodeBack(list,a);
}


struct Node* current=list->head;                //указатель для прогона по списку
answer+=current->value*current->value;

for(unsigned int i = 1; i<n; i++){              //Прогон списка и нахождение суммы
    current=current->next;
    answer+=current->value*current->value;
}

printf("Ответ: %.4f",answer);



free_list(list);
while (getchar()!='\n');
getchar();

return 0;
}