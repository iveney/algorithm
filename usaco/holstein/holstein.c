/*
ID: iveney1 
LANG: C
TASK: holstein
*/
#include <stdio.h>
#include <string.h>
#define MAXV 25
#define MAXG 15

int V,G;
int v[MAXV];
int g[MAXG][MAXV];
int mask[MAXG];
int idx[MAXG];
int sum[MAXV];
int output[MAXG];
int count=0;

int main(){
	freopen("holstein.in","r",stdin);
#ifndef LOCAL
	freopen("holstein.out","w",stdout);
#endif

	int i,j,k;
	scanf("%d",&V);
	for(i=0;i<V;i++) scanf("%d",&v[i]);
	scanf("%d",&G);
	for(i=G-1;i>=0;i--)// stores reversely
		for(j=0;j<V;j++)
			scanf("%d",&g[i][j]);
	for(i=0;i<G;i++) {
		mask[G-i-1] = (1<<i);
		idx[i]=i;
	}

	int best=0;
	int best_count=MAXG+1;
	for(i=1;i<(1<<G);i++){
		memset(sum,0,sizeof(sum));
		count=0;
		for(j=0;j<G;j++){
			if( mask[j] & i ){
				count++;
				for(k=0;k<V;k++)
					sum[k] += g[j][k];
			}
		}

		int notfail=1;
		/*
		printf("i=[%d]\n",i);
		for(j=0;j<V;j++){
			printf("%5d",sum[j]);
		}
		printf("\n");
			*/
		for(j=0;j<V && notfail;j++)
			if( sum[j] < v[j] )
				notfail=0;
		/*
		if(notfail) 
			printf("sol: %d\n",i);
			*/
		// found a solution
		if(notfail && count<best_count ){
			best = i;
			best_count = count;
		}
	}
	// now best is the answer
	// count how many bits and output corresponding bit
	int num=best;
	printf("%d",best_count);
	for(i=0;i<G;i++){
		if( num & mask[G-i-1] )
			printf(" %d",i+1);
			//output[count++] = i+1;
	}
	printf("\n");
	/*
	printf("%d %d",count,output[0]);
	for(i=1;i<count;i++)
		printf(" %d",output[i]);
	*/

#ifdef LOCAL
	//for(i=0;i<G;i++) printf("%3d:%5d%5d\n",i,mask[i],idx[i]);
	// output sth. here
#endif
	return 0;
}
