#include <stdio.h>



int main() {


unsigned char latter;

__asm {
    mov AL, 0xAB
    mov latter, AL
};

printf("%d",latter);
return 0;
}