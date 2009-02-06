// 0-1背包问题
#include <stdio.h>
#include <string.h>

const int MAXM = 100;
const int MAXN = 100;
int m;		// the capibility of the bag
int n;		// number of the items
int w[MAXN+1];	// weight
int p[MAXN+1];	// price
int dp[MAXM+1][MAXN+1];
int select[MAXN+1];

int main()
{
	FILE * f = freopen("data.in","r",stdin);
	fscanf(f,"%d %d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++) fscanf(f,"%d",&w[i]);
	for(i=1;i<=n;i++) fscanf(f,"%d",&p[i]);
	// init
	for(i=0;i<=m;i++) dp[i][0] = 0;
	for(j=0;j<=n;j++) dp[0][j] = 0;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if( i<w[j] )
				dp[i][j] = dp[i][j-1];
			else
			{
				int temp = dp[i-w[j]][j-1]+p[j];
				if( temp > dp[i][j-1] ) dp[i][j] = temp;
				else dp[i][j] = dp[i][j-1];
			}
		}
	}
	
	i=m;j=n;
	memset(select,0,sizeof(select));
	while(i>0 && j>0)
	{
		if( dp[i][j] > dp[i][j-1] )	
		{
			select[j] = 1;
			i-=w[j];
		}
		j--;
	}
	// back track to see which item has been chosed
	printf("%d\n",dp[m][n]);
	for(i=1;i<=n;i++) printf("%d ",select[i]);
	printf("\n");
	return 0;
}
