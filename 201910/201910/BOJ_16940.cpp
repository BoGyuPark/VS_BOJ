/*BOJ 16940 BFS ½ºÆó¼È*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, path[100'001], nextIdx = 2;
bool check[100'001];
vector<vector<int>> g;
queue<int> q;
int isPossible(int now) {
	for (int i = 0; i < g[now].size(); i++) {
		int next = g[now][i];
		if (check[next]) continue;
		if (next == path[nextIdx]) {
			q.push(next);
			check[next] = true;
			nextIdx++;
			return next;
		}
	}
	return -1;
}
bool bfs() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < g[now].size(); i++) {
			int next = isPossible(now);
			if (next == -1) break;
		}
	}
	for (int i = 1; i <= n; i++) if (!check[i]) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> path[i];
	q.push(1);
	check[1] = true;
	cout<<bfs();
}