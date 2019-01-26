#include<iostream>
#include<algorithm>
using namespace std;
int n, dl[100002], ori[100002], dr[100002], sum[100001], i, j, ans;
int main() {
	cin >> n;	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (i = 1; i <= n; i++) cin >> ori[i];
	for (int left = 1; left <= n; left++)
		dl[left] = max(dl[left - 1] + ori[left], ori[left]);
	for (int r = n; r >= 1; r--)
		dr[r] = max(dr[r + 1] + ori[r], ori[r]);
	ans = dl[1];
	for (i = 2; i <= n; i++)
		if (ans < dl[i])	ans = dl[i];
	for (int k = 1; k <= n; k++) {
		sum[k] = dl[k - 1] + dr[k + 1];
		if (ans < sum[k])	ans = sum[k];
	}
	cout << ans;
}