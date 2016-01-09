#include<stdio.h>
#include<algorithm>
using namespace std;

int N, E;
int sum;
int cnt;
int now;

struct Edge
{
	int n1, n2, x;
} ans_edge[1000];

struct kruskal
{
	Edge edge[1000];
	int graph[1000][1000];
	int group[1000];
} map;

void input()
{
	int i,s,e;

	scanf_s("%d%d", &N, &E);
	for (i = 0; i < E; i++)
	{
		scanf_s("%d%d", &s, &e);
		map.edge[i].n1 = s;
		map.edge[i].n2 = e;
		scanf_s("%d", &map.edge[i].x);
		map.graph[s][e] = map.graph[s][e] = map.edge[i].x;
	}

	return;
}

bool operation(Edge temp1, Edge temp2)
{
	return temp1.x < temp2.x;
}
void set_Group()
{
	int i;

	for (i = 1; i <= N; i++)
	{
		map.group[i] = i;
	}

	return;
}

void union_edge(int a, int b)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		if (map.group[i] == map.group[a])
		{
			map.group[i] = b;
		}
	}

	return;
}

void kruskal_MST()
{
	std::sort(map.edge,map.edge+E,operation);
	set_Group();
	while (cnt < N - 1)
	{
		if (map.group[map.edge[now].n1] != map.group[map.edge[now].n2])
		{
			sum += map.edge[now].x;
			ans_edge[cnt].n1 = map.edge[now].n1;
			ans_edge[cnt].n2 = map.edge[now].n2;
			ans_edge[cnt++].x = map.edge[now].x;

			union_edge(map.group[map.edge[now].n1], map.group[map.edge[now].n2]);
		}
		now++;
	}
	return;
}

void output()
{
	int i;

	printf("%d\n%d\n", sum, cnt);
	for (i = 0; i < cnt; i++)
	{
		printf("%d %d %d\n", ans_edge[i].n1, ans_edge[i].n2, ans_edge[i].x);
	}
	return;
}

int main()
{
	input();
	kruskal_MST();
	output();

	return 0;
}