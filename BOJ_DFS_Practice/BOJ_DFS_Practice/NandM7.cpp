#include<iostream>
#include<algorithm>
using namespace std;
int n, m, wait[7], a[7];
void go(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << a[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		a[index] = wait[i];
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	go(0);
}