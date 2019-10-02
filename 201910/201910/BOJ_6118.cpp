/* BOJ 6118 ¼û¹Ù²ÀÁú */
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, u, v, dist[20001], maxi, cnt, idx;
vector<vector<int>> g;
queue<int> q;
void bfs() {
	memset(dist, -1, sizeof(dist));
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i];
			if (dist[next] != -1) continue;
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (dist[i] > maxi) {
			idx = i;
			maxi = dist[i];
			cnt = 1;
		}
		else if (dist[i] == maxi) cnt++;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	cout << idx << ' ' << dist[idx] << ' ' << cnt;
}