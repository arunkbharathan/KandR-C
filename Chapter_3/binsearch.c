#include<stdio.h>
#include<time.h>
int binsearch(int x,int arr[],int n);

int main()
{	int n=2000000;
	int arr[n],i,result;
	 clock_t t;
	 
	for(i=0;i<n;i++,arr[i]=i);
	
	t = clock();
	result = binsearch(-55, arr, n);
	
	printf("\nResult: %d\n",result);
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("search() took %f seconds to execute \n", time_taken);
	return 0;
}
			



/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;      /* no match */
}
