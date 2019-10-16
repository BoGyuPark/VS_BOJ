/*BOJ 16917 양념 반 후라이드 반*/
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
typedef long long ll;
ll A, B, C, X, Y, ans = LLONG_MAX;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C >> X >> Y;
	int maxi = max(X, Y);
	ll t1 = 0, t2 = 0;
	for (int i = 0; i <= maxi; i++) {
		t1 = (X - i > 0 ? (X - i)*A : 0);
		t2 = (Y - i > 0 ? (Y - i)*B : 0);
		ll sum = t1 + t2 + i * C * 2;
		if (ans > sum) ans = sum;
	}
	cout << ans;
}