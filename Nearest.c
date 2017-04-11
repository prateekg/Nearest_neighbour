#include <stdio.h>
#include <stdlib.h>


int distance(int *x, int *y)
{
	int d = (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]); 
	return d;
} 

void print(int b[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d\t", b[i]);
	printf("\n\n");
}

int main()
{
	int n, i, j;
	printf("Enter the number of points:");
	scanf("%d", &n);

	int **a = (int **)malloc(n*sizeof(int *));
	int *b = (int *)malloc(n*sizeof(int));

	for(i=0; i<n; i++){
		printf("%d --> ", i+1);
		a[i] = (int *)malloc(2*sizeof(int));
		b[i] = 0;
		for(j=0; j<2; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}

	int *V = a[0]; //intial vertex
	b[0] = 1;
	int d, index;
	
	printf("(%d , %d) ---->  ", V[0], V[1]);
	for(j=0;j<n;j++)
	{    
		int min=10000;

		if(min!=1000)
		{
		for(i=0; i<n; i++){
			if(b[i]==0)
			{	
				d = distance(V, a[i]);
				if(d<min)
				{
					min=d;
					index = i;
				}
			}
		}
		int *V = a[index];
		printf("(%d , %d) ---->  ", V[0], V[1]);
		b[index]=1;
		}
	}	
	printf("END");

	return 0;
}