//BOJ_11576_BaseConversion
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, m; cin >> a >> b >> m;
	long long dec = 0;
	for (int i = 0; i < m; i++) {
		int temp;	cin >> temp;
		dec = dec*a + temp;
	}
	int arr[100], i = 0;
	while (dec > 0) {
		arr[i] = dec % b;
		dec /= b;
		i++;
	}
	for (int j = i-1; j >= 0; j--)
		cout << arr[j] << ' ';
	return 0;
}