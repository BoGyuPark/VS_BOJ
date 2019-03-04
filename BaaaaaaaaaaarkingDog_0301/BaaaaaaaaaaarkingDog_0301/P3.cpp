#include<iostream>
using namespace std;
int n, sel[9], found = false, ans = 0, sum;
pair<int, int> v[9], temp[9];
void dfs(int index) {
	if (found) return;
	if (index == n) {
		sum = 0;
		for (int i = 0; i < n; i++) temp[i] = { v[i].first,v[i].second };
		for (int j = 0; j < n; j++) {
			//부서진 계란을 든 경우.
			if (temp[j].first <= 0 || temp[sel[j] - 1].first <= 0) continue;
			
			//내가 들은 계란의 상태변화
			temp[j].first -= temp[sel[j] - 1].second;
			if (temp[j].first <= 0) sum++;

			//내가 들은 계란으로 부딪힌 계란의 상태변화
			temp[sel[j] - 1].first -= temp[j].second;
			if (temp[sel[j] - 1].first <= 0) sum++;
		}
		if (ans < sum) ans = sum;
		if (sum == n) found = true;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (index == i - 1) continue;
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[i] = { t1,t2 };
	}
	dfs(0);
	cout << ans;
}