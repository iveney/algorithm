// 模拟题
#include <stdio.h>
#include <string.h>

struct person
{
	int at;	// at which floor
	bool c;	// carry or not
	bool moved;	// this turn moved or not
};

int N,F,B;
int remain;
int f[1001];	// F floors,1 = carry box, 0 = don't carry, -1 = no one
		// 2 = two man in the same floor but one is moving up,one is moving down
		// 3 equals to 2,but the one moving down is handled

person p[1001];	// N people,p[i] indicate the ith person in which floor

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d%d%d",&N,&F,&B);
		int i;
		memset(f,-1,sizeof(f));
		memset(p,0,sizeof(p));
		remain = B;	// the boxes remain
		for(i=1;i<=N;i++)
		{// N lines of people
			int which;
			scanf("%d",&which);	// the person at which floor
			p[i].at = which;	// set the person's position
			f[which]=i;		// this floor has a person No.i
			int carry;
			scanf("%d",&carry); 	// carry box or not
			if(carry) 
			{
				remain++;
				p[i].c = true;
			}
		}
		int time=0;
		bool valid = false;
		while(remain > 0)
		{// simulate until all the boxes are finished
			for(i=1;i<=N;i++) p[i].moved = false;
			valid = false;
			for(i=1;i<=N;i++)
			{// for every person
				if(p[i].moved) continue;
				p[i].moved = true;
				if(p[i].at == 0)
				{// gets a box
					if(B)
					{// there's still box
						p[i].c = true;
						B--;
					}
					else continue;
				}
				else if( p[i].at == F )
				{// put down a box,note that it may took one more time to put down box
					// must check whether there's box not in F 
					p[i].c = false;
					remain--;
				}
			
				if(p[i].c)
				{// if he carries a box
					valid = true;
					int next = p[i].at+1;
					if(f[next] == -1)
					{// if there's no man in next floor
						p[i].at = next;	// move to next floor
					}
					else
					{// there's man in next floor 
						if(p[f[next]].c) // that man also carries box
							p[i].at = next;
						else
						{// that man doesn't have box,switch
							p[i].c = false;
							p[f[next]].c = true;
							p[f[next]].moved = true;
						}
					}
				}
				else
				{// if he does not carry
					int next = p[i].at - 1;
					if( next < 0 ) continue;	// finished
					if(f[next] == -1)
					{// if there's no man in next floor
						p[i].at = next;
					}
					else
					{// encounters some one who is in the next floor
						if( p[f[next]].c ) // if that man carries a box
						{// swtich box
							valid = true;
							p[i].c = true;
							p[f[next]].c = false;
							p[f[next]].moved = true;
						}
						else	// that man doesn't have box
							p[i].at = next;
					}
				}
			}	
			time++;
			printf("%d %d %d\n",time,remain,B);
		}
		if(valid == false) time--;
		printf("%d\n",time);
	}
	return 0;
}
