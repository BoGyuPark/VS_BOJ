/* BOJ 1185 유럽여행 */
#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;
int n, m, w[10001], u, v, cost, p[10001], mini = 2147483647;
vector<vector<pair<int, int>>> g;
struct edge {
	int s, e, c;
};
vector<edge> edges;
bool cmp(edge a, edge b) {
	return a.c < b.c;
}
int getParent(int x) {
	if (x == p[x]) return x;
	return p[x] = getParent(p[x]);
}
void unionParent(int a, int b) {
	a = getParent(a), b = getParent(b);
	if (a == b) return;
	if (a < b) p[b] = a;
	else p[a] = b;
}
bool findParent(int a, int b) {
	a = getParent(a), b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		mini = min(mini, w[i]);
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> cost;
		edges.push_back({ u,v, cost*2+w[u]+w[v] });
	}
	sort(edges.begin(), edges.end(), cmp);
	int ans = 0;
	for (int i = 0; i<edges.size(); i++) {
		int s = edges[i].s, e = edges[i].e, c = edges[i].c;
		if (!findParent(s, e)) {
			unionParent(s, e);
			ans += c;
		}
	}
	cout << ans + mini;
}