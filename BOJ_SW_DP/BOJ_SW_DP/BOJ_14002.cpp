#include<iostream>
using namespace std;
int n, a[1001], d[1001], b[1001], temp[1001], len = 0, lastIndex;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				b[i] = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (len < d[i]) {
			len = d[i];
			lastIndex = i;
		}
	}
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		temp[i] = a[lastIndex];
		lastIndex = b[lastIndex];
	}
	for (int i = len - 1; i >= 0; i--) {
		cout << temp[i] << ' ';
	}
	return 0;
}