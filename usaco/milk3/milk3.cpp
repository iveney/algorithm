/*
ID: iveney1
PROG: milk3
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>

struct state
{
	int buck[3];
};
state full;
state from;

const int QSIZE = 10000;
int q[QSIZE];
int b=0,e=0;
char hash[10000];

state result[QSIZE];
int rsize=0;

bool equals(const state & l,const state & r)
{return l.buck[0] == r.buck[0] && l.buck[1] == r.buck[1] && l.buck[2] == r.buck[2];}

void insert(const state & s)
{
	for(int i=0;i<rsize;i++)
		if( equals(result[i],s) )
			return;
	result[rsize++]=s;
}

void inc(int & a)
{if(++a >= QSIZE) a=0;}

int zip(const state & s)
{return s.buck[0]*441+s.buck[1]*21+s.buck[2];}

void unzip(const int z,state &s)
{
	int zipped = z;
	s.buck[2] = zipped%21;	zipped/=21;
	s.buck[1] = zipped%21;	zipped/=21;
	s.buck[0] = zipped;
}

// we call it success when bucket A is empty
bool success(const state & s)
{return (s.buck[0] == 0);}

bool pour(int src,int dest,state & s)
{
	// 0=A,1=B,2=C
	if( s.buck[src] > 0 && s.buck[dest] < full.buck[dest] )
	{// src not empty and dest not full
		int destLeft = full.buck[dest] - s.buck[dest];
		if( destLeft >= s.buck[src] )
		{// pour all from src to dest 
			s.buck[dest]+=s.buck[src];
			s.buck[src] = 0;
		}
		else
		{// pour part from src to dest
			int minus = s.buck[src] - destLeft;
			s.buck[src]=minus;
			s.buck[dest]=full.buck[dest];
		}
		return true;
	}
	return false;
}

void search()
{
	while(b != e)
	{// generate all possible case
		int now = q[b];	// de-queue
		inc(b);
		state s;
		unzip(now,s);
		if( success(s) )	// if it qualifies the success state
			insert(s);

		state change1,change2;
		int i,j;
		for(i=0;i<=1;i++)
		{// generate all 6 possible pour method
			for(j=i+1;j<=2;j++)
			{
				unzip(now,change1);
				if( pour(i,j,change1) == true)
				{// pour success
					int temp = 	zip(change1);
					if( hash[temp] == 0)
					{
						hash[temp] = 1;	// mark as searched
						q[e] = temp;	// en-queue
						inc(e);
					}
				}

				unzip(now,change2);
				if( pour(j,i,change2) == true)
				{// pour success
					int temp = 	zip(change2);
					if( hash[temp] == 0)
					{
						hash[temp] = 1;	// mark as searched
						q[e] = temp;	// en-queue
						inc(e);
					}
				}
			}
		}
	}
}

// sort the result state accoring to bucket C
int cmp(const void * a,const void * b)
{return ((state*)a)->buck[2] - ((state*)b)->buck[2];}

void output()
{
	printf("%d",result[0].buck[2]);
	int i;
	for(i=1;i<rsize;i++)
		printf(" %d",result[i].buck[2]);
	printf("\n");
}

int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&full.buck[0],&full.buck[1],&full.buck[2]);

	from.buck[2] = full.buck[2];	// set A,B to empty,C to full
	int init = zip(from);
	q[e] = init;	// en-queue the initial state
	inc(e);
	search();		// do search
	qsort(result,rsize,sizeof(state),cmp);	// output in order
	output();

	return 0;
}