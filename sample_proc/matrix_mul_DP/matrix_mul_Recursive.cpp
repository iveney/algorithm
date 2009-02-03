// 记忆化搜索

#include <stdio.h>
#include <string.h>

struct mat
{
	int sum;
	int b;
};

int cases=0;
int n;
int p[20];
mat d[21][21];
int INFINITE=(2<<30-1);
int top=-1;
char buf[100];

void output(int i,int j)
{
	if( j == i ) 
	{
		buf[++top]='A';
		buf[++top]=i+'0';
		return;
	}
	buf[++top]='(';
	int k=d[i][j].b;
	output(i,k);
	output(k+1,j);
	buf[++top]=')';
}

int dp(int i,int j)
{
	if(i==j)
	{
		d[i][i].sum=0;
	}
	else if(d[i][j].sum == -1)
	{
		int min=INFINITE;int cur=i;
		for(int k=i;k<j;k++)
		{
			int first = dp(i,k);
			int second = dp(k+1,j);
			int extra = p[i-1]*p[k]*p[j];
			int temp = first+second+extra;
			if(temp<min)
			{
				min = temp;
				cur = k;
			}
		}
		d[i][j].sum = min;
		d[i][j].b = cur;
	}
	return d[i][j].sum;
}

int main()
{
	FILE * f=freopen("data","r",stdin);
	while(fscanf(f,"%d",&n) != EOF)
	{
		cases++;
		for(int i=0;i<=n;i++) fscanf(f,"%d",&p[i]);	// input n+1
		for(int i=1;i<=n;i++) 
		{// init
			for(int j=1;j<=n;j++){
				d[i][j].sum=-1;		
				d[i][j].b=-1;
			}
		}
		int result = dp(1,n);
		printf("Case %d\n",cases);
		output(1,n);
		buf[top]=0;
		printf("%d %s\n",result,buf+1);	// extract the first and last '()'
		top=-1;
	}
}
