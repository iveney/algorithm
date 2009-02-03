#include <stdio.h>

#define MAX 100
#define M 1000
#define INF 1000000

int v[MAX];
int D[M];
int s,n;

int main()
{
	freopen("data.in","r",stdin);
	scanf("%d %d",&n,&s);
	int i,j;
	for(i=0;i<=s;i++) D[i]=INF;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&v[i]);
		D[v[i]]=1;
	}
	D[0]=0;
	for(i=1;i<=s;i++)
	{
		int half=i/2;
		int min=D[i];
		for(j=1;j<=half;j++)
		{
			if( D[j]+D[i-j] < min )
				min = D[j]+D[i-j];	
		}
		D[i] = min;
	}
	for(i=0;i<=s;i++)printf("[%d] : %d\n",i,D[i]);

	return 0;
}
