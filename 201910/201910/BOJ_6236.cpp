/* BOJ 6236 侩捣 包府*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, cost[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int lo = 0;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		lo = max(lo, cost[i]);
	}
	int hi = 1'000'000'000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int remains = mid;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (remains - cost[i] >= 0) remains -= cost[i];
			else {
				cnt++;
				remains = mid - cost[i];
			}
		}
		if (cnt <= m) hi = mid;
		else lo = mid;
	}
	cout << lo;
}
///* BOJ 6236 侩捣 包府*/
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n, m, cost[100001];
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> n >> m;
//	int lo = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> cost[i];
//		lo = max(lo, cost[i]);
//	}
//	int hi = 1'000'000'000;
//	while (lo + 1 < hi) {
//		int mid = (lo + hi) / 2;
//		int sum = 0;
//		int cnt = 1;
//		for (int i = 0; i < n; i++) {
//			if (sum + cost[i] < mid) {
//				sum += cost[i];
//			}
//			else {
//				cnt++;
//				sum = cost[i];
//			}
//		}
//		if (cnt > m) lo = mid;
//		else hi = mid;
//	}
//	cout << lo;
//}