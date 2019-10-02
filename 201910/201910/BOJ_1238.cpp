/* BOJ 1238 ÆÄÆ¼ */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 2147483647
typedef pair<int, int> p;	//wieght
int n, m, X, u, v, w, ans;
vector<vector<p>> g;
int dist[1001], goAndCome[1001];
priority_queue<p, vector<p>, greater<p>> pq;
void dijkstra(int nodeIdx, bool flag) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[nodeIdx] = 0;
	pq.push({ 0,nodeIdx });
	while (!pq.empty()) {
		int now = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (dist[now] < cost) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int nCost = g[now][i].second + cost;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				pq.push({ nCost,next });
			}
		}
	}

	if (flag) {
		for (int i = 1; i <= n; i++) goAndCome[i] += dist[i];
	}
	else {
		goAndCome[nodeIdx] += dist[X];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> X;
	g.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	for (int i = 1; i <= n; i++) {
		if (i == X) dijkstra(i, true);
		else dijkstra(i, false);
	}
	for (int i = 1; i <= n; i++) ans = max(ans, goAndCome[i]);
	cout << ans;
}