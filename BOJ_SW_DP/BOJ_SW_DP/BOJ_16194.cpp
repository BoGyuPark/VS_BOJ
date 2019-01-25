#include<iostream>
#include<algorithm>
using namespace std;
int n, i, j;
long p[1001], d[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for ( i = 1; i <= n; i++) cin >> p[i];
	d[0] = 0; d[1] = p[1]; d[2] = min(p[2], d[1] + p[1]);
	for ( i = 3; i <= n; i++) {
		d[i] = d[i - 1] + p[1];
		for ( j = 2; j <= i; j++) {
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n];
	return 0;
}