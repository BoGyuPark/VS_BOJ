/*BOJ 1107 리모컨_다른 풀이*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, ans;
bool possibleNumCheck[10];
int isPossible(int target) {
	int len = 0;
	if (target == 0) {
		if (!possibleNumCheck[target]) return 1;
		else return -1;
	}

	while (target != 0) {
		if (!possibleNumCheck[target % 10]) {
			target /= 10;
			len++;
		}
		else return -1;
	}
	return len;	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		possibleNumCheck[temp] = true;
	}
	ans = abs(n - 100);
	if (n == 100) cout << 0;
	else {
		for (int i = 0; i <= 1'000'000; i++) {
			int status = isPossible(i);
			if (status != -1) {
				ans = min(ans, abs(i - n) + status);
			}
		}
		cout << ans;
	}
}