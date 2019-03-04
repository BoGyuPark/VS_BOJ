#include<iostream>
using namespace std;
int a[50], sel[50], ans, T, k, sum;
void dfs(int index) {
	if (ans == 1) return;
	if (index == 3) {
		sum = 0;
		for (int j = 0; j < 3; j++) sum += sel[j];
		if (sum == k) ans = 1;
		return;
	}
	for (int i = 1; i < 46; i++) {
		sel[index] = a[i];
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 1; i < 46; i++) a[i] = i * (i + 1) / 2;
	while (T--) {
		cin >> k;
		ans = 0;
		dfs(0);
		cout << ans << '\n';
	}
}