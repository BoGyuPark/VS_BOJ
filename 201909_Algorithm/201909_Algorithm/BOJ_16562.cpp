/*BOJ 16562 Ä£±¸ºñ*/
#include<iostream>
#include<set>
using namespace std;
int n, m, k, parent[10001], cost[10001], a, b;
set<int> s;
int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (cost[a] < cost[b]) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unionParent(a, b);
	}

	for (int i = 1; i <= n; i++) {
		int t = getParent(parent[i]);
		s.insert(t);
	}
	int sum = 0;
	for (auto i : s) {
		sum += cost[i];
	}
	if (sum <= k) cout << sum;
	else cout << "Oh no";
}