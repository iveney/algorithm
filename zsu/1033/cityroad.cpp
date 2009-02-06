#include <stdio.h>
#include <string.h>
#include <limits.h>

struct Rect
{
	int x,y,s,t;
};

unsigned long long int a[2][1000001];	// rotate array
Rect r[1000];				
int m,n,B;

bool isInRect(int i,int j)
{
	for(int k=0;k<B;k++)
	{
		int x=r[k].x,y=r[k].y,s=r[k].s,t=r[k].t;
		if( x<i && i<s && y<j && j<t ) return true;
	}
	return false;
}

int main()
{	
	//FILE * f = freopen("data","r",stdin);
	FILE * f = stdin;
	while(1)
	{
		fscanf(f,"%d %d",&m,&n);	// input m,n
		if(m==0 || n==0) break;	
		fscanf(f,"%d",&B);		// input rect num
		for(int i=0;i<B;i++)	// input rects
		{
			int a,b,c,d;
			fscanf(f,"%d %d %d %d",&a,&b,&c,&d);
			r[i].x=a;
			r[i].y=b;
			r[i].s=a+c;
			r[i].t=b+d;
		}
		// init
		//memset(a,0,sizeof(a));
		for(int i=1;i<=n+1;i++)
			a[0][i]=1;
//		a[1][1]=1;
//		for(int i=0;i<n;i++)
//			a[1][i]=1;
		int k=1;
		for(int i=2;i<=m+1;i++)
		{
			a[k][1]=1;
			for(int j=2;j<=n+1;j++)
			{
				if( isInRect(i,j) )
					a[k][j]=0;
				else{
					unsigned long long int left=0,down=0;
					left = a[k][j-1];
					down = a[1-k][j];
					a[k][j]=left+down;
				}
			}
			k=1-k;	// rotate
		}
		k=1-k;	// point to the correct pos
		printf("%lld\n",a[k][n+1]);
		/*for(int i=0;i<=1;i++)
		{
			for(int j=1;j<=n+1;j++)
				printf("%lld  ",a[i][j]);
			printf("\n");
		}*/
	}
	return 0;
}
