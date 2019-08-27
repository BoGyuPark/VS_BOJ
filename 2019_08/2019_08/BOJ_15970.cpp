/*BOJ 15970 화살표 그리기*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> v[5001];
int n, pos, color, ans;
int mini = 2147483647;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos >> color;
		v[color].push_back(pos);
	}
	
	for (int i = 0; i <= n; i++) {
		if (v[i].size() == 0) continue;

		for (int j = 0; j < v[i].size(); j++) {
			mini = 2147483647;
			for (int z = 0; z < v[i].size(); z++) {
				if (j == z) continue;
				int dif = abs(v[i][j] - v[i][z]);
				if (mini > dif) mini = dif;
			}
			ans += mini;
		}
	}
	cout << ans;
}