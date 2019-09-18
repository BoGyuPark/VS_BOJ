/*BOJ 1717 집합의 표현*/
#include<iostream>
using namespace std;
int n, m, order, a, b, parent[1'000'001];
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
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> order >> a >> b;
		if (order == 0) {
			unionParent(a, b);
		}
		else {
			if (findParent(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}