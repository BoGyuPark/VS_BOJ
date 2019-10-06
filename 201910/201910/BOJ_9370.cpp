/* BOJ 9370 미확인 도착지*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 2147483647
int T, n, m, t, s, g, h, a, b, d, dest, dist[2001], finalCost[2001];
typedef pair<int, int> p;
vector<vector<p>> graph;
priority_queue<p, vector<p>, greater<p>> q;
vector<int> ans, destList;
void dijk(int nodeIdx) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[nodeIdx] = 0;
	q.push({ 0,nodeIdx });
	while (!q.empty()) {
		int now = q.top().second, cost = q.top().first;
		q.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nCost = graph[now][i].second + cost;
			if (nCost <= dist[next]) {
				dist[next] = nCost;
				q.push({ nCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m >> t >> s >> g >> h;
		graph.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			graph[a].push_back({ b,d });
			graph[b].push_back({ a,d });
		}
		dijk(s);
		for (int i = 0; i < t; i++) {
			cin >> dest;
			destList.push_back(dest);
			finalCost[dest] = dist[dest];
		}
		int cost = max(dist[g], dist[h]);
		if (dist[g] < dist[h]) dijk(h);
		else dijk(g);
		
		for (int i = 0; i < destList.size(); i++) {
			if (finalCost[destList[i]] == dist[destList[i]] + cost) {
				ans.push_back(destList[i]);
			}
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		for (auto i : ans) cout << i << ' ';
		cout << '\n';
		graph.clear(); ans.clear();
		memset(finalCost, 0, sizeof(finalCost));
	}
}