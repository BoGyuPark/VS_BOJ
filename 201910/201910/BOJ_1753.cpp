/* BOJ 1753 최단경로*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, K, u, v, w;
int dist[20001];
vector<vector<pair<int, int>>> g;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int nodeNum) {
	for (int i = 1; i <= V; i++) dist[i] = 2147483647;
	pq.push({0,nodeNum });
	dist[nodeNum] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, now = pq.top().second;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int nCost = g[now][i].second + cost;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				pq.push({ nCost,next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E >> K;
	g.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (i == K) cout << 0 << '\n';
		else if (dist[i] == 2147483647) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}