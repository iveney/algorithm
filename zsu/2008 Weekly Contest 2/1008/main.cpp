#include <stdio.h>
#include <string.h>

int len[]=
{
2,
4,
9,
19,
39,
79,
159,
319,
639,
1279,
2559,
5119,
10239,
20479,
40959,
81919,
};


void _gen(int n)
{
	printf("{");
	if(n>0)
	{
		int i;
		for(i=0;i<n-1;i++)
		{
			_gen(i);
			printf(",");
		}
		_gen(n-1);
	}
	printf("}");
}

void gen(int n)
{
	_gen(n);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char a[100000];
		char b[100000];
		scanf("%s\n%s",a,b);

		int lena = strlen(a);
		int lenb = strlen(b);
		int first,second;
		for(int j=0;j<=15;j++)
		{
			if( len[j] == lena )
				first = j;
			if( len[j] == lenb )
				second = j;
		}
		gen(first+second);
		//printf("%s\n",sum);
	}
	return 0;
}



/*

int pos = 0 ;
char table[200000];



void _gen(int n)
{
	pos += sprintf(table+pos,"{");
	if(n>0)
	{
		int i;
		for(i=0;i<n-1;i++)
		{
			_gen(i);
			pos += sprintf(table+pos,",");
		}
		_gen(n-1);
	}
	pos += sprintf(table+pos,"}");
}

void gen(int n)
{
	_gen(n);
	//sprintf(table+pos,"\n");
}

int main()
{
	int n;
	for(int j=0;j<=15;j++)
	{
		memset(table,0,sizeof(table));
		pos=0;
		gen(j);
		printf("%d,\n",strlen(table));
	}
	//scanf("%d",&n);
	//for(int i=0;i<n;i++)
	//{
	//	char a[1000];
	//	char b[1000];
	//	char sum[1000];
	//	//scanf("%s\n%s",a,b);

	//	//printf("%s\n",sum);
	//}
	return 0;
}
*/