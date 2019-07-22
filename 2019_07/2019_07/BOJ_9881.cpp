/*BOJ 9881 Ski Course Design*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[1001], ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	ans = 2147483647;
	for (int i = 0; i <= 100; i++) {
		int start = i, end = i + 17;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			//기준 범위 안에 들어 온다면 패스
			if (start <= arr[j] && arr[j] <= end) continue;
			int dif;

			if (arr[j] < start) {
				dif = start - arr[j];
				sum += dif * dif;
			}
			else if (arr[j] > end) {
				dif = arr[j] - end;
				sum += dif * dif;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans;
}