/* SWEA 3234. 준환이의 양팔저울 */
#include<iostream>
using namespace std;
int T, tc, n;

int go(int index, int leftSum, int rightSum, int w[], int c[]) {
	
	if (leftSum < rightSum) return 0;
	int r = 0;
	if (index == n) return 1;
	
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true;
		r += go(index + 1, leftSum + w[i], rightSum, w, c);
		r += go(index + 1, leftSum, rightSum + w[i], w, c);
		c[i] = false;
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	int w[10] = { 0, };
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i];
		int c[10] = { 0, };
		cout << '#' << tc << ' ' << go(0, 0, 0, w, c) << '\n';
	}
}