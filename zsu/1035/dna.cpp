#include <stdio.h>
#include <string.h>
const int N=105;
char dna[N][N];

bool cmp(char a[],char b[])
{
	int i=0;
	while(a[i]!='\0' && b[i]!='\0')
	{
		switch(a[i])
		{
			case 'A':if(b[i]!='T')return false;
				break;
			case 'T':if(b[i]!='A')return false;
				break;
			case 'C':if(b[i]!='G')return false;
				break;
			case 'G':if(b[i]!='C')return false;
				break;
		}
		i++;
	}
	if(a[i] == '\0' && b[i] == '\0')
	{// they matched
//		printf("%s\n%s\n",a,b);
		a[0]=b[0]='\0';	// set as used
		return true;	
	}
	return false;
}

int main()
{
	int i,j;
	int n,T;
	unsigned int match=0;
	FILE * f = stdin;// freopen("data","r",stdin);
	fscanf(f,"%d",&T);
	for(int count=0;count<T;++count)
	{
		match=0;
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%s",dna[i]);
			for(int j=0;j<i;j++)
			{
				if(cmp(dna[j],dna[i])) 
				{
					match++;
					break;
				}
			}
		}
		printf("%d\n",match);
	}
	return 0;
}
