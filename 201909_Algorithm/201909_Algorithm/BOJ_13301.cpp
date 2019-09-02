/*BOJ 13301 타일 장식물*/
#include<iostream>
using namespace std;
typedef long long ll;
ll n, arr[81];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++) arr[i] = arr[i - 1] + arr[i - 2];
	cout << (arr[n] + arr[n - 1]) * 2;
}