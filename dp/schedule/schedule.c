#include <stdio.h>

#define MAX 100
int e[3],x[3];
int n;
int a[3][MAX+1];
int t[3][MAX];

int f[3][MAX+1];
int l[3][MAX+1];

int main()
{
	freopen("data.in","r",stdin);
	scanf("%d%d%d%d%d",&e[1],&e[2],&x[1],&x[2],&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[1][i]);
	for(i=1;i<=n;i++) scanf("%d",&a[2][i]);
	for(i=1;i<=n-1;i++) scanf("%d",&t[1][i]);
	for(i=1;i<=n-1;i++) scanf("%d",&t[2][i]);

	f[1][1]=e[1]+a[1][1];
	f[2][1]=e[2]+a[2][1];

	l[1][1]=l[2][1]=-1;

	for(i=2;i<=n;i++)
	{
		int x,y;
		// calculate f[1]
		x=f[1][i-1]+a[1][i];
		y=f[2][i-1]+a[1][i]+t[2][i-1];
		if( x < y ) {// come from line 1 
			f[1][i]=x;
			l[1][i]=1;
		}
		else{
			f[1][i]=y;
			l[1][i]=2;
		}
		// calculate f[2]
		x=f[1][i-1]+a[2][i]+t[1][i-1];
		y=f[2][i-1]+a[2][i];
		if( x < y ){// come from line 1
			f[2][i]=x;
			l[2][i]=1;
		}
		else{
			f[2][i]=y;
			l[2][i]=2;
		}
	}
	int s,k;
	int end1=f[1][n]+x[1];
	int end2=f[2][n]+x[2];
	if( end1 < end2 ){
		s=end1;
		k=1;
	}
	else{
		s=end2;
		k=2;
	}
	printf("%d\n",s);

	printf("%d ",k);
	for(j=6;j>=2;j--) {
		printf("%d ",l[k][j]);
		k=l[k][j];
	}
	printf("\n");
	return 0;
}
