/* BOJ 1916 최소비용 구하기*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, u, v, w, start, dest;
vector<vector<pair<int,int>>> graph;
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
void dijkstra(int nodeNum) {
	//init
	for (int i = 1; i <= n; i++) dist[i] = 2147483647;

	//cost, nodeNum;
	q.push({0, nodeNum });
	dist[nodeNum] = 0;
	while (!q.empty()) {
		int cost = q.top().first, now = q.top().second;
		q.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nCost = graph[now][i].second + cost;
			if (nCost < dist[next]) {
				q.push({ nCost,next });
				dist[next] = nCost;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	cin >> start >> dest;
	dijkstra(start);
	cout << dist[dest];
}