#include<iostream>
using namespace std;
int T, tc, one, two, thr, fou;
int a[12], sel[15], ans;
void dfs(int index) {
	if (index >= 12) {
		int sum = 0;
		for (int j = 0; j < 12; j++) {
			if (sel[j] == 0) sum += a[j] * one;
			else if (sel[j] == 1 && a[j] > 0) sum += two;
			else if (sel[j] == 2 && a[j] > 0) {
				sum += thr;
				j += 2;
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	// 0: 1일 , 1: 1달, 2: 3달 이용권
	for (int i = 0; i < 3; i++) {
		sel[index] = i;
		if (i != 2) dfs(index + 1);
		else dfs(index + 3);	
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> one >> two >> thr >> fou;
		for (int i = 0; i < 12; i++) cin >> a[i];
		ans = 2147483647;
		dfs(0);
		if (ans > fou) ans = fou;
		cout << '#' << tc << ' ' << ans << '\n';
	}
}