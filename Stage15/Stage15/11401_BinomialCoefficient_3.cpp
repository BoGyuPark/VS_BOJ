//������ ������ ����Ͽ� ���� ����� ������ ����غ��ϴ�
//BOJ_11401_BinomialCoefficient_3
//Failed
//������ �𸣸� ...������ �ȵ�...
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

//�ð����⵵�� �ٿ� x^y ����ϴ� ���
ll mul(ll x, ll y)
{
	ll ans = 1;
	while (y > 0) {
		//y�� Ȧ���̸�
		if (y % 2 != 0) {
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
	return ans;
}

int main()
{
	int N, K; cin >> N >> K;
	ll n = 1, k = 1, mm = 1, temp = N - K;
	ll ans;
	for (ll i = 1; i <= N; i++) {
		n *= i;
		n %= mod;
	}
	for (ll i = 1; i <= K; i++) {
		k *= i;
		k %= mod;
	}
	for (ll i = 1; i <= temp; i++) {
		k *= i;
		k %= mod;
	}
	ll t = mul(k, mod - 2);
	t %= mod;
	ans = n * t;
	ans %= mod;
	cout << ans;
	return 0;
}