#include<iostream>
using namespace std;
typedef long long ll;
ll go(ll a, ll b, ll c) {
	if (b == 0) return 1;
	ll ans = go(a, b / 2, c);
	ans = (ans * ans) % c;
	//¦���� �״��
	if (b % 2 == 0) return ans;
	//Ȧ���� a���� �ѹ� �� ���ؼ�
	return (ans * a) % c;
}
int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << go(a, b, c);
}

//ll go(ll a, ll b, ll c) {
//	ll t = a, ans = 1;
//	while (b) {
//		if (b % 2 == 1)
//			ans = (ans * t) % c;
//		t = (t * t) % c;
//		b /= 2;
//	}
//	return ans % c;
//}