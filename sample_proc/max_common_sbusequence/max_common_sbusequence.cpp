// 两个串的最长公共子序列
#include <stdio.h>
#include <string.h>

#define MAX(a,b) \
	(((a)>(b))?(a):(b))

const int N = 1000;
char a[N];
char b[N];
int d[N+1][N+1];	// d[i][j] 表示ai与bj的最长公共子序列
int track[N+1][N+1];	// 记录回溯信息
int buf[N];		// 输出最长公共子序列的缓冲区

int main()
{
	FILE * f=freopen("data.in","r",stdin);
	fscanf(f,"%s%s",a,b);
	// init
	int i,j,lena,lenb;
	lena = strlen(a);
	lenb = strlen(b);
	printf("A: %s ; len = %d\nB: %s ; len = %d\n",a,lena,b,lenb);
	for(i=0;i<=lena;i++) d[i][0]=0;
	for(j=0;j<=lenb;j++) d[0][j]=0;
	for(i=1;i<=lena;i++)
	{
		for(j=1;j<=lenb;j++)
		{
			if( a[i-1]==b[j-1] )
			{// 注意a,b的下标从0开始表示第一个字符
				d[i][j] = d[i-1][j-1]+1;
				track[i][j]=0;
			}
			else
			{
				if(d[i-1][j]>=d[i][j-1])
				{
					d[i][j] = d[i-1][j];
					track[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i][j-1];
					track[i][j] = 2;
				}
			}

		}
	}
	int k=d[lena][lenb];
	buf[k]=0;
	i=lena;j=lenb;
	while(k>0)
	{// 该子序列有k位长
		if(track[i][j] == 0)
		{
			buf[k-1]=a[i-1];
			i--;j--;k--;
		}
		else if(track[i][j] == 1) i--;
		else j--;	
	}


	for(int i=0;i<d[lena][lenb];i++) printf("%c",buf[i]);
	printf(" : %d\n",d[lena][lenb]);	// 为什么用%s才输出一位?
	return 0;
}
