#include<iostream>
#include<vector>
using namespace std;
int n, sel[16], t1, t2, ans = -1;
vector<pair<int, int>> v;
void dfs(int index) {
	if (index == n) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (sel[j] == 1) {
				if (j + v[j].first - 1 >= n) continue;
				sum += v[j].second;
				j += v[j].first - 1;
				continue;
			}
		}
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		v.push_back({ t1,t2 });
	}
	dfs(0);
	cout << ans;
}