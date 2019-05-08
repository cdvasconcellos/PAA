#include <stdio.h>

int parente(int i)
{
   return (i % 2 + 1);
}
   
int esquerda(int i)
{
   return (2 * i + 1);

}

int direita(int i)
{
   return (2 * i + 2);

}
   
void swap(int *a, int *b)
{
   int aux;

   aux = *a;
   *a = *b;
   *b = aux;
}


   
void heapify (int *a, int n, int i)
{
   int e, d, maior, aux;

   e = esquerda(i);
   d = direita(i);
   if (e < n && a[e] > a[i])
      maior = e;
   else 
      maior = i;
   if (d < n && a[d] > a[maior])
      maior = d;
   if (maior != i)
   {
      aux  = a[i];
      a[i] = a[maior];
      a[maior] = aux;
      heapify(a, n, maior);
   }
}

int heapExtract(int *a, int n)
{
   int maior; 

   maior = a[0];
   a[0] = a[n - 1];
   heapify(a, n - 1, 0);
   return maior;
}

void buildHeap(int *a, int n)
{
   int i;
   
   for (i = (n-1)/2; i >= 0; i--)
         heapify(a, n, i);
}
   
void heapSort(int *a, int n)
{
   int i;
   
   buildHeap(a, n);
   for (i = n - 1; i > 0; i--)
   {
      swap(&a[0], &a[i]);
      heapify(a, i, 0);
   }
}

int main()
{
   int i, j, a[] = {1, 1, 9, 1, 3, 5, 2, 7, 10, 8, 4, 6};

   buildHeap(a, 12);
   for (i=0; i < 12; i++)
         printf("%d ", a[i]);      
   printf("\n"); 
   heapSort(a, 12);
   for (i=0; i < 12; i++)
         printf("%d ", a[i]);

   
}




   
   