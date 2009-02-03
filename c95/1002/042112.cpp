#include <stdio.h>
#include <string.h>
#define maxn 110
int g[maxn][maxn], used[maxn];
bool v1[maxn], v2[maxn];
int tree[maxn], f1,f2;
int ans[maxn];
int n,m,k;



void dfs1(int idx)
{
	int i;
	v1[idx]=1;
	for (i=0;i<n;++i) if (g[idx][i] && !v1[i]) dfs1(i);
	tree[f1++]=idx;
}
void dfs2(int idx, int fa)
{
	int i;
	v2[idx]=1;
	ans[idx]=fa;
	for (i=0;i<f1;++i)
		if (g[tree[i]][idx] && !v2[tree[i]])
			dfs2(tree[i], fa);
}
void solve()
{
	int i,j;
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	for (i=0;i<n;++i)
		if (!v1[i])
		{
			f1=0;
			dfs1(i);
			for (j=f1-1;j+1;--j) 
				if (!v2[tree[j]])
				{
					f2=0;
					dfs2(tree[j], tree[j]);
				}
		}
}


int list[maxn], head;
int mrk[maxn];
void mark(int kk)
{
	int i,j,u,head,tail;
	head=tail=0;
	list[0]=ans[0];
	memset(mrk,0,sizeof(mrk));
	mrk[ans[0]]=kk+1;
	while (head<=tail)
	{
		u=list[head++];
		if (mrk[u]==1) break;
		for (i=0;i<n;++i)
			if (ans[i]==u)
		for (j=0;j<n;++j)
			if (g[i][j] && !mrk[ans[j]])
			{
				mrk[ans[j]]=mrk[u]-1;
				list[++tail]=ans[j];
			} 
	}
	for (i=0;i<n;++i) if (mrk[ans[i]]) used[i]=true; else used[i]=false;
	//printf("------\n");
	//for (i=0;i<n;++i) printf("%d %d %d\n", i, ans[i], mrk[ans[i]]);
}

int main()
{
	int i,j,kk,t,a,b,c;
	while (scanf("%d%d%d",&n,&m,&kk)!=EOF)
	{
		memset(g,0,sizeof(g));
		for (i=0;i<m;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			if (g[a][b]==0 || c<g[a][b]) g[a][b]=c;
		}
		if (n==1) 
		{
			printf("0\n");
			continue;
		}
		solve();
		memset(used,0,sizeof(used));
		mark(kk);
	//	printf("---------\n");
		//for (i=0;i<n;++i) printf("%d %d %d\n", i, used[i], ans[i]);

		for (i=0;i<n;++i) if (used[i]) 
		for (j=0;j<n;++j) if (used[j])
			if (g[i][j] && ans[i] != ans[j]) g[i][j]=g[i][j]*2;

		for (k=0;k<n;++k)
		if (used[k]) 
			for (i=0;i<n;++i)
			if (used[i] && g[i][k])
				for (j=0;j<n;++j)
					if (used[j] && g[k][j] && (g[i][j]==0 || g[i][j]>g[i][k]+g[k][j]))
						g[i][j]=g[i][k]+g[k][j];
		if (g[0][n-1]) printf("%d\n", g[0][n-1]); else printf("-1\n");
		
	}
	return 0;
}