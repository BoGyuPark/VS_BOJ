#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[8], c[8], p[8];
void go(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << a[j] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		a[index] = p[i];
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	go(0);
}