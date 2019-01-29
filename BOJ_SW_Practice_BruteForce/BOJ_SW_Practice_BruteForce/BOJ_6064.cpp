#include<iostream>
using namespace std;
int t, m, n, num, x, y, ans, l;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	cin >> t;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (t--) {
		cin >> m >> n >> x >> y;
		num = x; ans = 0;
		l = m * n / gcd(m, m);
		while (l--) {
			if (num % n == y % n) {
				ans = num;
				break;
			}
			num += m;
		}
		cout << (ans == 0 ? -1 : ans)<<"\n";
	}
}