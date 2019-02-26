#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int Test, T, n,Limit;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		int a[17][17] = { 0, }, temp[17] = { 0, };
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		Limit = n / 2;
		vector<int> ans;
		for (int i = 0; i < Limit; i++) temp[i] = 1;

		do {
			vector<int> left, right;
			for (int i = 0; i < n; i++) {
				//A음식과 B음식으로 나눈다.
				if (temp[i] == 1) left.push_back(i);
				else right.push_back(i);
			}
			//각 음식의 맛을 구한다.
			int leftsum = 0, rightsum = 0;
			for (int j = 0; j < Limit; j++) {
				for (int z = 0; z < Limit; z++) {
					rightsum += a[right[j]][right[z]];
					leftsum += a[left[j]][left[z]];
				}
			}
			int dif = rightsum - leftsum;
			if (dif < 0) dif = -dif;
			ans.push_back(dif);
		} while (prev_permutation(temp, temp + n));
		sort(ans.begin(), ans.end());
		cout << '#' << T << ' ' << ans[0] << '\n';
	}
}