/*BOJ 9882 Balanced Teams*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[12];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 12; i++) cin >> arr[i];
	int temp[12] = { 0, };
	for (int i = 0; i < 12; i++) {
		if (3 <= i && i < 6) temp[i] = 1;
		else if (6 <= i && i < 9) temp[i] = 2;
		else if (9<=i) temp[i] = 3;
	}
	int sum[4] = { 0, };
	int ans = 2147483647;
	do {
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < 12; i++) {
			if (temp[i] == 0) sum[0] += arr[i];
			else if (temp[i] == 1) sum[1] += arr[i];
			else if (temp[i] == 2) sum[2] += arr[i];
			else sum[3] += arr[i];
		}
		sort(sum, sum + 4);
		ans = min(ans, sum[3] - sum[0]);
	} while (next_permutation(temp, temp + 12));
	cout << ans;
}
