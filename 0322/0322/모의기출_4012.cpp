#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int TC, T, n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	for (T = 1; T <= TC; T++) {
		cin >> n;
		int a[17][17] = { 0, };
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		int temp[16] = { 0, };
		for (int i = 0; i < n / 2; i++) temp[i] = 1;
		int ans = 2147483647;
		int cnt = 0;
		do {
			vector<int> A, B;
			for (int i = 0; i < n; i++) {
				if (temp[i] == 0) A.push_back(i);
				else B.push_back(i);
			}
			int ASum = 0, BSum = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					ASum += a[A[i]][A[j]];
					BSum += a[B[i]][B[j]];
				}
			}
			int dif = ASum - BSum;
			if (dif < 0) dif = -dif;
			if (ans > dif) ans = dif;
			if (ans == 0) break;
		} while (prev_permutation(temp, temp + n));
		cout << '#' << T << ' ' << ans << '\n';
	}
}