/*
 * http://www.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
 * Dynamic Programming
 */
#include <stdio.h>
#define MAX 60
int n;	/* [2..40] */
int d[MAX];

int m1[MAX]; /* [1..n-1] */
int m2[MAX]; /* [2..n] */

int main()
{
	freopen("data.in","r",stdin);
	n=0;
	int temp;
	while(scanf("%d",&temp) != EOF){
		n++;
		d[n]=temp;
		m1[n]=m2[n]=temp;
	}
	
	m1[0]=0;m1[1]=d[1];
	int i,j;
	for(i=2;i<=n-1;i++){
		int x=m1[i-1];
		int y=m1[i-2]+d[i];
		if( x>y ) m1[i] = x;
		else m1[i]=y;
	}

	m2[0]=0;m2[1]=0;m2[2]=d[2];
	for(i=3;i<=n;i++){
		int x=m2[i-1];
		int y=m2[i-2]+d[i];
		if( x>y ) m2[i] = x;
		else m2[i] = y;
	}
	int out=0;
	if( m1[n-1] > m2[n] ) out=m1[n-1];
	else out=m2[n];
	printf("%d\n",out);
	/*
	for(i=0;i<=n;i++)
		printf("%d\t%d\n",m1[i],m2[i]);
	printf("%d\n",n);
	*/

	return 0;
}
