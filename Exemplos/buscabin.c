#include <stdio.h>

/****************************************
Pesquisa binaria em um vetor ordenado. */

/******************************************************************************************
Pesquisa binaria recursiva.                                                               * 
v - vetor, p - posicao inicial do intervalo, q - posicao final do intervalo, e - elemento.*/ 
int pesqbinrec(int *v, int p, int r, int e)
{
   int q;
   //printf ("%d - %d\n", p, q);
   if (r<p)
      return -1;
   q = (p + r)/2;
   if (e == v[q])
      return q;
   if (e < v[q])
      return pesqbinrec(v, p, q-1, e); // Recursividade de cauda. 
   return pesqbinrec(v, q+1, r, e);
}


/************************************************************
Interface para a impelementacao recursiva.                  *
v - vetor, n - numero de elementos, e - elemento procurado. */

int pesqbin (int *v, int n, int e)
{
   return pesqbinrec(v, 0, n-1, e);
}

/**********************************************************
Pesquisa binaria iterativa.                               * 
v - vetor, n - numero de elementos do vetos, e - elemento.*/ 

int pesqbin2 (int *v, int n, int e)
{
   int p, q, r;
   
   p = 0;
   r = n-1;
   do
   {
      q = (p + r) / 2;
      if (e == v[q])
         return q;
      if (e < v[q])
         r = q -1;
      else    
         p = q + 1;
   } while (p<= r);
   return -1;
}
      
      
int main()
{
   int v[] = {9, 10, 15, 17, 20, 25, 28, 30};
   int pos;
   
   pos = pesqbin(v, 8, 27);
   printf("%d\n", pos);
   return 0;
   
}
   