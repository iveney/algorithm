#include <stdio.h>
#include <string.h>

const int N=40;
int m,d;
int num[N][N];	// high precision

void add(int c[],int a[],int b[])
{
	memset(c,0,sizeof(num[0]));
	for(int i=0;i<N-1;i++)
	{
		int temp = a[i]+b[i]+c[i];
		c[i]=temp%10;
		c[i+1]=temp/10;
	}
}

void output(int high,int a[])
{
	for(;high>=0;high--)
		printf("%d",a[high]);
	printf("\n");
}

int main()
{
	while(1)
	{
		scanf("%d %d",&m,&d);
		if(m==0 || d==0) break;
		memset(num,0,sizeof(num));
		num[0][0]=1;
		// before mth month,the rabbits are sequentially increased
		for(int i=1;i<m;i++)
			num[i][0]=i+1;
		// reduce:
		for(int i=m;i<=d;i++)
			add(num[i],num[i-m],num[i-1]);
		int high=N-1;
		for(int j=N-1;j>=0;j--)
		{
			if( num[d][j] > 0 )
			{
				high=j;break;
			}
		}
		output(high,num[d]);
	}
	return 0;
}
