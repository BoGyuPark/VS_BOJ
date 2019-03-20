#include<iostream>
#include<algorithm>
using namespace std;
int n, m, wait[9], sel[9], c[9];
void dfs(int idx) {
	if (idx == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[idx] = wait[i];
		dfs(idx + 1);
		c[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	dfs(0);
}