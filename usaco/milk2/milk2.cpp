/*
ID: iveney1
PROG: milk2
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

struct seg
{
	int b,e;
}s[5001];

struct point
{
	int v;
	bool head;
	int belongs;
}pts[10020];

int cmp(const void *a,const void *b)
{
	point * pa=(point*)a;
	point * pb=(point*)b;
	int ret = pa->v - pb->v;
	if(ret == 0)
	{
		if( pa->head && !pb->head)
			ret = -1;
		else if( !pa->head && pb->head )
			ret = 1;
		else
			ret = 1;
	}
	return ret;
}

int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);

	int N;
	scanf("%d",&N);
	int i = N;
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&s[i].b,&s[i].e);
		pts[2*i].v = s[i].b;
		pts[2*i].head = true;
		pts[2*i+1].v = s[i].e;
		pts[2*i+1].head = false;
		pts[2*i].belongs = pts[2*i+1].belongs = i;
	}

	qsort(pts,N*2,sizeof(point),cmp);

	int maxlong = 0,maxinter = 0;
	int count = 0;
	int start=0,end=0;
	int no_start=0,no_end=0;
	for(i=0;i<2*N;i++)
	{
		if( pts[i].head == true )
		{
			if(count == 0)
			{
				start = i;
				no_end = i;
				int dist = pts[no_end].v-pts[no_start].v;
				if( dist > maxinter )
					maxinter = dist;
			}
			count++;
		}
		else
		{
			count--;
			if(count == 0)
			{
				end = i;
				no_start = i;
				int dist = pts[end].v - pts[start].v;
				if( dist > maxlong )
					maxlong = dist;
			}
		}
	}

	printf("%d %d\n",maxlong,maxinter);

	/*
	for(i=0;i<2*N;i++)
		printf("%d\t%d\n",pts[i].v,pts[i].belongs);
	*/
	return 0;
}
