#include<iostream>
#include<cmath>
using namespace std;
long long a[1000001], n, b, c, ans = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		ans++;
		if (a[i] > 0) ans += ceil(a[i] / (double)c);
	}
	cout << ans;
}