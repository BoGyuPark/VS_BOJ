/* BOJ 11657 타임머신 */
#include<iostream>
#include<vector>
using namespace std;
#define INF 2137483647
typedef pair<int, int> pii;
vector<vector<pii>> g;
vector<int> Upper;
int n, m, u, v, w;
void bellmanFord() {
	for (int i = 0; i <= n; i++) Upper.push_back(INF);
	Upper[1] = 0;
	bool updated;
	for (int i = 1; i <= n; i++) {
		updated = false;
		for (int now = 1; now <= n; now++) {
			for (int j = 0; j < g[now].size(); j++) {
				int next = g[now][j].first;
				int cost = g[now][j].second;
				//relax
				if (Upper[now]!=INF && Upper[next] > cost + Upper[now]) {
					Upper[next] = cost + Upper[now];
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	//음수 사이클 발생
	if (updated) Upper.clear();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	bellmanFord();
	if (Upper.empty()) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			cout << (Upper[i]==INF ? -1 : Upper[i]) << '\n';
		}
	}
}