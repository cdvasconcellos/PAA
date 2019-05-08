#include <stdio.h>

/****************************************************************************************************
Executa o merge dos vetores v1 (com tamanho t1) e v2 (com tamanho t1), colocando o resultado em res.*/

void merge (int *v1, int *v2, int *r, int t1, int t2)
{
   int t3, i1, i2, j;

   j = i1 = i2 = 0;
   t3 = t1 + t2;
   while (j < t3)
   {
	  if (i1 < t1 && (i2 == t2 || v1[i1] <= v2[i2]))
         r[j++] = v1[i1++];
      if (i2 < t2 && (i1 == t1 || v2[i2] < v1[i1]))
         r[j++] = v2[i2++];     
   }
      
}

int main()
{
   int vec1[] = {3, 4, 5, 8, 9, 12, 17};
   int vec2[] = {1, 2, 3, 6, 7, 10, 15};
   int i, res[7];

   merge(vec1, vec2, res, 7, 7);
   for (i = 0; i < 14; i++)
      printf("%d ", res[i]);
   return 0;
}
   

         