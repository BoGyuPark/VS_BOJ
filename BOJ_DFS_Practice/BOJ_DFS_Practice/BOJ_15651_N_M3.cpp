#include<iostream>
using namespace std;
int n, m, a[7];
void go(int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		a[index] = i + 1;
		go(index + 1);
	}
}
int main() {
	cin >> n >> m;
	go(0);
}