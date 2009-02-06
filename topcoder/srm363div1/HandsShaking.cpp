#include <stdio.h>

class HandsShaking{
public:
	long long countPerfect(int n){
		long long d[60];
		d[2]=1;
		int i;
		for(i=4;i<=n;i+=2){
			d[i]=3*d[i-2]-1;
		}
		return d[n];
	}
};

int main()
{
	return 0;
}
