//BOJ_11005_BaseConversion2
#include<bits/stdc++.h>
using namespace std;
//BOJ풀이
int main() {
	int n, b; cin >> n >> b;
	string ans = "";
	while (n > 0) {
		int r = n % b;
		if (r < 10) {
			ans += (char)(r + '0');
		}
		else {
			ans += (char)(r - 10 + 'A');
		}
		n /= b;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
//나의 풀이
//int main() {
//	long long s; cin >> s;
//	int B; cin >> B;
//	int arr[100]; int i = 0;
//	while (s / B != 0) {
//		arr[i] = s % B;
//		s /= B;
//		i++;
//	}
//	arr[i++] = s;
//	reverse(arr, arr + i);
//	string st = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	for (int j = 0; j < i; j++) {
//		cout << st[arr[j]];
//	}
//
//	return 0;
//}