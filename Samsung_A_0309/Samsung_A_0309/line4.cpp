#include <iostream>
using namespace std;
int a[1000001];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int maxlen = 0;
		int now = a[i];
		//왼쪽
		int left = 0;
		for (int j = 1; j < n; j++) {
			if (i - j >= 0) {
				if (a[i] <= a[j]) {
					int temp = abs(i - j);
					if (temp > left) left = temp;
					break;
				}
			}
			else break;
		}

		//오른쪽 검사
		int r = 0;
		for (int j = 1; j < n; j++) {
			if (i + j < n) {
				if (a[i] <= a[j]) {
					int temp = abs(i - j);
					if (temp > r) r = temp;
					break;
				}
			}
			else break;
		}
		maxlen = (left < r ? r : left);
		if (maxlen > ans) ans = maxlen;
	}
	cout << ans;
	return 0;
}