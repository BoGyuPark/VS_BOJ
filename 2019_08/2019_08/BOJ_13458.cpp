/* BOJ 13458 시험 감독*/
#include<iostream>
#include<math.h>
using namespace std;
long long n, a[1'000'001], b, c, ans, cnt;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if (a[i] - b > 0) ans += ceil((a[i] - b) / (double)c) + 1;
		else ans++;
	}
	cout << ans;
}