/*
ID: iveney1 
LANG: C
TASK: hamming
*/
#include <stdio.h>

int hamdist(int a,int b){
	int c = a^b;
	int i,n=0;
	for(i=0;i<8;i++){
		if( (c & 1) ) n++;
		c>>=1;
	}
	return n;
}

int N,B,D;

int main(){
	freopen("hamming.in","r",stdin);
#ifndef LOCAL
	freopen("hamming.out","w",stdout);
#endif
	scanf("%d%d%d",&N,&B,&D);

	int i;

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
