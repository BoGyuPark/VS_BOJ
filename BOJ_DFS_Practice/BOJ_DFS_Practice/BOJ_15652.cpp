#include<iostream>
using namespace std;
int n, m, a[8];
void go(int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int j = start; j < n; j++) {
		a[index] = j + 1;
		go(index + 1, j);
	}
}
int main() {
	cin >> n >> m;
	go(0, 0);
}