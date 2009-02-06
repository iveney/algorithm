#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);


	for(int i=0;i<n;i++)
	{
		char str[2000];
		char out[3000];
		scanf("%s",str);
		int len=strlen(str);
		int pos=0;
		int count=1;
		char now,pre=str[0];
		for(int j=1;j<len;j++)
		{
			now = str[j];
			if( now == pre )
			{
				count++;
			}
			else
			{// write to output string
				pos += sprintf(out+pos,"%d%c",count,pre);
				count = 1;
			}
			pre = now;
		}
		pos += sprintf(out+pos,"%d%c",count,pre);
		printf("%s\n",out);
	}
	return 0;
}