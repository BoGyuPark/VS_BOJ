#include<iostream>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, c, ans = 1, t;
	cin >> a >> b >> c;
	t = a;
	while (b) {
		if (b % 2 == 1) ans = (ans*t) % c;
		t = (t*t) % c;
		b /= 2;
	}
	cout << ans;
}