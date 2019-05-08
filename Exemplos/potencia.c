#include <stdio.h>

//Calcula b elevado a e.
unsigned int potencia (unsigned int b, unsigned int e)
{
   unsigned int r;
   if (e == 0)
      return 1;
   r = potencia(b, e/2);
   if (e % 2 == 0)
      return r*r;
   else 
      return r*r*b;
}
   
int main()
{
   unsigned int b, e, r;
   
   printf("Base:");
   scanf("%d", &b);
   printf("Expoente:");
   scanf("%d", &e);
   r = potencia(b, e);
   printf("Resultado: %d\n", r);
}
   