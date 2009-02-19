/*
ID: iveney1 
LANG: C
TASK: sort3
*/
#include <stdio.h>
#define MAXSIZE 1005

int arr[MAXSIZE];
int c[4];
#define ABS(a) ((a)<0?(-(a)):(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))

int main(){
	freopen("sort3.in","r",stdin);
#ifndef LOCAL
	freopen("sort3.out","w",stdout);
#endif

	int N;
	int i;
	scanf("%d\n",&N);
	for(i=0;i<N;i++){
		scanf("%d\n",&arr[i]);
		c[arr[i]]++;
	}

	int c12,c13,c21,c23,c31,c32;
	c12=c13=c21=c23=c31=c32=0;

	for(i=0;i<c[1];i++)
		if(arr[i] == 2) c12++;
		else if(arr[i] == 3) c13++;

	for(i=c[1];i<c[1]+c[2];i++)
		if(arr[i] == 1) c21++;
		else if (arr[i] == 3) c23++;

	for(i=c[1]+c[2];i<N;i++)
		if(arr[i] == 1) c31++;
		else if(arr[i] == 2) c32++;

	/*
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
		*/

	printf("%d\n",MIN(c12,c21)+MIN(c13,c31)+ABS(c12-c21)+MAX(c23,c32));
#ifdef LOCAL
	printf("%d %d %d\n",c[1],c[2],c[3]);
	printf("%d %d\n",c12,c13);
	printf("%d %d\n",c21,c23);
	printf("%d %d\n",c31,c32);
	// output sth. here
#endif
	return 0;
}
