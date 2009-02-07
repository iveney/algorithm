/* http://www.topcoder.com/stat?c=problem_statement&pm=1592&rd=4482 */

#include <vector>
#include <iostream>
using namespace std;
const int MAX= 105;
const int MAX_MOVE=51;
const int n=100;
const int si=99;
const int sj=99;
const int ti=0;
const int tj=0;
const int move=50;

class ChessMetric{
public:
	long long howMany(int size, vector<int> start,vector<int> end,int numMoves){
		memset(board,0,sizeof(board));
		int i,j,k;
		board[0][si][sj]=1;
		for(k=1;k<=move;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					long long count=0;
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
		return board[move][ti][tj];
	}

	int bound(int i,int j){
		if( i>=0 && i<=n-1 &&
				j>=0 && j<=n-1)
			return 1;
		else
			return 0;
	}

	long long check(int k,int i,int j){
		if( bound(i,j) )
			return board[k][i][j];
		else
			return 0; 
	}
	long long board[MAX_MOVE][MAX][MAX];
};
