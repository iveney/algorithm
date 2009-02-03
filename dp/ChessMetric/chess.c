/* http://www.topcoder.com/stat?c=problem_statement&pm=1592&rd=4482 */

#include <stdio.h>
#include <string.h>

#define MAX 105
#define MAX_MOVE 51
typedef unsigned long long int64 ;

const int n=100;
const int si=99;
const int sj=99;
const int ti=0;
const int tj=0;
const int move=50;

int64 board[MAX_MOVE][MAX][MAX];

int bound(int i,int j){
	if( i>=0 && i<=n-1 &&
	    j>=0 && j<=n-1)
		return 1;
	else
		return 0;
}

int64 check(int k,int i,int j){
	if( bound(i,j) )
		return board[k][i][j];
	else
		return 0; 
}

int main()
{
	memset(board,0,sizeof(board));
	int i,j,k;
	board[0][si][sj]=1;
	for(k=1;k<=move;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				int64 count=0;
				count+=check(k-1,i-1,j-1);
				count+=check(k-1,i-1,j);
				count+=check(k-1,i-1,j+1);
				count+=check(k-1,i,j-1);
				count+=check(k-1,i,j+1);
				count+=check(k-1,i+1,j-1);
				count+=check(k-1,i+1,j);
				count+=check(k-1,i+1,j+1);

				count+=check(k-1,i-1,j-2);
				count+=check(k-1,i-2,j-1);
				count+=check(k-1,i-2,j+1);
				count+=check(k-1,i-1,j+2);

				count+=check(k-1,i+1,j-2);
				count+=check(k-1,i+2,j-1);
				count+=check(k-1,i+2,j+1);
				count+=check(k-1,i+1,j+2);
				board[k][i][j]=count;
			}
		}
	}
	printf("%lld\n",board[move][ti][tj]);
	return 0;
}
