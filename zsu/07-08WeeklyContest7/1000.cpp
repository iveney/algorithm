#include <stdio.h>
#include <string.h>

char * s1="successful hashing\n";
char * s2="rehash necessary\n";

int m,n;
int hash[10000][2];
int value[10000];
int parent[10000];

int insert(int val,int pos)
{
	int pos2=hash[val][1];
	if( value[pos] == -1) value[pos] = val;
	else if( value[pos2] == -1 ) value[pos2] = val;
	else{// both bucket is full...
		if( parent[pos] == val )	// check if there's circulation
			return -1;
		int change = value[pos];	// the element that was evicted
		parent[pos] = change;		// mark the original value
		value[pos] = val;		// set the new value
		int newpos = (hash[change][0]==pos)?hash[change][1]:hash[change][0];	// find the alternative pos
		return insert(change,newpos);	// re-insert the evicted value
	}
	return 1;
}

void print()
{
	for(int i=0;i<n;i++) printf("%d\n",value[i]);	
}

int main()
{
	int t;
	//FILE * f=freopen("1000.in","r",stdin);
	FILE *f=stdin;
	fscanf(f,"%d",&t);
	for(int s=0;s<t;s++)
	{
		fscanf(f,"%d %d",&m,&n);
		memset(value,-1,sizeof(value));
		memset(parent,-1,sizeof(parent));

		int i;
		int result = 1;
		for(i=0;i<m;i++)
		{
			int p,q;
			fscanf(f,"%d %d",&p,&q);
			hash[i][0]=p;
			hash[i][1]=q;

			if( result != -1 && insert(i,p)==-1 ){
				result = -1;
			}
		}
		if(result==1) printf("%s",s1);
		else printf("%s",s2);
//		print();
	}
}
