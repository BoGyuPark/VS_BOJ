#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, map[21][21], i, j;
int main() {
	cin >> n;	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) cin >> map[i][j];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (i < n / 2)	v.push_back(0);
		else	v.push_back(1);
	}
	int ans = 2147483647, starsum, linksum, dif;
	do {
		vector<int> star, link;
		starsum = linksum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0)	star.push_back(i);
			else link.push_back(i);
		}
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				if (i == j)		continue;
				starsum += map[star[i]][star[j]];
				linksum += map[link[i]][link[j]];
			}
		}
		dif = starsum - linksum;
		if (dif < 0)	dif = -dif;
		if (ans > dif) ans = dif;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
}