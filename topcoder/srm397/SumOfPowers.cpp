#include <iostream>
using namespace std;

class SumOfPowers{
public:
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

	int value(int n,int k){
		int mod = 1000000007;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum = (sum + mod_exp(i,k,mod)) % mod;
		}
		return sum;
	}
};

int main(){
	SumOfPowers s;
	int n,k;
	while(cin>>n>>k){
		cout<<s.value(n,k)<<endl;
	}
	return 0;
}
