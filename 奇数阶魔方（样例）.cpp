#include <cstdio>
#include <cstring>
int main()
{
	int u;
	int x,y,n;
	int num[22][22];
	scanf ("%d",&u);
	while (u--)
	{
		scanf ("%d",&n);
		memset (num,-1,sizeof(num));
		x = 1;		//1填首行正中央 
		y = n / 2 + 1;
		for (int i = 1 ; i <= n * n ; i++)
		{
			num[x][y] = i;
			x--;		//依次斜上切莫忘 
			y++;
			if (x == 0 && y == n + 1)		//若是重了填下方 
			{
				x += 2;
				y--;
			}
			else if (num[x][y] != -1)
			{
				x += 2;
				y--;
			}
			else if (x == 0 && y != n + 1)
			{
				x = n;		//上出下填 
			}
			else if (x != 0 && y == n + 1)
			{
				y = 1;		//右出左 
			}
		}
		//输出 
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				printf ("%4d",num[i][j]);
			}
			printf ("\n");
		}
	}
	return 0;
}
