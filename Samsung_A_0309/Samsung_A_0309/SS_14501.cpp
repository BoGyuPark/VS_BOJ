#include<iostream>
using namespace std;
int n, t[15], p[15], sel[15], ans = 0;
void dfs(int index) {
	if (index == n) {
		if (sel[0] == 1 && sel[3] == 1 && sel[4] == 1)
			cout << 'a';
		//선택된 상담일을 계산한다.
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (sel[j]) {
				if (j + t[j] <= n) {
					sum += p[j];
					j += t[j] - 1;
					continue;
				}
			}
		}
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
	dfs(0);
	cout << ans;
}