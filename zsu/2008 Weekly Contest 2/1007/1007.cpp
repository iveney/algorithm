#include <stdio.h>
#include <string.h>
int main()
{
	while(1)
	{
		int N;
		int i,j,k;
		int origin[2][300];
		scanf("%d",&N);
		if(N == 0) break;
		for(i=0;i<N;i++){
			scanf("%d",&origin[0][i]);
			origin[1][i] = origin[0][i];
		}

		int n=1;
		int p=0;
		while( n != N )
		{
			int q = (p+1)%2;
			for(j=0;j<n*2;j+=2)
			{
				origin[q][j] = (origin[p][(j+1)/2] + origin[p][n+(j+1)/2])/2;
				origin[q][j+1] = (origin[p][(j+1)/2] - origin[p][n+(j+1)/2])/2;
			}
			p = q;
			n *= 2;
		}
		//p = (p+1)%2;
		for(k=0;k<N-1;k++)
			printf("%d ",origin[p][k]);
		printf("%d\n",origin[p][k]);
	}
	return 0;
}

/*
#include <stdio.h>

int main()
{
	while(1)
	{
		int N;
		int i,j,k;
		int a[2][300],d[300],origin[300];
		scanf("%d",&N);
		if(N == 0) break;
//		for(i=0;i<N;i++) scanf("%d",a[0][i]);
		for(i=0;i<N;i++) scanf("%d",origin[i]);

		int n=1;
		int p=0;
		while( n != N )
		{
			n *= 2;
			//int q = (p+1)%2;
			for(j=0;j<n;j+=2)
			{
				//a[q][j] = a[p][2*j-1] + a[p][2*j];	// ÂÖ»»
				//origin[n/2+j] = a[p][2*j-1] + a[p][2*j];
				origin[j] = (origin[2*j] + origin[2*j+1])/2;
				origin[j+1] = (origin[2*j] - origin[2*j+1])/2;
			}
			//p = q;
		}
		//origin[0] = a[p][0];
		for(k=0;k<N-1;k++)
			printf("%d ",origin[k]);
		printf("%d\n",origin[k]);
	}
	return 0;
}
*/