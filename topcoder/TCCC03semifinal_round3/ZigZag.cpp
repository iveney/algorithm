#include <vector>
using std::vector;
int s[51];
int n;
int A[51],B[51];
int id[51];
int dirA[51];
int dirB[51];
int max(int a,int b){return (a>b)?a:b;}

class ZigZag{
public:
	int longestZigZag(vector<int> sequence){
		int i,j;
		A[0]=B[0]=0;A[1]=B[1]=1;A[2]=B[2]=2;
		id[0]=-1;id[1]=1;id[2]=2;
		/*
		if( n<=2 ){
			printf("%d",A[n]);
			return 0;
		}
		*/
		dirA[0]=dirB[0]=0;
		dirA[1]=dirB[1]=0;
		dirA[2]=dirB[2]=s[2]-s[1];
		for(i=3;i<=n;i++)
		{
			// update A[i]
			if( A[i-1] > B[i-1] )
			{
				id[i] = id[i-1];
				A[i] = A[i-1];
				dirA[i] = dirA[i-1];
			}
			else
			{
				id[i] = i-1;
				A[i]=B[i-1];
				dirA[i] = dirB[i-1];
			}
			int max=1;
			int idx=-1;
			int use=0; // -1 for A, 1 for B
			for(j=1;j<=i-1;j++)
			{
				// for A, e.g.   10,15,s[i]
				if( dirB[j]>0 && s[i]-s[id[j]] < 0 ||
						dirB[j]<0 && s[i]-s[id[j]] > 0 )
				{
					if( max<A[j]+1 ){
						idx=j;
						max=A[j]+1;
						use=-1;
					}
				}
				// for B
				if( dirB[j]>0 && s[i]-s[j] < 0 ||
						dirB[j]<0 && s[i]-s[j] > 0 ){
					if( max<B[j]+1 ){
						max=B[j]+1;
						use=1;
					}
				}

			}
			B[i]=max;
			if(use==-1){// use A
				id[i]=idx;
				dirB[i]=s[i]-s[id[idx]];
			}
			else if (use==1){// use B
				dirB[i]=s[i]-s[i-1];
			}
		}
		/*
		for(i=1;i<=n;i++)
			printf("[%d] :\t %d\t%d\t%d\t%d\n",i,A[i],B[i],dirA[i],dirB[i]);
			*/
		int max=2;
		for(i=1;i<=n;i++)
		{
			if( max < A[i] ) max=A[i];
			if( max < B[i] ) max=B[i];
		}
		//printf("%d\n",max);
		return max;
	}
};

int main()
{
	freopen("data.in","r",stdin);
	int i,j;
	/*
	   for(i=1;i<=n;i++) 
	   {
	   scanf("%d",&s[i]);
	   A[i]=B[i]=2;
	   }
	   */
	n=0;
	int t;
	while( scanf("%d",&t) != EOF ) {
		n++;
		s[n]=t;
		A[n]=B[n]=2;
	}
	printf("%d\n",n);
	A[0]=B[0]=0;A[1]=B[1]=1;A[2]=B[2]=2;
	id[0]=-1;id[1]=1;id[2]=2;
	if( n<=2 ){
		printf("%d",A[n]);
		return 0;
	}
	dirA[0]=dirB[0]=0;
	dirA[1]=dirB[1]=0;
	dirA[2]=dirB[2]=s[2]-s[1];
	for(i=3;i<=n;i++)
	{
		// update A[i]
		if( A[i-1] > B[i-1] )
		{
			id[i] = id[i-1];
			A[i] = A[i-1];
			dirA[i] = dirA[i-1];
		}
		else
		{
			id[i] = i-1;
			A[i]=B[i-1];
			dirA[i] = dirB[i-1];
		}
		int max=1;
		int idx=-1;
		int use=0; // -1 for A, 1 for B
		for(j=1;j<=i-1;j++)
		{
			// for A, e.g.   10,15,s[i]
			if( dirB[j]>0 && s[i]-s[id[j]] < 0 ||
					dirB[j]<0 && s[i]-s[id[j]] > 0 )
			{
				if( max<A[j]+1 ){
					idx=j;
					max=A[j]+1;
					use=-1;
				}
			}
			// for B
			if( dirB[j]>0 && s[i]-s[j] < 0 ||
					dirB[j]<0 && s[i]-s[j] > 0 ){
				if( max<B[j]+1 ){
					max=B[j]+1;
					use=1;
				}
			}

		}
		B[i]=max;
		if(use==-1){// use A
			id[i]=idx;
			dirB[i]=s[i]-s[id[idx]];
		}
		else if (use==1){// use B
			dirB[i]=s[i]-s[i-1];
		}
	}
	for(i=1;i<=n;i++)
		printf("[%d] :\t %d\t%d\t%d\t%d\n",i,A[i],B[i],dirA[i],dirB[i]);
	int max=2;
	for(i=1;i<=n;i++)
	{
		if( max < A[i] ) max=A[i];
		if( max < B[i] ) max=B[i];
	}
	printf("%d\n",max);
	return 0;
}
