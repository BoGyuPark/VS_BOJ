#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[500001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		int st = lower_bound(a, a + n, target) - a + 1;
		int en = upper_bound(a, a + n, target) - a + 1;
		cout << en - st << ' ';
	}
}