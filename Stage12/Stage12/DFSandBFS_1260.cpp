//BOJ_DFSandBFS_1260
#include<bits/stdc++.h>
using namespace std;
vector<int> varr[1001];

void DFS(int start)
{
	stack<int> s;
	s.push(start);
	int i, temp, flag;
	int visited[1001] = { 0, };
	visited[start] = 1;
	cout << start + 1 << ' ';
	while(!s.empty())
	{
		int v = s.top();
		s.pop();

		for (i = 0; i<varr[v].size(); i++)
		{
			int there = varr[v][i];

			if (!visited[there]) {
				cout << there + 1 << ' ';
				visited[there] = 1;
				s.push(v);
				s.push(there);
				break;
			}
		}
			
	}

}

void BFS(int start)
{
	queue<int> q;
	int visited[1001] = { 0, };
	q.push(start);
	visited[start] = 1;
	cout << start + 1 << ' ';
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < varr[v].size(); i++)
		{
			int there = varr[v][i];
			if (!visited[there])
			{
				q.push(there);
				visited[there] = 1;
				cout << there + 1 << ' ';
			}
		}
	}
}


int main()
{
	int N, M, V, s, e;
	cin >> N >> M >> V;

	for(int i=0; i<M; i++)
	{ 
		cin >> s >> e;
		varr[s - 1].push_back(e - 1);
		varr[e - 1].push_back(s - 1);
	}

	//한 정점에서 작은 숫자의 정점으로 접근하기 위하여
	for (int i = 0; i < M; i++)
		sort(varr[i].begin(), varr[i].end());
	
	DFS(V - 1);
	cout << "\n";
	BFS(V - 1);

	return 0;
}