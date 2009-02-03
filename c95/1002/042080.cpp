#include <stdio.h>
#include <memory.h>

struct
{
	long num;
	int sign;
}    way[110][110], ttt[110][110];
char visit[110][12];
long dist[110][12];
long n, k, m;


void Initial()
{
	long x, y, z, i, j;

	memset(way, 0, sizeof(way));
	for (i = 0; i < m; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &z);
		if (!way[x][y].num || way[x][y].num > z) way[x][y].num = z;
	}
	
	memcpy(ttt, way, sizeof(way));
	for (j = 0; j < n; j++)
		for (i = 0; i < n; i++)
			if (ttt[i][j].num)
				for (k = 0; k < n; k++)
					if (ttt[j][k].num && (!ttt[i][k].num || ttt[i][k].num > ttt[i][j].num + ttt[j][k].num))
						ttt[i][k].num = ttt[i][j].num + ttt[j][k].num;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (ttt[i][j].num)
				if (!ttt[j][i].num)	
				{
					way[i][j].sign = 1;
					way[i][j].num *= 2;
				}
}


void work()
{
	long i, j, nowi, nowk, ans = -1, tmpk;
	
	memset(dist, 255, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	dist[0][0] = 0;
	do
	{
		nowi = -1;
		nowk = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j <= k; j++)
				if (dist[i][j] != -1 && !visit[i][j])
					if (nowi == -1 || dist[nowi][nowk] > dist[i][j])
					{
						nowi = i;
						nowk = j;
					}
		if (nowi == -1) break;

		for (i = 0; i < n; i++)
			if (way[nowi][i].num)
			{
				tmpk = nowk + (way[nowi][i].sign);
				if (tmpk <= k && (dist[i][tmpk] == -1 || dist[i][tmpk] > dist[nowi][nowk] + way[nowi][i].num))
					dist[i][tmpk] = dist[nowi][nowk] + way[nowi][i].num;
			}
		visit[nowi][nowk] = 1;
		if (nowi == n - 1)
		{
			printf("%ld\n", dist[nowi][nowk]);
			return;
		}
	} while (1);
	printf("-1\n");
}


int main()
{
	while (scanf("%ld %ld %ld", &n, &m, &k) == 3)
	{
		Initial();
		work();
	}
	
	return 0;
}

