// recursive Euclid and non-recursive Euclid
// GCD recursion theorem:
// gcd(a,b) = gcd(b, a mod b)
//
// gcd(a,b) = gcd(|a|,|b|)
#include <stdio.h>
#define abs(x) (x<0?(-x):(x))

// recursive version of Euclid
// @parameter
// a: integer
// b: integer
// return their greatest common divisor
int euclid_recur(int a,int b){
	a=abs(a);
	b=abs(b);
	if( b == 0 )
		return a; // gcd(a,0) = a
	return euclid_recur(b,a % b);
}

// same as euclid_recur, but iterative
int euclid_nonrecur(int a,int b){
	a=abs(a);
	b=abs(b);
	if( a < b ){
		int t = a;
		a=b;
		b=t;
	}
	while( b != 0 ){
		int t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main(){
	int a,b;
	while( scanf("%d%d",&a,&b) != EOF ){
		printf("%d\n",euclid_nonrecur(a,b));
	}
	return 0;
}
