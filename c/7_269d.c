#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Автор: Галкин Р.Р.
 * Задача
 * Дана строка символов. Нужно найти какое-нибудь слова на букву а
 */

int main() {

setlocale(LC_ALL, "Russian");

char str[256];
int word = 0;
int foundword = 0;


printf("Введите предложение (не > 256 символов)\n");
fgets(str, sizeof(str),  stdin); //Stdin переменная которая являеся каналом ввода с клавиатуры
for (int i = 0; i<=255; i++){
    if ((str[0] == 'a') || (str[0] == 'A')) {
        word = 1;
    }
    if (str[i] == ' ' ){
        if (str[i+1]== 'a' || str[i+1] == 'A'){
            word = 1;
            if (foundword){
                break;
            }
        }
        else{
            word =0;
            if (foundword){
                break;
            }
        }
    }
    if (word){
        printf("%c",str[i]);
        foundword = 1;
    }
}

while (getchar()!='\n');
getchar();

return 0;
}