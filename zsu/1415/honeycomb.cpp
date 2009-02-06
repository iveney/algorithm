#include <stdio.h>
#include <string.h>

const int N = 20;
int a[N][N][15];

void init(int origin)
{
	memset(a,0,sizeof(a));
	a[origin][origin][0]=1;
}

int main()
{
	//FILE * f=freopen("data","r",stdin);
	FILE *f = stdin;
	int count,numCase;
	fscanf(f,"%d",&numCase);
	for(count=0;count<numCase;count++)
	{
		int n;
		fscanf(f,"%d",&n);
		//printf("%d:",n);
		int i,j,k;
		int origin=N/2;
		init(origin);
		for(k=1;k<=n;k++)
		{
			for(i=1;i<N-1;i++)
			{
				for(j=1;j<N-1;j++)
				{
						a[i][j][k]= 	a[i][j+1][k-1]+
								a[i+1][j+1][k-1]+
								a[i+1][j][k-1]+
								a[i][j-1][k-1]+
								a[i-1][j-1][k-1]+
								a[i-1][j][k-1];
				}
			}
		}
		printf("%d",a[origin][origin][n]);
/*		i=j=origin,k=n+1;
		printf("%d %d %d %d %d %d",a[i][j+1][k-1],
						a[i+1][j+1][k-1],
						a[i+1][j][k-1],
						a[i][j-1][k-1],
						a[i-1][j-1][k-1],
						a[i-1][j][k-1]);
*/
		printf("\n");
	}
	return 0;
}
