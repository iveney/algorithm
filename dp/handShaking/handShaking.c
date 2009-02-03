#include <stdio.h>

int d[51];

int main()
{
	d[2]=1;
	int n=10;
	int i;
	for(i=4;i<=n;i+=2){
		d[i]=3*d[i-2]-1;
	}
	printf("%d\n",d[n]);
	return 0;
}
