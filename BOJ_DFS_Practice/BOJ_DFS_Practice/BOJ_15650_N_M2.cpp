#include<iostream>
using namespace std;
int n, m, check[8], a[8];
void go(int index, int prev) {
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = prev; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			a[index] = i + 1;
			go(index + 1, i + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	go(0, 0);
}