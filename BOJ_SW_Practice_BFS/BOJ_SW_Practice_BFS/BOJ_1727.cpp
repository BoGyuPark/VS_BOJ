#include<iostream>
#include<algorithm>
using namespace std;
int n, m, narr[1001], marr[1001], dp[1001][1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> narr[i];
	for (int i = 1; i <= m; i++) cin >> marr[i];
	sort(narr, narr + n + 1);
	sort(marr, marr + m + 1);
	//둘 중 작은값만큼은 무조건 커플이 생긴다를 보장하기 위하여
	if (n > m) {
		swap(n, m);
		swap(narr, marr);
	}
	//dp[i][j] 는 i명의 사람과 j명의 사람을 맺어주는 값의 차의 최소 합
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			if (i == j)	dp[i][j] = dp[i - 1][j - 1] + abs(narr[i] - marr[j]);
			else
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(narr[i] - marr[j]));
		}
	}
	cout << dp[n][m];
}