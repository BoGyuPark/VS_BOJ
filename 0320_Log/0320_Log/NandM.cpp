#include<iostream>
using namespace std;
int sel[8], n, m, c[8];
void dfs(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i + 1;
		dfs(index + 1);
		c[i] = false;
	}

}
int main() {
	cin >> n >> m;
	dfs(0);
}