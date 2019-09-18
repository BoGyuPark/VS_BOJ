/*BOJ 1197 최소 스패닝 트리_크루스칼 알고리즘*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, A, B, C, parent[10001], ans;
struct edge {
	int s, e, w;
};
vector<edge> v;
bool cmp(edge &a, edge &b) {
	return a.w < b.w;
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		v.push_back({ A,B,C });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (!findParent(v[i].s, v[i].e)) {
			unionParent(v[i].s, v[i].e);
			ans += v[i].w;
		}
	}
	cout << ans;
}