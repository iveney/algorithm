#include <stdio.h>
#include <stdlib.h>
//#include <algorithm>

int prices[20010];

int cmp(const void * l,const void * r)
{
	return (*(int*)r) - (*(int*)l);
}

int main()
{
	int t,n;
	//FILE * f=freopen("shopaholic.in","r",stdin);
	FILE * f = stdin;
	fscanf(f,"%d",&t);
	for(int i=0;i<t;i++)
	{
		fscanf(f,"%d",&n);
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&prices[j]);

		qsort(prices,n,sizeof(int),cmp);

		//for(int j=0;j<n;j++)
		//	printf("%d ",prices[j]);
		//printf("\n");

		int sum=0;
		for(int j=2;j<n;j+=3)
			sum+=prices[j];
		
		printf("%d\n",sum);
	}
	return 0;
}