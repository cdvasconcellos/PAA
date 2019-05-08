#include <stdio.h>

void selectionSort (int *a, int n)
{
   int i, j, k, aux, menor;

   for (i = 0; i < n-1; i++)
   {
      menor = i;
      for (j = i+1; j < n; j++)
      {
         if (a[j] < a[menor])
            menor = j;
      }
      aux = a[i];
      a[i] = a[menor];
      a[menor] = aux;
      //for (k = 0; k < n; k++) printf("%d ", a[k]); printf("\n");
   }
}

int main()
{
   int k, a[] = {10, 34, 10, 12, 23, 5, 4, 3, 2, 1};

   selectionSort(a, 10);
   for (k = 0; k < 10; k++) 
      printf("%d ", a[k]); 
   printf("\n");
   return 0;
}
