/*7584. 자가 복제 문자열*/
#include<iostream>
using namespace std;
typedef long long ll;
ll T, tc, k, value[3] = { 0,0,1 };
int ans;
void go(ll num, ll cnt) {
	if (num <= 2) {
		if (cnt % 2 == 0) ans = value[num];
		else ans = (value[num] + 1) % 2;
		return;
	}
	ll pivot = 1;
	while (pivot * 2 <= num + 1) pivot = pivot << 1;
	pivot--;
	ll dif = num - pivot;

	if (dif == 0) {
		if (cnt % 2 == 0) ans = 0;
		else ans = 1;
		return;
	}
	else go(pivot - dif, cnt + 1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> k;
		go(k - 1, 0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}