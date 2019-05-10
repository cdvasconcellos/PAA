#include <stdio.h>
#include <stdio.h>

int particao(int *v, int e, int d) 
{
  int i, j, pivo, aux;
 
  pivo = v[e];
  i = e - 1;
  j = d + 1;
 
  while (i < j) 
  {
    do 
	   j--;
	while (v[j] > pivo);
    do
       i++;
    while (v[i] < pivo);
    if (i < j)	
	{
	  aux = v[i];
	  v[i] = v[j];
	  v[j] = aux;
    }
  }
  return j;
}

void quickSort(int *a, int e, int d)
{
	int q,i ;

	printf("ini:%d fim:%d\n", e, d);
	if (e < d)
	{
		q = particao(a, e, d);
		printf("   ==>%d\n", q);
		quickSort(a, e, q);
		quickSort(a, q + 1, d);
	}
}

int main()
{
	int i;
	int v0[] = {10, 7, 3, 2, 1, 6, 8, 9, 5, 2, 2, 10, 11};
	int v1[] = {1, 2, 3, 14, 4, 5, 13, 12, 6, 7, 8, 9, 15, 10, 11};
	int v2[] = {17, 15, 14, 13, 12, 11 , 10, 9, 8, 7, 5, 4, 3, 2, 1}; 

	quickSort(v0, 0, 12);
	for (i = 0; i<13; i++)
		printf ("%d ", v0[i]);
	return 0;
}