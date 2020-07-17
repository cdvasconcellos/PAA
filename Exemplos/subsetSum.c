#include <stdio.h>

/**********************************************************************************
Solucao de forca bruta para o problema SubsetSum.
Versao de decisao
v - vetor.
k e n - numero de elementos do vetor (k sera decrescido em cada chamda recursiva.
t - valor do somatorio.
retorna um caso exita solucao, caso contrario retorna 0
***********************************************************************************/

int subsetSumD(int *v, int n, int t)
{
   if (t == 0) 
   {
      printf("\n+");
      return 1; // Encontrou um subconjunto.
   }   
   if (n >= 0)
      return subsetSumD(v, n-1, t-v[n-1]) || // Procurar solucao com o valor da posição n-1
             subsetSumD(v, n-1, t); // Procurar solucao sem o valor da posicao n-1
   return 0;
}

/**********************************************************************************
Solucao de forca bruta para o problema SubsetSum.
Imprime a resposta.
v - vetor.
k e n - numero de elementos do vetor (k sera decrescido em cada chamda recursiva.
t - valor do somatorio.
retorna um caso exita solucao, caso contrario retorna 0
***********************************************************************************/


int subsetSum(int *v, int k, int n, int t)
{
   int r1, r2, aux, i;
   
   if (t == 0) 
   {
      printf("\n");
      for (i = k; i < n; i++)
         if (v[i])
            printf("%d ", v[i]); 
      return 1; // Encontrou um subconjunto.
   }
   if (k >= 0)
   {
      r1 = subsetSum(v, k-1, n, t-v[k-1]); // Procurar solucao com o valor da posição n-1
      aux = v[k-1];
      v[k-1] = 0;
      r2 = subsetSum(v, k-1, n, t); // Procurar solucao sem o valor da posicao n-1
      v[k-1] = aux;
      return r1 || r2;
   }
   return 0;
}

/**********************************************************************************
Solucao de forca bruta para o problema SubsetSum.
Imprime todas combinacoes, destancando as respostas.
v - vetor.
k e n - numero de elementos do vetor (k sera decrescido em cada chamda recursiva.
t - valor do somatorio.
***********************************************************************************/

void subsetSum2(int *v, int k, int n, int t)
{
   int aux, s, i;
   
   if (k > 0)
   {
      subsetSum2(v, k-1, n, t);
      aux = v[n-k];
      v[n-k] = 0; // Atribui valor zero a posicao p/ que o elemento não seja considerado na solucao.
      subsetSum2(v, k-1, n, t);
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
   int v[8] = {2, 3, 5, 7, 13, 17, 19};   

   subsetSum2(v, 7, 7, 55);
   if (subsetSumD (v, 7, 55)) 
      printf("\nEncontrou");
   else
      printf ("\nSem solucao\n");
   subsetSum(v, 7, 7, 55);
}

