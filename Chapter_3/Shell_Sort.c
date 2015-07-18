#include<stdio.h>
void shellsort(int v[], int n);

main()
{
	int n=1000;
	int v[n];
	int i;
	for(i=n-1;i >= 0;v[i]= i--)
		;
	shellsort(v,n);
	for(i=0;i<n;i++)
		printf(" %d ",i);
	putchar('\n');
	return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
	{
		int gap, i, j, temp;
		for (gap = n/2; gap > 0; gap /= 2)
			for (i = gap; i < n; i++)
				for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
					temp = v[j];
					v[j] = v[j+gap];
					v[j+gap] = temp;
				}
	}
