#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}

void print(int a[],int N)
{
	for(int i=0;i<N;i++)
		printf("%d,",a[i]);
	printf("\n");
}

void qsort(int arr[],int a,int b)
{
	if(a>=b) return;
	int piv=arr[a];
	int i=a+1,j=b;
	while(1)
	{
		while( i<j && arr[i]<=piv ) i++;
		while( i<j && arr[j]>=piv ) j--;
		if( i>=j )
			break;
		swap(arr[i],arr[j]);
	}
	if( arr[i] < piv ) swap(arr[i],arr[a]);
	else swap(arr[i-1],arr[a]);
	qsort(arr,a,i-1);
	qsort(arr,i,b);
}

void qsort(int a[],int N)
{
	int i=0;
	qsort(a,0,N-1);
}

int partition(int a[],int low,int high)
{
	int pivpos=low;
	int piv=a[low];
	for(int i=low+1;i<=high;i++)
	{
		if(a[i]<piv && ++pivpos != i)
			swap(a[i],a[pivpos]);
	}
	swap(a[pivpos],a[low]);
	return pivpos;
}

void quicksort(int a[],int low,int high)
{
	if(low>=high) return;
	int pivpos=partition(a,low,high);
	quicksort(a,low,pivpos-1);
	quicksort(a,pivpos+1,high);
}

void qs(int a[],int N)
{
	quicksort(a,0,N-1);
}


int main()
{
	time_t t=time(NULL);
	srand((unsigned int)t);
	const int N=10;
	int i,a[N]={60 ,60, 82, 9, 6, 69, 35, 92, 20, 50};
	for(i=0;i<N;i++) a[i]=rand()%(N*10);
	print(a,N);
	qsort(a,N);
	print(a,N);
	return 0;
}
