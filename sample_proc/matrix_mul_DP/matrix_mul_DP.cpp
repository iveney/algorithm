// Dynamic programming

#include <stdio.h>
#include <string.h>

struct mat
{
	int sum;
	int a,b,c;
};

int cases=0;
int n;
int p[20];
int result[20];
mat d[21][21];
int INFINITE=(2<<30-1);
int top=-1;
char buf[100];

int get(int k)
{// get the multiplication times that kth multiple (k+1)th matrix
	if( result[k] == -1 )
		result[k]=p[k-1]*p[k]*p[k+1];
	return result[k];
}

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

int main()
{
	FILE * f=freopen("data","r",stdin);
	while(fscanf(f,"%d",&n) != EOF)
	{
		cases++;
		for(int i=0;i<=n;i++) fscanf(f,"%d",&p[i]);	// input n+1
		for(int i=1;i<=n;i++) 
		{// init
			d[i][i].sum=0;		
			d[i][i].a=d[i][i].c=i;d[i][i].c=i;
		}
		memset(result,-1,sizeof(result));
		for(int r=2;r<=n;r++)
		{
			for(int i=1,j=r;j<=n;i++,j++)
			{
				int min=INFINITE;
				int cur_a=i,cur_b,cur_c=j;
				for(int k=i;k<j;k++)
				{// i <= k < j
					int temp = d[i][k].sum + d[k+1][j].sum+p[i-1]*p[k]*p[j];
					if(temp < min)
					{
						min = temp;
						cur_b = k;
					}
				}
				//printf("(%d %d)=%d ",i,j,min);
				d[i][j].sum=min;
				d[i][j].a=cur_a;
				d[i][j].b=cur_b;
				d[i][j].c=cur_c;
			}
			//printf("\n");
		}
		printf("Case %d\n",cases);
		printf("%d ",d[1][n].sum);
		output(1,n);
		buf[top]=0;
		printf("%s\n",buf+1);
		top=-1;
	}
}
