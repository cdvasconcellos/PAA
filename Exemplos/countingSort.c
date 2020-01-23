#include <stdlib.h>
#include <stdio.h>

void countingSort(unsigned int *a, unsigned int *b, unsigned int n)
{
   int i, j, k, *c;
   
   k = 0; 
   for (i = 0; i < n; i++)
      if (a[i] > k)
         k = a[i];
   c = (int *) malloc((k+1) * sizeof(int));
   if (c == NULL)
   {
      printf("Erro na Alocacao\n");
      exit(1);
   }
   for (i = 0; i <= k; i++)
      c[i] = 0;
   for (j = 0; j < n; j++)
      c[a[j]] = c[a[j]]+1;
   for (i = 0; i <= k; i++)
      printf ("C[%d] = %d \n", i, c[i]);
   for (i = 1; i <= k; i++)
      c[i] = c[i] + c[i-1];
        
   for (j = n - 1; j >= 0; j--)
   {
      b[c[a[j]]-1] = a[j];
      c[a[j]] = c[a[j]] - 1;
   }  
   free(c);
}

int main()
{
   int i, b[12], a[] = {3, 6, 9, 4, 1, 3, 4, 7, 8, 9, 1, 4};
   
   countingSort(a, b, 12);
   for (i = 0; i < 12; i++)
	   printf ("%d ", b[i]);
   printf("\n");
   return 0;
}
