/*
ID: iveney1 
LANG: C
TASK: zerosum
*/
#include <stdio.h>

int N;

void input(){
	scanf("%d\n",N);
}

int main(){
	freopen("zerosum.in","r",stdin);
#ifndef LOCAL
	freopen("zerosum.out","w",stdout);
#endif
	input();

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
