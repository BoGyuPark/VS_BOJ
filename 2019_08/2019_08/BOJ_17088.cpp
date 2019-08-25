/*BOJ 17088 등차수열 변환*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll n, arr[100'001], ans = 2147483647;
typedef struct {
	ll dif, preValue, cnt;
}info;
vector<info> v;
void solve(ll pivot, ll preValue, ll cnt) {

	for (int i = 2; i < n; i++) {
		ll dif = arr[i] - preValue;
		if (dif == pivot) {
			preValue = arr[i];
		}
		else if (dif + 1 == pivot) {
			preValue = arr[i] + 1;
			cnt++;
		}
		else if (dif - 1 == pivot) {
			preValue = arr[i] - 1;
			cnt++;
		}
		else return;
	}
	
	if (ans > cnt) ans = cnt;
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	//0번 인덱스와 1번인덱스의 경우의 수를 골라서 
	//등차 수열의 값을 찾는다.
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			ll cnt = 0;
			ll num1 = arr[0] + i, num2 = arr[1] + j;
			if (i != 0) cnt++;	
			if (j != 0) cnt++;
			v.push_back({ (num2 - num1), num2 , cnt });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		solve(v[i].dif, v[i].preValue, v[i].cnt);
	}
	if (ans == 2147483647) ans = -1;
	
	cout << ans;
	
	return 0;
}