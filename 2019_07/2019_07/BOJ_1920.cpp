#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[100000];
//void bs(int value, int len) {
//	int ans = 0;
//	int st = 0, en = len - 1;
//	int mid = (st + en) / 2;
//	while (st <= en) {
//		mid = (st + en) / 2;
//		if (a[mid] < value) {
//			st = mid + 1;
//		}
//		else if (a[mid] > value) {
//			en = mid - 1;
//		}
//		else {
//			ans = 1;
//			break;
//		}
//	}
//	cout << ans << '\n';
//}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int find_value;
		cin >> find_value;
		//bs(find_value, n);
		cout << binary_search(a, a + n, find_value) << '\n';
	}
}