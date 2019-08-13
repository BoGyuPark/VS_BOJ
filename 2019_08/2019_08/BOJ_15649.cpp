#include<iostream>
using namespace std;
int n, m, sel[9], c[9];
void go(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i + 1;
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	go(0);
}