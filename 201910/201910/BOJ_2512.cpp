/* BOJ 2512 ¿¹»ê*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, cost[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int s = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		s += cost[i];
		maxi = max(maxi, cost[i]);
	}
	cin >> m;
	if (m >= s) {
		cout << maxi;
		return 0;
	}

	int lo = 0, hi = 1'000'000'000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (cost[i] >= mid) sum += mid;
			else sum += cost[i];
		}
		if (sum > m) hi = mid;
		else lo = mid;
	}
	cout << lo;
}