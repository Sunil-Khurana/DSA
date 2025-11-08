#include <iostream.h>
#include <conio.h>

#define INF 9999
const int N = 10;

int n=4;
int dist[N][N]={{0, 10, 15, 20},{10, 0, 35, 25},{15, 35, 0, 30},{20, 25, 30, 0}};

int minCost = INF;
int visited[N]; // 0: not visited, 1: visited

void tsp(int currCity, int count, int cost, int start)
{
	if (count == n && dist[currCity][start]>0)
	{
		if (cost + dist[currCity][start] < minCost)
		{
			minCost = cost + dist[currCity][start];
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0 && dist[currCity][i]>0)
		{
			visited[i] = 1;
			tsp(i, count + 1, cost + dist[currCity][i], start);
			visited[i] = 0;
		}
	}
}

main()
{
	int i;
	clrscr();
	for (i = 0; i < n; i++)
		visited[i] = 0;
	visited[0] = 1;
	tsp(0, 1, 0, 0);
	cout << "Minimum cost: " << minCost << "\n";
}
