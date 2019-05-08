#include <stdio.h>

void bubble(int *v, int t)
{
	int i, j, k, aux;

	for (i = t - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
			printf ("\n%2d,", i);
			printf("%2d: ", j);
			for (k = 0; k < t; k++)
				printf("%d ", v[k]);
		}
	}
}

int main()
{
	int v[] = {8, 1, 6, 3, 7, 2, 5, 4};

	bubble(v, 8);
}

 
				 

	