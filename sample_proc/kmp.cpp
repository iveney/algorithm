#include <stdio.h>
#include <string.h>

void getNext(const char * pattern,int next[])
{
	int k=0,j=0;
	int len = strlen(pattern);
	next[j]=-1;
	for(j=1;j<len;j++)
	{
		k=next[j-1];
		while( (pattern[k+1]!=pattern[j]) && k>=0 ) 
			k=next[k];
		if( pattern[k+1] == pattern[j] )
			next[j]=k+1;
		else
			next[j]=-1;
	}
}

int kmp(const char * target,const char * pattern,int next[])
{
	int i=0,j=0;
	int m=strlen(target);
	int n=strlen(pattern);
	while(i<m && j<n)
	{
	/*	if(j==-1 || target[i] == pattern[j])
		{
			i++;j++;
		}
		else 
			j=next[j];
*/
		if(pattern[j]==target[i])
		{
			i++;j++;
		}
		else if(j==0)i++;
		else j=next[j-1]+1;
	}
	if(j<n)return -1;
	else return i-n;
}

int match(const char * target,const char * pattern)
{
	int n=strlen(pattern);
	int * next = new int[n];
	getNext(pattern,next);
	for(int i=0;i<n;i++) printf("%d ",next[i]);
	printf("\n");
	int pos = kmp(target,pattern,next);
	delete [] next;
	return pos;
}

int main()
{
	const int SIZE=80;
	char target[SIZE]="ababc";
	char pattern[SIZE]="abaabcaba";
	printf("Target:");
	scanf("%s",target);
	printf("Pattern:");
	scanf("%s",pattern);
	int pos=match(target,pattern);
	printf("%d\n",pos);
	return 0;
}
