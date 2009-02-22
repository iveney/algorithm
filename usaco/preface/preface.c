/*
ID: iveney1 
LANG: C
TASK: preface
*/
#include <stdio.h>

char * num_str[]={"","I","V","X","L","C","D","M"};
enum NUM{DUMMY,I,V,X,L,C,D,M};
int N;
int c[8];
/*
int n[9][4][8]={
};
*/

int inc(int x){
	int base=0;
	while(x > 0){
		int d = x%10;
		//printf("d=%d\n",d);
		x=x/10;
		switch(d){
		case 0:break;
		case 3: c[base+I]++;
		case 2: c[base+I]++;
		case 1: c[base+I]++;
			break;
		case 9: c[base+X]++;
			c[base+I]++;
			break;
			c[base+V]++;
		case 8: c[base+I]++;
		case 7: c[base+I]++; 
		case 4:
		case 6: c[base+I]++;  
		default:c[base+V]++;
			break;
		}
		base += 2;
	}
	return 0;
}

void output(){
	int i;
	for(i=1;i<8;i++)
		if(c[i]>0)
			printf("%s %d\n",num_str[i],c[i]);
}

int main(){
	freopen("preface.in","r",stdin);
#ifndef LOCAL
	freopen("preface.out","w",stdout);
#endif
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
		inc(i);
	output();

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
