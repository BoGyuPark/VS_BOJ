/*BOJ 1976 여행 가자*/
#include<iostream>
using namespace std;
int n, m, p[201], t;
int getParent(int x) {
	if (x == p[x]) return x;
	return p[x] = getParent(p[x]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) p[b] = a;
	else p[a] = b;
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t;
			if (t == 1 && !findParent(i,j)) unionParent(i, j);
		}
	}
	int lastParent = getParent(1);
	int flag = true;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (lastParent != getParent(t)) {
			flag = false;
		}
	}
	cout << (flag == true ? "YES" : "NO");
}