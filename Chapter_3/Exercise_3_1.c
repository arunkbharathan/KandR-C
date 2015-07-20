/*
 int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else	
			return mid;
	}
	return -1;     
}
 Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time.*/
#include<stdio.h>
#include<time.h>
int binsearch1(int x,int arr[],int n);
int binsearch2(int x, int v[], int n);

int main()
{	int n=2000000;
	int arr[n],i,result;
	double time_taken;
	clock_t t;
	 
	for(i=0;i<n;i++,arr[i]=i);
	
	t = clock();
	result = binsearch1(n/2, arr, n);
	t = clock() - t;
	printf("\nResult: %d\n",result);
	
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("search() took %f seconds to execute \n", time_taken);
    t = clock();
	result = binsearch2(n/2, arr, n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("Exercise3_1 search() took %f seconds to execute \n", time_taken);
	return 0;
}
			


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch1(int x, int v[], int n)
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

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	if(x == v[high])
		return high;    /* match */
	else
		return -1;      /* no match */
}
