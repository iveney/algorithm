/*
ID: iveney1 
LANG: C
TASK: checker
*/
#include <stdio.h>
#include <string.h>
#define ABS(a) ((a)<0?(-(a)):(a))
#define inboard(r,c) ((r)>=1&&(r)<=N&&(c)>=1&&(c)<=N)

int board[14][14];
int at[14];
int out_count=0;
int sol_count=0;
int odd_count=0;
int N;
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};

void out_occupy(){
	int i,j;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			printf("%3d",board[i][j]);
		printf("\n");
	}
}

void output(){
	int i;
	for(i=1;i<N;i++)
		printf("%d ",at[i]);
	printf("%d\n",at[i]);
}

inline void place(int row,int col,int set){
	int i,j;
	for(i=1;i<=N;i++) {// horizontal and vertical
		board[i][col]+=set;
		board[row][i]+=set;
	}
	board[row][col]-=set;
	for(i=1;i<=N-1;i++){
		for(j=0;j<4;j++){
			int new_row =row+dx[j]*i; 
			int new_col =col+dy[j]*i;
			if( inboard(new_row,new_col) )
				board[new_row][new_col]+=set;
		}
	}
}


/*
inline int valid(int r1,int r2){
	int c1=at[r1];
	int c2=at[r2];
	if( c1==c2 ) return 0; // same column
	// diagnal
	if( ABS(r1-r2) == ABS(c1-c2) ) return 0;
	return 1;
}

// check if the `depth' is compatable with others
inline int all_valid(int depth){
	int i;
	for(i=1;i<depth;i++){
		if( !valid(i,depth) ) return 0;
	}
	return 1;
}
*/

inline int search(int depth){
	if(depth > N){// valid placement
		if(out_count<3) {
			output();
			out_count++;
		}
		if( N%2 != 0 && at[1]==(N+1)/2 ) odd_count++;
		else sol_count++;
		return 1;
	}
	int i,j;
	for(i=1;i<=N;i++){
		if(depth==1 && i>(N+1)/2) break; // symmetry break
		if( board[depth][i] == 0 ){
			at[depth] = i;
			place(depth,i,1);
			search(depth+1);
			place(depth,i,-1);
			at[depth] = 0;
		}
	}
}

int main(){
	//freopen("checker.in","r",stdin);
	//freopen("checker.out","w",stdout);
	memset(board,0,sizeof(board));
	scanf("%d",&N);
	search(1);
	int total=sol_count*2+odd_count;

	printf("%d\n",total);
	return 0;
}
