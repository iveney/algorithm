#include <stdio.h>
#include <string.h>
int len;
int before[15];
int after[15];
char mark[1<<24];			// 用于hash的数组
const int QLEN = 200000;	// 广搜队列长度

int bval,eval;

struct node
{// 广搜树节点
	int value;
	int level;
};
node q[QLEN];
int b,e;	// queue and its head,tail

void inc(int & p)
{// 使用循环队列的方法来保存节点
	if(++p == QLEN) p=0;
}

int zip(int * gene)
{// 状态压缩
	int result = 0,base = 1,i,j;
	for(i=len-1;i>=0;i--)
		result |= gene[i]<<((len-i-1)*2);
	return result;
}

int * unzip(int zipped,int * gene)
{// 解压缩
	int i;
	for(i=0;i<len;i++)
	{
		gene[i] = (zipped>>(len-i-1)*2)&3;
	}
	return gene;
}

int op1(int gene)
{// 对应题目的第一个操作
	int first = (gene>>(len-1)*2)&3;
	int second = (gene>>(len-2)*2)&3;
	int mask = (1<<(len*2))-1;	// for len=4, 11 11 11 11
	int mask1 = ~(3<<(len-1)*2) & mask; // for len=4, 00 11 11 11
	int mask2 = ~(3<<(len-2)*2) & mask; // for len=4, 11 00 11 11
	gene &= mask1;
	gene &= mask2;
	gene |= first<<(len-2)*2;
	gene |= second<<(len-1)*2;
	return gene;
}

int op2(int gene)
{// 对应题目的第二个操作
	int first = (gene>>(len-1)*2)&3;
	int m = (1<<(len*2))-1;			 // for len=4, 11 11 11 11
	int mask = ~(3<<(len-1)*2) & m;  // for len=4, 00 11 11 11
	gene = (gene&mask) <<2;
	gene |= first;
	return gene;
}

void getGene(int * gene)
{// 输入gene
	char ch;
	for(int i=0;i<len;i++)
	{
		scanf("%c",&ch);
		switch(ch)
		{
		case 'A':gene[i] = 0;break;
		case 'C':gene[i] = 1;break;
		case 'G':gene[i] = 2;break;
		case 'T':gene[i] = 3;break;
		}
	}
	scanf("\n");
}

int search()
{// 进行搜索，返回结果所在的层数，就是所需要的最短步数
	while( b!=e )
	{
		node n = q[b]; // de-queue
		inc(b);
		if( n.value == eval ) return n.level;
		
		node temp;
		temp.value = op1(n.value);
		temp.level = n.level + 1;
		if( temp.value == eval ) return temp.level;
		if( mark[temp.value] != 1)
		{// en-queue
			q[e] = temp;
			inc(e);
			mark[temp.value] = 1;
		}

		temp.value = op2(n.value);
		temp.level = n.level + 1;
		if( temp.value == eval ) return temp.level;
		if( mark[temp.value] != 1) 
		{// en-queue
			q[e] = temp;
			inc(e);
			mark[temp.value] = 1;
		}
	}
	return -1;
}

int main()
{
	freopen("order.in","r",stdin);
	while( scanf("%d\n",&len) != EOF)
	{
		memset(mark,0,sizeof(mark));
		b=0;e=0;
		getGene(before);
		getGene(after);

		bval = zip(before);
		eval = zip(after);
		node temp;
		temp.value = bval;
		temp.level = 0;
		q[b] = temp;	// 把初始状态压入队列
		inc(e);
		mark[bval] = 1;

		int result = search();
		printf("%d\n",result);
	}
	return 0;
}