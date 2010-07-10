/*
ID: iveney1 
LANG: C
TASK: prefix
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char list[205][12];
int list_size=0;
int str_len[205];
char S[200005];
int s_size=0;
char buf[80];

int len[200005];

void input(){
	do{// input the list
		int ret = scanf("%s",list[list_size]);
		//printf("%d\n",ret);
		if( strcmp(list[list_size],".") == 0 )
			break;
		//printf("%s\n",list[list_size]);
		str_len[list_size] = strlen(list[list_size]);
		list_size++;
	}while(1); 

	do{// input the S
		int ret = scanf("%s",buf);
		if( ret == EOF )
			break;
		int l = strlen(buf);
		strcpy(&S[s_size],buf);
		s_size+=l;
	}while(1);
	//printf("%s\n",S);
}

int main(){
	
#ifdef LOCAL
	freopen("prefix.in3","r",stdin);
#else
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
#endif
	input();
	//memset(len,0,sizeof(len));

	int i,j;
	for(i=0;i<s_size;i++){
		char c = S[i];  // current last char
		int max=0;
		if( i != 0 ) max = len[i-1];
		// search for a matching primitive
		for(j=0;j<list_size;j++){
			int l = str_len[j];
			int lid = str_len[j]-1;
			if( i+1-l >= 0 && 
			    strncmp(list[j],&S[i-l+1],l) == 0 ) {
				// special case for the 1st character
				if( i==0 ) { max = 1;break; }
				if( len[i-l] == i-l+1 && len[i-l] + l > max )
					max = len[i-l]+l;
			}
		}
		len[i] = max;
	}


#ifdef LOCAL
	for(i=0;i<s_size;i++){
		printf("%d\n",len[i]);
	}
#else
	printf("%d\n",len[s_size-1]);
#endif
	return 0;
}
