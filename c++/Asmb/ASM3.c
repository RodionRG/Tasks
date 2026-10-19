#include <stdio.h>



int main() {

short a;
int b;

printf("Введите число\n");
scanf("%hd",&a);

__asm {
    mov ecx, 0
    mov cx, a
    mov b, ecx
};

printf("%d",b);
return 0;
}