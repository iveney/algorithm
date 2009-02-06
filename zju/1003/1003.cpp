#include <stdio.h>
#include <string.h>

void swap(int & a, int & b){
     int c = a;
        a = b;
        b = c;
}

int gcd(int a,int b){
     if(0 == a ){
         return b;
     }
     if( 0 == b){
         return a;
     }
     if(a > b){
         swap(a,b);
     }
     int c;
     for(c = a % b ; c > 0 ; c = a % b){
            a = b;
            b = c;
     }
     return b;
}

int main()
{
	bool a =3.5 & 2.0;
	return 0;
}

/*

void   factor(int   f[],   int   num)//   f[]是存储因子的数组，num是待分解的数  
{  
	int   i=2;  
	int   temp;  

	temp=num;  

	while(temp!=1)  
	{  
		if(temp%i==0)  
		{  
			f[temp]=i;  
			temp/=i;  
		}  
		else  
			i++;  
	}  

	for(i=0;f[i]!=0;i++)  
		printf("%d\n",f[i]);  
} 
		int a,b;
		int fa[101],fb[101];
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		sscanf(line,"%d %d",&a,&b);
		if( a > 100 * 99 )
		{
			if( b > 100 * 99 )
				printf("%d\n",a);
			else
				printf("%d\n",b);
		}
		else if ( b > 100 * 99 )
			printf("%d\n",a);
		else
		{
			factor(fa,a);
			factor(fb,b);
			for(int i=2;i<=100;i++)
			{
				if(fa[i] == 1 && fb[i] == 1)
					printf("%d\n",b);
			}
			printf("%d\n",a);
		}
*/