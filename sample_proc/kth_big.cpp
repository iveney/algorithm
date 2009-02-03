// 找第k大元素(可用于找中位数)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void print(int a[],int size)
{
	for(int i=0;i<size;i++){printf("%d,",a[i]);}
	printf("\n");
}

void genRndSeq(int a[],int size)
{
	time_t t=time(NULL);
	srand((unsigned int)(t));
	for(int i=0;i<size;i++) a[i]=random() % (size*10);
}

void genSeq(int a[],int size)
{
	for(int i=0;i<size;i++) a[i]=i;
}

void genShuffleSeq(int a[],int size)
{
	genSeq(a,size);
	random_shuffle(a,a+size);
}

void swap(int &a,int &b){int temp=a;a=b;b=temp;}

int partition(int a[],int low,int high)
{// sort the array where the first element of array as pivot
	if(low>=high) return low;
	int pivpos=low;
	int piv=a[low];
	for(int i=low+1;i<=high;i++)
	{
		if(a[i]<piv && ++pivpos !=i)
			swap(a[i],a[pivpos]);
	}
	swap(a[low],a[pivpos]);
	return pivpos;
}

int findKth(int a[],int low,int high,int k)
{
// find the kth SMALL element in array a[] which size is 'size'
	if(low>=high) return a[low];
	int pivpos=partition(a,low,high);
	int value;
	if( (k-1)<pivpos )
		value=findKth(a,low,pivpos-1,k);
	else if((k-1)==pivpos) return a[pivpos];
	else
		value=findKth(a,pivpos+1,high,k);
	return value;
}

int findKth(int a[],int N,int k)
{// find the kth big element in array a[] which size is 'size'
	if(k<0 || k>N) return -1;
	return findKth(a,0,N-1,N-k+1);
}

int cmp(const void * a,const void * b)
{
	int x=*(const int *)a;
	int y=*(const int *)b;
	return x>y;
}

int main()
{
	time_t t=time(NULL);
	srand((unsigned int)(t));
	const int N=10;
	int arr[N];
	//genSeq(arr,N);
	genShuffleSeq(arr,N);
	print(arr,N);
	int k;
	scanf("%d",&k);
	//int value=findKth(arr,0,N-1,k);
	int value=findKth(arr,N,k);
	printf("%d\n",value);
	qsort(arr,N,sizeof(int),cmp);
	print(arr,N);

	return 0;
}
