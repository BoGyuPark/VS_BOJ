//BOJ_1260_DFS_BFS
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int check[1001];
vector<int> a[1001];

void dfs(int x)
{
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

void bfs(int x)
{
	queue<int> q;
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		cout << x << ' ';
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				q.push(y); check[y] = true;
			}
		}
	}
}

int main()
{
	int v, e, start;	cin >> v >> e >> start;

	for (int i = 0; i < e; i++) {
		int t1, t2;	cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	for(int i=1; i<=v; i++)
		sort(a[i].begin(), a[i].end());

	dfs(start);
	memset(check, 0, sizeof(check));
	cout << "\n";
	bfs(start);
	return 0;
}