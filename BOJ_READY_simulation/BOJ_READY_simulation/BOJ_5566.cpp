#include<iostream>
using namespace std;
int a[5000], n, m, cnt;
int main() {
	cin >> n >> m;
	int s = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> cnt;
		s += cnt;
		if (a[s] !=0 ) s += a[s];
		if (s >= n) {
			cout << i;
			break;
		}
	}
}