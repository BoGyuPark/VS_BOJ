#include<iostream>
#include<cstring>
using namespace std;
int t, n, m = 3;
int nums[3] = { 1,2,3 };
int d[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		d[0] = 1;
		for (int j = 0; j < m; j++) {
			for (int i = 1; i <= n; i++) {
				if (i - nums[j] >= 0) {
					d[i] += d[i - nums[j]];
				}
			}
		}
		cout << d[n] << '\n';
		memset(d, 0, sizeof(d));
	}
}