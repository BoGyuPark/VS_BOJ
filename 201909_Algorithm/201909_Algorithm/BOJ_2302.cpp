/*BOJ 2302 ±ØÀå ÁÂ¼®*/
#include<iostream>
using namespace std;
int n, m, sel[41], c[41], fix[41], cnt;
void go(int index) {

	if (index == n + 1) {
		for (int j = 1; j <= n; j++) cout << sel[j] << ' ';
		cout << '\n';
		cnt++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (fix[index] == -1) go(index + 1);
		if (fix[index] != -1 && c[i] == false && abs(i - index) <= 1) {
			c[i] = true;
			sel[index] = i;
			go(index + 1);
			c[i] = false;
		}
		if (fix[index] == -1) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	//°íÁ¤ ÁÂ¼®À» Ç¥½Ã
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		fix[t] = -1;
		sel[t] = t; c[t] = true;
	}

	go(1);
	cout << cnt;
}
//*BOJ 2302 ±ØÀå ÁÂ¼®*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int n, m, fix[41], cnt;
//vector<int> num;
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> n >> m;
//
//	//°íÁ¤ ÁÂ¼®À» Ç¥½Ã
//	for (int i = 0; i < m; i++) {
//		int t; cin >> t;
//		fix[t] = -1;
//	}
//
//	cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (fix[i] == -1) {
//			if (cnt != 0) num.push_back(cnt);
//			cnt = 0;
//		}
//		else cnt++;
//	}
//	if (cnt != 0) num.push_back(cnt);
//	int ans = 1;
//	for (int i = 0; i < num.size(); i++) ans *= num[i];
//	cout << ans;
//}