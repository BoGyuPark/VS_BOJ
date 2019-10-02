/* BOJ 10282 «ÿ≈∑*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 2147483647
typedef pair<int, int> p;
int T, n, m, c, a, b, w, ans, dist[10001], cnt;
vector<vector<p>> g;
priority_queue<p, vector<p>, greater<p>> pq;
void search() {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	pq.push({ 0,c });
	dist[c] = 0;
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
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			ans = max(ans, dist[i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m >> c;
		g.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			g[b].push_back({ a,w });
		}
		ans = 0; cnt = 0;
		search();
		cout << cnt << ' ' << ans << '\n';
		g.clear();
	}
}