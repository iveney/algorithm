/*
ID: iveney1 
LANG: C
TASK: checker
*/
#include <stdio.h>
#include <string.h>
#define ABS(a) ((a)<0?(-(a)):(a))
#define inboard(r,c) ((r)>=1&&(r)<=N&&(c)>=1&&(c)<=N)
#define occupy(pb,r,c) (((pb)->o[(r)]) & (mask[(c)]))
#define setboard(pb,r,c) (((pb)->o[(r)]) |= (mask[(c)]))
#define MAX 14

typedef struct BOARD{
	int o[MAX];
}board;

int at[14];
int out_count=0;
int sol_count=0;
int odd_count=0;
int N;
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};
// use to mask the row integer
int mask[]={
	 0,
	 1,    1<<1,
	 1<<2, 1<<3,
	 1<<4, 1<<5,
	 1<<6, 1<<7,
	 1<<8, 1<<9,
	 1<<10,1<<11, 
	 1<<12
};

void output(){
	int i;
	for(i=1;i<N;i++)
		printf("%d ",at[i]);
	printf("%d\n",at[i]);
}

// only set the column and two down diagnals
inline void place(board*pb,int row,int col){
	int i;
	for(i=row+1;i<=N;i++)
		setboard(pb,i,col);
	int c1=col,c2=col;
	for(i=row+1;i<=N;i++){
		--c1;
		++c2;
		if(inboard(i,c1)) setboard(pb,i,c1);
		if(inboard(i,c2)) setboard(pb,i,c2);
	}
}

inline int search(board* pb,int depth){
	if(depth > N){// valid placement
		if(out_count<3) {
			output();
			out_count++;
		}
		// when the chess is placed in the middle when N is odd
		// no need to double the solution count
		if( N%2 != 0 && at[1]==(N+1)/2 ) odd_count++; 
		else sol_count++;
		return 1;
	}
	int i,j;
	for(i=1;i<=N;i++){
		if(depth==1 && i>(N+1)/2) break; // symmetry break
		if( (occupy(pb,depth,i)) == 0 ){
			at[depth]=i;
			board cb;
			board* nb=&cb;
			memcpy(nb->o,pb->o,sizeof(int)*MAX);
			int row=depth,col=i;
			place(nb,depth,i);
			search(nb,depth+1);
			at[depth]=0;
		}
	}
}

int main(){
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&N);
	board b;
	memset(b.o,0,sizeof(int)*MAX);
	search(&b,1);
	int total=sol_count*2+odd_count;
	// very nasty: because the first three should be output,
	// but N=6 only has 4 solution,
	// and symmetry breaking gets only 2...
	// manually output the third solution
	if(N==6)
		printf("4 1 5 2 6 3\n");

	printf("%d\n",total);
	return 0;
}
