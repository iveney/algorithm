/*
ID: iveney1
PROG: transform
LANG: C++
*/
#include <cstdio>
using namespace std;

FILE* in ;
FILE* out;

int N;
int before_mat[15][15],after_mat[15][15];
int before,after;

struct node
{
	int value;
	int step;
	int parent;
	int kind;
	void set(int v,int s,int p,int k){value = v;step = s;parent=p;kind=k;}
	node(){set(0,0,-1,0);}
	node(int v,int s,int p,int k){set(v,s,p,k);}
};

node q[1000];
int head = -1,tail=0;

int zip(int mat[15][15])
{
	int i,j,base = 1,result = 0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			result += base * mat[i][j];
			base *= 2;
		}
	return result;
}

int ** unzip(int from,int mat[15][15])
{
	int i,j,base = 1;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			mat[i][j] = from%2;
			from /= 2;
		}
	return (int**)mat;
}

void input()
{
	fscanf(in,"%d\n",&N);
	int i,j;
	char ch;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fscanf(in,"%c",&ch);
			if(ch=='@') before_mat[i][j] = 1;
			else before_mat[i][j] = 0;
		}
		fscanf(in,"\n");
	}
	before = zip(before_mat);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fscanf(in,"%c",&ch);
			if(ch=='@') after_mat[i][j] = 1;
			else after_mat[i][j] = 0;
		}
		fscanf(in,"\n");
	}
	after = zip(after_mat);
}

void output(int mat[15][15])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}



int rot90(int mat)
{
	int result = 0,base = 1;
	int m[15][15];//,m2[15][15];
	unzip(mat,m);
	//unzip(mat,m2);	
	int i,j;
	for(j=0;j<N;j++)
	{
		for(i=N-1;i>=0;i--)
		{
			result+= base * m[i][j];
			base *= 2;
		}
	}
	return result;
}

int rot180(int mat){return rot90(rot90(mat));}
int rot270(int mat){return rot180(rot90(mat));}

int reflect(int mat)
{
	int result = 0,base = 1;
	int m[15][15];
	unzip(mat,m);
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=N-1;j>=0;j--)
		{
			result+= base * m[i][j];
			base *= 2;
		}
	}
	return result;
}

int search(int level)
{
	if(head == tail) return -1;
	int origin = q[head++].value;

	int r90 = rot90(origin);
	q[tail++] = node(r90,level+1,head-1,1);
	if(r90 == after) return level;

	int r180 = rot90(r90);
	q[tail++] = node(r180,level+1,head-1,2);
	if(r180 == after) return level;

	int r270 = rot90(r180);
	q[tail++] = node(r270,level+1,head-1,3);
	if(r270 == after) return level;

	int r = reflect(origin);
	q[tail++] = node(r,level+1,head-1,4);
	if(r == after) return level;

	return search(level+1);
}

int main() {
    in = fopen("transform.in","r");
	out = fopen("transform.out","w");
	input();
	printf("%d\n%d\n",before,after);
	if(before == after) fprintf(out,"6\n");

	q[++head] = node(before,0,-1,-1);
	tail++;
	int value = search(0);
	if(value == -1) fprintf(out,"7\n");
	else
	{
		node cur = q[head],pre;
		while( cur.parent != -1)
		{
			fprintf(out,"%d<-",cur.kind);
			cur=q[cur.parent];
		}
	}
	fprintf(out,"\n");		

    return 0;
}