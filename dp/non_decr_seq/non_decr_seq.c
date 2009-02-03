#include <stdio.h>

#define MAX 100
int d[MAX];	/* d[i]: seq[i] ends longest non-deq sequence*/
int idx[MAX];

int main()
{
	int seq[]={0,5, 3, 4, 8, 6, 7,1,2,3,4,5};
	int n=sizeof(seq)/4-1;

	d[0]=0;idx[0]=-1;
	d[1]=1;idx[1]=1;

	int i,j;
	for(i=2;i<=n;i++){
		int max=1;
		for(j=1;j<i;j++){
			int temp=1;
			if( seq[i] >= seq[j] ) temp=d[j]+1;
			if( temp > max ) max=temp;
		}
		d[i]=max;
	}
	printf("%d\n",d[n]);
	for(i=1;i<=n;i++)
		printf("%d ",d[i]);
	printf("\n");
	return 0;
}
