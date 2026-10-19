#include <stdio.h>


int main() {

char a;
short b;
int c;

printf("Вводите числа\n");
scanf("%c",&a);
scanf("%hd",&b);
scanf("%d",&c);

char answer_a; 
short answer_b;
int answer_c;

__asm {
    mov AH, a
    mov BX, b
    mov EDX, c

    mov answer_a, AH
    mov answer_b, BX
    mov answer_c, EDX
};

printf("AH = %c\nBX = %d\nEDX = %d", answer_a, answer_b, answer_c);
return 0;
}