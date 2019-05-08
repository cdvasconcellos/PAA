#include <stdio.h>

void minMaxRec(int *v, int p, int r, int *min, int *max)
{
	int q, min1, max1;
	
	//printf ("p = %d r= %d\n", p, r);
	if (p < r)
	{
		q = (p + r)/2;
		minMaxRec(v, p, q, &min1, &max1);
		minMaxRec(v, q + 1, r, min, max);
		if (min1 < *min)
			*min = min1;
		if (max1 > *max)
			*max = max1;
	}
	else
	{
		*min = v[p];
		*max = v[p];
	}
}

/*******************************************************************************************
Interface para minMaxRec. Retorna ao maoir (max) e o menor (min) valor contido no vetor (v),
que tem tamanho n. */ 
void minMax1(int *v, int n, int *min, int *max)
{
	minMaxRec (v, 0, n-1, min, max);
}


/*****************************************************************
Retorna ao maoir (max) e o menor (min) valor contido no vetor (v),
que tem tamanho n. */ 


void minMax(int *v, int n, int *min, int *max)
{
        int i;
        
        if (n % 2 != 0) 
                v[n] = v[n-1];
        if (v[0] > v[1]) 
        {
                *max = v[0];
                *min = v[1];
        }
        else
        {
                *max = v[1];
                *min = v[0];
        }
        i = 2;
        while (i < n)
        {
                if (v[i] > v[i+1]) // primeira comparação
                {
                        if (v[i] > *max) // segunda comparação
                                *max = v[i];
                        if (v[i+1] < *min)
                                *min = v[i+1]; // terceira 
                }
                else // ou
                {
                        if (v[i] < *min) // segunda comparação
                                *min = v[i];
                        if (v[i+1] > *max) // terceira 
                                *max = v[i+1];
                }
                i+=2; // numero de iteracoes eh a metade do tamanho do vetor
        }
}

int main()
{
	int min, max;
	int v1[] = {21, 3, 40, 18, 89, 15, 18, 23, 2, 10, 15, 4, 56, 10, 7};
	int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int v3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int v4[] = {1};
	
	minMax1(v3, 10, &min, &max);
	printf("Rec: %d - %d\n", min, max);
	minMax(v3, 10, &min, &max);
	printf("Ite: %d - %d\n", min, max);
	return 0;
	
}
	

		
		