/* BOJ 2211 네트워크 복구*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define INF 2147483647
typedef pair<int, int> p;
int n, m, u, v, w, dist[1001], from[1001];
bool check[1001][1001];
vector<vector<p>> g;
priority_queue<p, vector<p>, greater<p>> q;
vector<p> ans;
void dijkstr(int nodeIdx) {
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
				from[next] = now;
			}
		}
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
	dijkstr(1);
	for (int i = 2; i <= n; i++) {
		int temp = i;
		int prev;
		while (temp != 0) {
			prev = temp;
			temp = from[temp];
			if (temp != 0 && !check[temp][prev]) {
				ans.push_back({ temp,prev });
				check[temp][prev] = check[prev][temp] = true;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
}