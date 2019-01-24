#include<iostream>
#include<algorithm>
using namespace std;
int n, m, check[10], ans[10], num[10];
void go(int index, int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << ans[j] << ' ';
		}cout << "\n";
		return;
	}
	for (int i = start; i < n; i++) {
		if (check[i] == true) continue;
		check[i] = true; ans[index] = num[i];
		go(index + 1, i + 1);
		check[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0, 0);
	return 0;
}