#include <stdio.h>



int main() {

char a;
char b;
printf("Введите число\n");
scanf("%d",&a);

__asm {
    mov ax, 0 
    mov al, a
    mov cl, 10
    div cl 
    mov b, ah
};

printf("%d",b);
return 0;
}