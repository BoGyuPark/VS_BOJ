/*BOJ 16971 배열 B의 값*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, A[1001][1001], cnt[1001][1001], originSum, ans = -2147483647;
void findMax() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			sum += A[i][j] + A[i + 1][j] + A[i + 1][j + 1] + A[i][j + 1];
			cnt[i][j]++;	cnt[i + 1][j]++;	
			cnt[i + 1][j + 1]++;	cnt[i][j + 1]++;
		}
	}
	ans = max(ans, sum);
}

void solve(int pivotIdx, int s, int e, int state) {
	int sum;
	//row
	if (state == 0) {
		for (int i = s; i < e; i++) {
			sum = originSum;
			for (int j = 0; j < m; j++) {
				sum -= (A[pivotIdx][j] * cnt[pivotIdx][j] + A[i][j] * cnt[i][j]);
				sum += (A[pivotIdx][j] * cnt[i][j] + A[i][j] * cnt[pivotIdx][j]);
			}
			ans = max(ans, sum);
		}
	}
	//col
	else {
		for (int i = s; i < e; i++) {
			sum = originSum;
			for (int j = 0; j < n; j++) {
				sum -= (A[j][pivotIdx] * cnt[j][pivotIdx] + A[j][i] * cnt[j][i]);
				sum += (A[j][pivotIdx] * cnt[j][i] + A[j][i] * cnt[j][pivotIdx]);
			}
			ans = max(ans, sum);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> A[i][j];
	}
	findMax();
	originSum = ans;

	//0행과 n-2까지 조합, n-1행과 1~n-2행까지 조합
	solve(0, 1, n - 1, 0);	solve(n - 1, 1, n - 1, 0);
	//0열과 1~m-2열까지 조합, m-1열과 1~m-2열까지 조합
	solve(0, 1, m - 1, 1);	solve(m - 1, 1, m - 1, 1);
	cout << ans;
}