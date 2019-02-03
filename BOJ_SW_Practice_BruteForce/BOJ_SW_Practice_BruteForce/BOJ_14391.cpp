#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m, i, j, ans = 0;
char map[5][5];
int main() {
	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> map[i];
	for (i = 0; i < (1 << (n*m)); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			string s = "";
			for (int z = 0; z < m; z++) {
				int k = j * m + z;
				if ((i&(1 << k)) == 0) {
					s += map[j][z];
				}
				else {
					if (s.size() > 0)
						sum += stoi(s);
					s = "";
				}
			}
			if(s.size()>0)
				sum += stoi(s);
		}
		for (int j = 0; j < m; j++) {
			string s = "";
			for (int z = 0; z < n; z++) {
				int k = z * m + j;
				if ((i&(1 << k)) != 0) {
					s += map[z][j];
				}
				else {
					if (s.size() > 0)
						sum += stoi(s);
					s = "";
				}
			}
			if (s.size() > 0)
				sum += stoi(s);
		}
		ans = max(ans, sum);
	}
	cout << ans;
}