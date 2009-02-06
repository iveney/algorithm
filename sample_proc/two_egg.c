#include <stdio.h>
#include <string.h>

#define INF 2<<15

int main(){
	int d[3][105];
	memset(d,0,sizeof(d));
	int i,j,k;
	for(i=0;i<=100;i++){
		d[1][i]=i;
	}
	d[2][1]=1;d[2][0]=d[1][0]=0;
	int min=INF,max;
	for(i=2;i<=2;i++)
	for(j=2;j<=100;j++){
		min=INF;
		for(k=1;k<=j;k++){
			int a=d[i-1][k-1];
			int b=d[i][j-k];
			max=(a>b?a:b);
			if(min>max)min=max;
		}
		d[i][j]=min+1;
	}
	for(j=1;j<=100;j++){
		printf("%d    %d\n",d[1][j],d[2][j]);
	}
	printf("%d\n",d[2][100]);

	return 0;
}
