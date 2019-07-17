/*BOJ 9881 Ski Course Design*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, arr[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	cout << '\n';

	int ans = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int lowest = arr[i];
			int maxDif = 0;
			int maxDif_idx = 0;
			for (int j = 0; j < n; j++) {
				int highest = arr[j];
				int dif = abs(highest - lowest);
				if (maxDif < dif) {
					maxDif = dif;
					maxDif_idx = j;
				}
			}
			if (maxDif > 17) {
				maxDif -= 17;
				if (maxDif % 2 == 0) {
					int temp = maxDif / 2;
					ans += temp * temp * 2;
					if (arr[i] < arr[maxDif_idx]) {
						arr[i] += temp;
						arr[maxDif_idx] -= temp;
					}
					else {
						arr[i] -= temp;
						arr[maxDif_idx] += temp;
					}
				}
				else {
					int t1 = ceil(maxDif / 2.0);
					int t2 = (maxDif / 2);
					ans += t1 * t1 + t2 * t2;

					if (arr[i] < arr[maxDif_idx]) {
						arr[i] += t1;
						arr[maxDif_idx] -= t2;
					}
					else {
						arr[i] -= t1;
						arr[maxDif_idx] += t2;
					}

				}
			}
			else {
				cnt++;
			}
			/*for (int i = 0; i < n; i++) cout << arr[i] << ' ';
			cout << '\n';*/
		}
		if (cnt == n) break;
	}
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
			cout << '\n';
	cout << ans;
	
}