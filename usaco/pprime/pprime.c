/*
ID: iveney1 
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int isprime(int n)
{
	int i;
	int root = (int) sqrt(n);
	for(i=2;i<=root;i++)
		if( n % i == 0 )
			return 0;
	return 1;
}

char buf[10];
int d[10];
int t[]={
	0,
	1,	// 1
	10,
	100,
	1000,
	10000,	// 5
	100000,
	1000000,
	10000000,
	100000000, // 9
	1000000000
};

int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);
	int i;
	int sum;
	for(d[1]=0;d[1]<=9;d[1]++)
	{
		if( d[1]!=0 && d[1]%2==0 ) continue;
		for(d[2]=0;d[2]<=9;d[2]++)
		{
			for(d[3]=0;d[3]<=9;d[3]++)
			{
				for(d[4]=0;d[4]<=9;d[4]++)
				{
					for(d[5]=0;d[5]<=9;d[5]++)
					{
						sum = d[1]*t[9]+d[2]*t[8]+d[3]*t[7]+
							d[4]*t[6]+d[5]*t[5]+
							d[4]*t[4]+d[3]*t[3]+
							d[2]*t[2]+d[1]*t[1];
						if( sum > b )
							continue;
						printf("%d\n",sum);
					}
				}

			}
		}
	}
	return 0;
}
