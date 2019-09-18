/*JungOl 1863 Á¾±³*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, parent[50001], a, b, ans;
int cnt[50001];
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unionParent(a, b);
	}
	
	for (int i = 1; i <= n; i++) {
		int p = getParent(i);
		cnt[p]++;
	}
	for (int i = 1; i <= n; i++) if (cnt[i] > 0) ans++;
	cout << ans;
}