#include<stdio.h>
#include<time.h>
int binsearch(int x,int arr[],int n);

int main()
{	int n=2000000;
	int arr[n],i,result;
	 clock_t t;
	 
	for(i=0;i<n;i++,arr[i]=i);
	//printf("%d",arr[n-1]);
	t = clock();
	result = binsearch(n/2, arr, n);
	t = clock() - t;
	printf("\nResult: %d\n",result);
	
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("search() took %f seconds to execute \n", time_taken);
	return 0;
}
			



/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)//(search x in array v of length n)
{
	int low, high, mid, midVal;
	low = 0;
	high = n - 1;
	while (low <= high) {
            mid = (low + high)/2;//((unsigned int)low>>1) + ((unsigned int)high>> 1); // Bug Fix for long arrays //(low+high)/2;
            midVal = v[mid];
            
            if (midVal < x)
                low = mid + 1;
            else if (midVal > x)
                high = mid - 1;
            else
                return mid; // key found
         }
         return -(low + 1);  // key not found.
     }
     //Still some problem with n-1th element
