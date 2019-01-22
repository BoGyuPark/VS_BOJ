#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int c[11], w[11][11], n, i, j, ans = INT_MAX, sum = 0, flag = 0;;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n; for (i = 0; i < n; i++) c[i] = i;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	do {
		sum = 0, flag = 0;
		for (i = 0; i < n - 1; i++) {
			if (w[c[i]][c[i + 1]] == 0) {
				flag = 1;
				break;
			}
			sum += w[c[i]][c[i + 1]];
		}
		if (flag == 0 && w[c[n - 1]][c[0]] != 0) {
			sum += w[c[n - 1]][c[0]];
			if (ans > sum)
				ans = sum;
		}
	}while(next_permutation(c + 1, c + n));
	cout << ans;
	return 0;
}