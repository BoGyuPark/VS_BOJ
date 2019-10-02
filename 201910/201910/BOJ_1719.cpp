/* BOJ 1719 ец╧Х */
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, u, v, w, dist[201], path[201][201], fromTo[201];
#define INF 2147483647
typedef pair<int, int> p;
vector<vector<p>> g;
priority_queue<p, vector<p>, greater<p>> pq;

void dijk(int nodeIdx) {
	memset(fromTo, 0, sizeof(fromTo));
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[nodeIdx] = 0;
	pq.push({ 0,nodeIdx });
	while (!pq.empty()) {
		int now = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int nCost = g[now][i].second + cost;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				pq.push({ nCost,next });
				fromTo[next] = now;
			}
		}
	}
	int prev, firstPath = -1;
	for (int i = 1; i <= n; i++) {
		if (i == nodeIdx) continue;
		int temp = fromTo[i];
		firstPath = i;
		while (temp != 0) {
			prev = temp;
			temp = fromTo[temp];
			if (temp == nodeIdx) firstPath = prev;
		}
		path[nodeIdx][i] = firstPath;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	for (int i = 1; i <= n; i++) dijk(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (path[i][j] == 0) cout << '-' << ' ';
			else cout << path[i][j] << ' ';
		}
		cout << '\n';
	}
}