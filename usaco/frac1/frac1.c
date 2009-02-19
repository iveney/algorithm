/*
ID: iveney1 
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 10E-7
#define ABS(a) ((a)>0?(a):-(a))
#define EQUAL(a,b) (ABS((a)-(b))<EPSILON)
#define MAX 161

typedef struct{
	int a,b;
	double value;
}FRAC;

FRAC fracs[MAX*MAX];
int size=0;
int N;

int cmp(const void *s, const void *t){
	FRAC* pa =((FRAC*)s); 
	FRAC* pb =((FRAC*)t); 
	double x=pa->value;
	double y=pb->value;
	if( EQUAL(x,y) ) {
		return (pa->a) - (pb->a);
	}
	if((x-y)>EPSILON) return 1;
	return -1;
}

int main(){
	freopen("frac1.in","r",stdin);
#ifndef LOCAL
	freopen("frac1.out","w",stdout);
#endif
	scanf("%d",&N);
	// special: 0 1
	FRAC tmp;
	tmp.a = 0;tmp.b=1;
	tmp.value=0.0;
	fracs[size++] = tmp;
	tmp.a = 1;
	tmp.value=1.0;
	fracs[size++] = tmp;

	int i,j;
	for(j=N;j>=1;j--){
		for(i=1;i<j;i++){
			tmp.a = i;tmp.b = j;
			tmp.value = (double)i/(double)j;
			fracs[size++] = tmp;
		}
	}
	qsort(fracs,size,sizeof(FRAC),cmp);
	double p=-1.0,q=-2.0;
	for(i=0;i<size;i++){
		q = p;
		p = fracs[i].value;
		if( EQUAL(p,q) ) continue;
		printf("%d/%d\n",fracs[i].a,fracs[i].b);
	}

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
