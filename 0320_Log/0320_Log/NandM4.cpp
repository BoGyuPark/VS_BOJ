#include<iostream>
using namespace std;
int n, m, sel[8];
void dfs(int index,int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		sel[index] = i + 1;
		dfs(index + 1, i);
	}
}
int main() {
	cin >> n >> m;
	dfs(0, 0);
}