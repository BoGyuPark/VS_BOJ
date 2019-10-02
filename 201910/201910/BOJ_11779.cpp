/* BOJ 11779 최소비용 구하기 2*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, u, v, w, start, dest, dist[1001], fromTo[1001];
typedef pair<int, int> pii;
vector<vector<pii>> g;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> ans;

void search(int node) {
	for (int i = 1; i <= n; i++) dist[i] = 2147483647;
	dist[node] = 0;
	pq.push({ 0,node });	//cost, nodeNum
	while (!pq.empty()) {
		int now = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int nCost = g[now][i].second + cost;
			if (nCost < dist[next]) {
				pq.push({ nCost,next });
				dist[next] = nCost;
				fromTo[next] = now;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	cin >> start >> dest;
	search(start);
	cout << dist[dest] << '\n';
	while (dest!=0) {
		ans.push_back(dest);
		dest = fromTo[dest];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i <<" ";
}