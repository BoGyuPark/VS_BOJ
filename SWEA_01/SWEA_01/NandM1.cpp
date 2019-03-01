#include<iostream>
using namespace std;
int n, m, c[8], selected[8];
void go(int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		selected[index] = i + 1;
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	cin >> n >> m;
	go(0);
}