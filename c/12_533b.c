#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "modul.h"
/* Автор: Галкин Р.Р.
 * Задача
 * Дано натуралное число n и действительные числа a1 ... an. Вычислить (a1+an)(a2+an-1)...(an+a1)
 */

int main() {

setlocale(LC_ALL, "Russian");

unsigned int n;
float a;
float answer = 1.0f;
struct dList* list = create_dlist();

printf("Введите число n\n");
scanf("%d",&n);
printf("Вводите числа по очереди действительные числа\n");
for(unsigned int i = 0; i<n; i++){              //Ввод чисел в список
    scanf("%f",&a);
    dAddNodeBack(list,a); 
}

struct dNode* current=list->head;                //указатель для прогона по списку
struct dNode* endcurrent=list->tail;             //указатель для прогона с обратной стороны

for(unsigned int i = 0; i<n; i++){                  //прогон списка и нахождение произведения
    answer*=(current->value+endcurrent->value);
    current=current->next;
    endcurrent=endcurrent->prev;
}

printf("Ответ: %.4f",answer);
 


free_dlist(list);
while (getchar()!='\n');
getchar();

return 0;
}