/*
ID: iveney1 
LANG: C
TASK: subset
*/

/*
 * Dynamic programming
 * num[i][j][k] denotes: 
 * use i in the subset S of set {1,..,i}, |S|=j
 * sum(S)=k
 * num[i][j][k]=num[i-1][j][k] +     // 
 *              num[i-1][j-1][k-i]   // 
 */
#include <stdio.h>
#define MAXN 40
#define MAXSUM 400

int num[MAXN][MAXN][MAXSUM];

void find(int i,int j,int k){
	if( i < 0 || j < 0 || k < 0)
		return;
	printf("(%d,%d,%d)=%d\t", i,j,k,num[i][j][k]);
	if(i-1>=0)
		printf("(%d,%d,%d)=%d\t",i-1,j,k,num[i-1][j][k]);
	if(j-1>=0 && k-i >=0)
		printf("(%d,%d,%d)=%d",i-1,j-1,k-i,num[i-1][j-1][k-i]);
	printf("\n");
	find(i-1,j,k);
	find(i-1,j-1,k-i);
}

int main(){
	freopen("subset.in","r",stdin);
#ifndef LOCAL
	freopen("subset.out","w",stdout);
#endif
	int N;
	scanf("%d",&N);
	int sum = N*(N+1)/2;
	if( sum % 2 != 0 ) {
		printf("0\n");
		return 0;
	}
	int half = sum/2;
	int i,j,k;
	for(i=1;i<=N;i++){
		num[i][0][0]=1;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=i;j++){
			for(k=1;k<=half;k++){
				num[i][j][k] = num[i-1][j][k];
				num[i][j][k] += num[i-1][j-1][k-i];
			}
		}
	}

	int sol=0;
	for(j=1;j<=N;j++){
		sol+=num[N][j][half];
	//	printf("j=%d:%d\n",j,num[N][j][half]);
	}
	printf("%d\n",sol);
	//find(7,3,14);
	return 0;
}

// 15
// 361
