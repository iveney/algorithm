// 最大上升子序列

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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

int maxSubSeq(int a[],int size)
{
	int * d=new int[size];
	memset(d,0,sizeof(a));
	d[1]=1;
	for(int i=2;i<size;i++)
	{
		int max=d[1];
		for(int j=1;j<i;j++)
		{
			if( a[j]<a[i] && d[j]>max )
				max = d[j];
		}
		d[i]=max+1;
	}
	int max=0;
	for(int i=1;i<size;i++)
		if(d[i]>max) max = d[i];
	delete [] d;
	return max;
}

int main()
{
	const int N = 15;
	int seq[N]={0,1,0,3,0,5,0,7,0,9,0,11,15,0};
	//genRndSeq(seq,N);
	print(seq,N);

	int max=maxSubSeq(seq,N);
	printf("%d\n",max);
	return 0;
}
