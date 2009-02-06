/*
ID: iveney1
PROG: clocks
LANG: C++
*/

#include <stdio.h>
#include <string.h>


int begin[3][3];
const int target[3][3] = {
	{12,12,12},
	{12,12,12},
	{12,12,12}
};
int trace[100];
int tlen=0;

char count[10];

void input()
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&begin[i][j]);
}

char * list[]={
	"",	// count from zero
	"ABDE",	// 1
	"ABC",
	"BCEF",
	"ADG",
	"BDEFH",
	"CFI",
	"DEGH",
	"GHI",
	"EFHI", // 9
};

void move(int type,int mat[][3])
{
	int len = strlen(list[type]);
	for(int i=0;i<len;i++)
	{
		char ch = list[type][i];
		int temp = ch-'A';
		int row = temp/3;
		int col = temp%3;
		int t = mat[row][col];
		switch(t)
		{
		case 3:t=6;break;
		case 6:t=9;break;
		case 9:t=12;break;
		case 12:t=3;break;
		}
		mat[row][col]=t;
	}
}

void output(int mat[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%3d",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

bool equals(const int l[][3],const int r[][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(l[i][j] != r[i][j])
				return false;
	return true;
}

void cp(const int src[][3],int dest[][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j] = src[i][j];
}

int dfs(int mat[][3],int level)
{
	if(level == 0) return 0;
	if(equals(mat,target))
	{
		//trace[tlen++] = type;
		return 1;
	}

	for(int i=1;i<=9;i++)
	{
		if(count[i] == 3)
			continue;
		count[i]++;
		int next[3][3];
		cp(mat,next);
		move(i,next);	// do transform
		int result = dfs(next,level-1);
		count[i]--;

		if( result == 1 )
		{
			trace[tlen++] = i;
			return 1;
		}
	}

	return 0;
}

int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	input();
	int level=1;
	int result;
	do
	{
	//	memset(count,0,sizeof(count));
		result = dfs(begin,level);
		level++;
	}while(result != 1);
	
	printf("%d",trace[tlen-1]);
	for(int i=tlen-2;i>=0;i--)
		printf(" %d",trace[i]);
	printf("\n");
	/*
	output(begin);
	move(5,begin);
	output(begin);
	move(8,begin);
	output(begin);
	move(4,begin);
	output(begin);
	move(9,begin);
	output(begin);
	printf("%d\n",equals(begin,target));
	*/
	return 0;
}