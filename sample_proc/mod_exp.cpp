// compute modular exponentiation: a^b mod n
#include <iostream>
using namespace std;

// input: a>=0 b>=0 n>0
// output: remainder of a^b mod n
unsigned int mod_exp(unsigned int a,unsigned int b,unsigned int n){
	unsigned int d=1;
	unsigned int c=0x80000000;// 31b set to 1, others 0
	// search for the first non-zero bit of b
	while( (c&b) == 0 ) c>>=1;
	// traverse all the bit of b
	while(c>0){
		d = (d*d)%n;
		if( (c&b) > 0){// current bit is 1
			d = (d*a)%n;
		}
		c>>=1;
	}
	return d;
}

int main(){
	unsigned int a,b,n;
	while(cin>>a>>b>>n){
		cout<<mod_exp(a,b,n)<<endl;
	}
	return 0;
}
