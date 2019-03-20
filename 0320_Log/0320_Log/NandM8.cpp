#include<iostream>
#include<algorithm>
using namespace std;
int n, m, sel[8], wait[8];
void dfs(int index, int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		sel[index] = wait[i];
		dfs(index + 1, i);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	dfs(0, 0);
}