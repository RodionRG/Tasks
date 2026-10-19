#include <stdio.h>
#include <math.h>
#include <locale.h>
#define PI 3.141592

/* �����: ������ �.�.
 * ������
 * ��������� a � b �� ������ �������� � ���������� x,y � z.
 */

int main() {

setlocale(LC_ALL, "Russian"); 

float x,y,z; // ������� ����������
float a,b;   // ������� ����������

printf("������� ���������� \n");
printf("x = ");
scanf("%f", &x);

printf("y = ");
scanf("%f", &y);

printf("z = ");
scanf("%f", &z);

a = (2*cos(x-PI/6))/((float)1/2+pow(sin(y),2)); //������ �������
b = 1 + (pow(z,2))/(3+pow(z,2)/5);
 
printf("a = %.3f \nb = %.3f",a,b);

while (getchar()!='\n');  //��� ������ �� �������� �� enter
getchar();

return 0;
}