/*BOJ 3985 롤 케이크*/
#include<iostream>
using namespace std;
int L, n, p, k, cake[1001], maxLen, maxIdx, realMax, realIdx;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p >> k;
		int len = k - p + 1;
		if (maxLen < len) {
			maxLen = len;
			maxIdx = i;
		}
		int realCnt = 0;
		for (int j = p; j <= k; j++) {
			if (cake[j] == 0) {
				cake[j] = i;
				realCnt++;
			}
		}
		if (realMax < realCnt) {
			realMax = realCnt;
			realIdx = i;
		}
	}
	cout << maxIdx << '\n' << realIdx;
}