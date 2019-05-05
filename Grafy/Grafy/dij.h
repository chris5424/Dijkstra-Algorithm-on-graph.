#pragma once
#include <iostream>


int N;
int a, b, w;
int am[100][100];
int dis[100];
int visited[100];

int dij(int x)
{
	visited[x] = 1;
	for (int i = 1; i < N; i++)
	{
		if ((visited[i] == 0) && (am[x][i] != -1))
		{
			if ((dis[x] + am[x][i] < dis[i]) || (dis[i] == -1))
			{
				dis[i] = dis[x] + am[x][i];
			}
		}
	}
	int smaller = -1, sw = -1;
	for (int i = 0; i <= N; i++)
	{
		if ((visited[i] == 0) && (dis[i] >= 0) && ((sw > dis[i]) || (sw == -1)))
		{
			sw = dis[i];
			smaller = i;
		}
	}
	if (smaller != -1)
	{
		dij(smaller);
		return 0;
	}
	return 0;
}

int main()
{
	fin >> N;

	for (int i=0;i<=N;i++)
	{
		for (int j=0; j<=N;j++)
		{
			am[i][j] = -1;
		}
	}

	for (int i = 0; i <= N; i++)
	{
		dis[i] = -1;
	}

	dis[1] = 0;
	while (!fin.eof)
	{
		fin >> a >> b >> w;
		am[a][b] = w;
		am[b][a] = w;
	}
	dij(1);

	for (int i = 0; i <= N; i++)
	{
		std::cout << dis[i] << " ";
	}
	std::cout << std::endl;
}