/* BOJ 5719 거의 최단 경로*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int, int> p;
#define INF 2147483647
vector<vector<p>> g;
priority_queue<p, vector<p>, greater<p>> q;
int n, m, u, v, w, start, dest,dist[501];
int pathCost[501][501];
vector<int> from[501];
vector<int> path, temp;
vector<vector<int>> ans;
void tracking(int d) {
	if (d == start) {
		int sum = 0;
		for (int j = path.size() - 1; j > 0; j--) {
			sum += pathCost[path[j]][path[j - 1]];
		}
		if (sum == dist[dest]) {
			for (auto j : path) temp.push_back(j);
			ans.push_back(temp);
			temp.clear();
		}
		return;
	}
	for (int i = 0; i < from[d].size(); i++) {
		path.push_back(from[d][i]);
		tracking(from[d][i]);
		path.pop_back();
	}
}

void dijk(int nodeIdx) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[nodeIdx] = 0;
	q.push({ 0,nodeIdx });
	while (!q.empty()) {
		int now = q.top().second, cost = q.top().first;
		q.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first, nCost = g[now][i].second + cost;
			if (dist[next] >= nCost) {
				dist[next] = nCost;
				q.push({ nCost,next });
				from[next].push_back(now);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt = 1;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> dest;
		start++, dest++;
		g.resize(n+1);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			g[u+1].push_back({ v+1, w });
			pathCost[u + 1][v + 1] = w;
		}
		dijk(start);
		path.push_back(dest);
		tracking(dest);

		for (int i = 0; i < ans.size(); i++) {
			for (int j = ans[i].size() - 1; j > 0; j--) {
				pathCost[ans[i][j]][ans[i][j - 1]] = 0;
			}
		}

		g.clear(); g.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (pathCost[i][j] != 0) {
					g[i].push_back({ j,pathCost[i][j] });
				}
			}
		}
		dijk(start);
		cout << (dist[dest] == INF ? -1 : dist[dest]) << '\n';
		memset(pathCost, 0, sizeof(pathCost));
		memset(from, 0, sizeof(from));
		g.clear(); 
		for (int i = 0; i < ans.size(); i++) ans[i].clear();
		ans.clear(); 
		path.clear();
		cnt++;
	}
}