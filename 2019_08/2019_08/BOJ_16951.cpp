/*
	BOJ 16951 블록 놀이
	높이 차가 k인 오름차순	
*/
#include<iostream>
using namespace std;
int n, k, A[1001], ans = 2147483647, cnt;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 1; i <= 1000; i++) {
		cnt = 0;
		int dif = abs(A[0] - i);
		if (dif != 0) cnt++;
		for (int j = 1; j < n; j++) {
			int want = i + j * k;
			if (abs(want - A[j]) != 0) cnt++;
		}
		//cout << cnt << '\n';
		if (ans > cnt) ans = cnt;
	}
	cout << ans;
}