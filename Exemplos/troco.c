#include <stdio.h>

#define MAX 10000
/*******************************************************************************************
Exemplo programacao dinamica - Problema do troco - Construção da tabela.                   *
x - vetor de moedas;                                                                       *
c - numero minimo de moedas necessario para compor o troco representado na linha da tabela;*
s - indice da ultima moeda usada na solucao minima;                                        *
n - ramanho do vetor x (quantidade de moedas com valor distintos).                         *
v - valor maximo do troco.                                                                 *
********************************************************************************************/

void troco(int *x, int *c, int *s, int n, int v)
{
   int p, i, min, m;
   c[0] = 0;
   for (p = 1; p <= v; p++)
   {
      min = MAX;
      for (i = 0; i < n; i++)
      {
        if (x[i] <= p && c[p-x[i]] + 1 <= min)
        {
           min = c[p-x[i]]+1;
           m = i;
        }
        c[p] = min;
        s[p] = m;
      }
   }
}
/***********************************************
Uma vez calculada a tabela s, imprime o troco. */
void imprimirTroco(int *s, int *x, int v)
{
   while (v > 0)
   {
      printf ("%d ", x[s[v]]);
      v = v - x[s[v]];
   }
}
     

int main()
{
   int x[] = {1, 5, 10, 25, 50, 100}; 
   int c[201], s[201];

   troco(x, c, s, 6, 201);
   imprimirTroco(s, x, 108);
   return 0;
}
   
