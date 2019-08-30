/*BOJ 2303 숫자 게임*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, maxNum[1001], arr[5], sel[3], c[5], maxi;
void go(int index, int start) {
	if (index == 3) {
		int sum = 0;
		for (int j = 0; j < 3; j++) sum += arr[sel[j]];
		maxi = max(maxi, sum % 10);
		return;
	}
	for (int i = start; i < 5; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) cin >> arr[j];
		maxi = 0;
		go(0, 0);
		maxNum[i] = maxi;
	}
	int ans = 0;
	maxi = 0;
	for (int i = 0; i < n; i++) {
		if (maxi <= maxNum[i]) {
			maxi = maxNum[i];
			ans = i + 1;
		}
	}
	cout << ans;
}