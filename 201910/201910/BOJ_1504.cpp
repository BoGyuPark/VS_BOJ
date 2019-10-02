/* BOJ 1504 특정한 최단 경로*/
/* 
	1 -> a -> b -> N 과 ,1 -> b -> a -> N 경우가 있으므로
	1->a ,a->b , b->N     1-b  b-a a-N 중 작은것!	
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 2147483647
typedef pair<int, int> p;
int n, m, u, v, w, a,b,dist[801];
vector<vector<p>> g;
priority_queue<p, vector<p>, greater<p>> q;
void dijk(int nodeIdx) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[nodeIdx] = 0;
	q.push({ 0,nodeIdx });
	while (!q.empty()) {
		int now = q.top().second, cost = q.top().first;
		q.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int nCost = g[now][i].second + cost;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				q.push({ nCost,next });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	cin >> a >> b;
	dijk(1);
	//A먼저, B먼저 코스
	long long Acost = 0, Bcost = 0;
	Acost += dist[a], Bcost += dist[b];
	
	dijk(a);
	Acost += dist[b], Bcost += dist[n];

	dijk(b);
	Acost += dist[n], Bcost += dist[a];
	if (Acost >= INF && Bcost >= INF) cout << -1;
	else if (Acost >= INF && Bcost < INF) cout << Bcost;
	else if (Acost < INF && Bcost >= INF) cout << Acost;
	else cout << min(Acost, Bcost);
}