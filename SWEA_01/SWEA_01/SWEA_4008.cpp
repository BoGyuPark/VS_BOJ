#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int T, Test, n;
void go(int index, int cal, int p, int mi, int mu, int di, int a[13]) {
	if (index == n) {
		ans.push_back(cal);
		return;
	}
	if (p > 0) go(index + 1, cal + a[index], p - 1, mi, mu, di, a);
	if (mi > 0) go(index + 1, cal - a[index], p, mi - 1, mu, di, a);
	if (mu > 0) go(index + 1, cal * a[index], p, mi, mu - 1, di, a);
	if (di > 0) go(index + 1, cal / a[index], p, mi, mu, di-1, a);
}
int main() {
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		int a[13] = { 0, }, t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		for (int i = 0; i < n; i++) cin >> a[i];
		go(1, a[0], t1, t2, t3, t4, a);
		sort(ans.begin(), ans.end());
		cout << '#' << T << ' ' << (ans[ans.size() - 1] - ans[0]) << '\n';
		ans = vector<int>();
	}
}













////순열의 최대인 11이여서 순열풀이로 불가능.
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int T, Test, n;
//int main() {
//	cin >> Test;
//	for (T = 1; T <= Test; T++) {
//		cin >> n;
//		int cnt = 1, a[13] = { 0, };
//		vector<pair<int, int>> o;
//		vector<int> ans;
//		for (int i = 1; i <= 4; i++) {
//			int t; cin >> t;
//			while (t--) { o.push_back({ cnt++,i }); }
//		}
//		for (int i = 0; i < n; i++) cin >> a[i]; 
//		do {
//			int sum = a[0];
//			for (int i = 0; i < o.size(); i++) {
//				if (o[i].second == 1) sum += a[i + 1];
//				else if (o[i].second == 2) sum -= a[i + 1];
//				else if (o[i].second == 3) sum *= a[i + 1];
//				else sum /= a[i + 1];
//			}
//			ans.push_back(sum);
//		} while (next_permutation(o.begin(), o.end()));
//		sort(ans.begin(), ans.end());
//		cout << '#' << T << ' ' << (ans[ans.size() - 1] - ans[0]) << '\n';
//	}
//}