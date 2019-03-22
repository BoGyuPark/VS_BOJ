#include<iostream>
#include<algorithm>
using namespace std;
int TC, T, n, b, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	for (T = 1; T <= TC; T++) {
		cin >> n >> b;
		int a[20] = { 0, };
		for (int i = 0; i < n; i++) cin >> a[i];
		//부분집합의 개수 구하기
		ans = 2147483647;
		int temp[20] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) temp[j] = 1;
			do {
				int sum = 0;
				for (int z = 0; z < n; z++) 
					if (temp[z] == 1) sum += a[z];
				if (sum - b >= 0) {
					if (ans > (sum - b)) ans = sum - b;
				}
			} while (prev_permutation(temp, temp + n));
		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}