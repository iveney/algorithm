#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int mat[MAX][MAX];
int horz[MAX][MAX];
int vert[MAX][MAX];
int mul[MAX][MAX];
int n,m;

void output(int matrix[][MAX]){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%4d",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void gen(){
	int i,j;
	srandom(time(NULL));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			mat[i][j] = random()%2;
		}
	}
}

void search(){
	int i,j;
	int idx_i=0,idx_j=0;
	int max=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if( mat[i][j] == 1 )
				horz[i][j] = horz[i][j-1]+1;
			else
				horz[i][j] = 0;
		}
	}
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			if( mat[i][j] == 1 )
				vert[i][j] = vert[i-1][j]+1;
			else
				vert[i][j] = 0;
			// now we can calculate their multiple
			mul[i][j] = horz[i][j] * vert[i][j];
			// also keeps track of the largest value
			if( mul[i][j] > max ){
				max = mul[i][j];
				idx_i = i;
				idx_j = j;
			}
		}
	}
	output(horz);
	output(vert);
	output(mul);
	printf("max = %d, at (%d,%d)\n",max,idx_i,idx_j);
}

int main(int argc,char * argv[]){
	if(argc < 3)
		return 1;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	gen();
	output(mat);
	search();
	return 0;
}
