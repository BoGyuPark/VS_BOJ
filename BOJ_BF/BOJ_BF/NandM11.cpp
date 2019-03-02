#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, sel[8];
vector<int> a;
void dfs(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		sel[index] = a[i];
		dfs(index + 1);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; a.push_back(t);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	dfs(0);
}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//int n, m, sel[8], a[8];
//vector<string> v;
//void dfs(int index) {
//	string s = "";
//	if (index == m) {
//		for (int j = 0; j < m; j++) s += sel[j] + '0';
//		v.push_back(s);
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		sel[index] = a[i];
//		dfs(index + 1);
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a, a + n);
//	dfs(0);
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
//	for (auto i : v) {
//		for (int j = 0; j < i.size(); j++) cout << i[j] - '0' << ' ';
//		cout << '\n';
//	}
//}
