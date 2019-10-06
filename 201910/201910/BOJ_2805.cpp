/* BOJ 2805 나무 자르기*/
#include<iostream>
using namespace std;
int n, m, h[1'000'001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> h[i];
	int lo = 0, hi = 1'000'000'000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (h[i] > mid) sum += h[i] - mid;
		}
		if (sum >= m) lo = mid;
		else hi = mid;
	}
	cout << lo;
}