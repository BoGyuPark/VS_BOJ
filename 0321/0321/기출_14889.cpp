#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, a[21][21], team[20], ans = 2147483647;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int i = 0; i < n / 2; i++) team[i] = 1;

	do {
		//startÆÀ°ú linkÆÀÀ¸·Î ³ª´©±â
		vector<int> start, link;
		for (int i = 0; i < n; i++) {
			//startÆÀ
			if (team[i] == 0) start.push_back(i);
			//linkÆÀ
			else link.push_back(i);
		}

		//°¢ ÆÀº°·Î 2¸í¾¿ Â¦Áö¾î Sij ,Sji °è»êÇÏ¿© ´õÇÏ±â
		int StartSum = 0, LinkSum = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				StartSum += a[start[i]][start[j]];
				LinkSum += a[link[i]][link[j]];
			}
		}
		int dif = StartSum - LinkSum;
		if (dif < 0) dif = -dif;
		if (ans > dif) ans = dif;
	} while (prev_permutation(team, team + n));
	cout << ans;
}