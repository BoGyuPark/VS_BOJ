/*BOJ 2437 Àú¿ï*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[1001], sum, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] != 1) ans = 1;
	else {
		for (int i = 0; i < n; i++) {
			if (sum + 1 < arr[i]) {
				ans = sum + 1;
				break;
			}
			sum += arr[i];
		}
	}
	if (ans == 0) ans = sum + 1;
	cout << ans;
}