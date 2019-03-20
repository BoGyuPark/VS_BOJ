#include<iostream>
#include<algorithm>
using namespace std;
int n, m, sel[8], wait[8], c[8];
void dfs(int idx, int start) {
	if (idx == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[idx] = wait[i];
		dfs(idx + 1, i);
		c[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	dfs(0, 0);
}