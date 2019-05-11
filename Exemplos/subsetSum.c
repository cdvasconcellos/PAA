#include <stdio.h>

/**********************************************************************************
Solucao de forca bruta para o problema SubsetSum.                                 *
v - vetor.                                                                        *
k e n - numero de elementos do vetor (k sera decrescido em cada chamda recursiva. *
t - valor do somatorio.                                                           *
***********************************************************************************/

void subsetSum(int *v, int k, int n, int t)
{
   int aux, s, i;
   
   if (k > 0)
   {
      subsetSum(v, k-1, n, t);
      aux = v[n-k];
      v[n-k] = 0; // Atribui valor zero a posicao p/ que o elemento não seja considerado na solucao.
      subsetSum(v, k-1, n, t);
      v[n-k] = aux;
   }
   else
   {   s = 0;
      printf("\n");
      for (i=0; i < n; i++)
      {
         s += v[i];
         if (v[i] != 0)
         printf("%d ", v[i]);
      }
      if (s == t)   
         printf ("**");
         
   }
}

int main()
{
   int v[8] = {2, 3, 5, 7, 9};   

   subsetSum(v, 5, 5, 17);
}

