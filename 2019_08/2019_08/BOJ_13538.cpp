/*BOJ 13538 XOR Äõ¸®          fail*/
#include<iostream>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;
int m, x, l, r, k, y, cnt, maxi;
int arr[500'001];
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			cin >> x;
			dq.push_back(x);
			break;
		case 2:
			cin >> l >> r >> x;
			y = 0;
			maxi = -1;
			for (int j = l-1; j < r; j++) {
				int temp = dq[j] ^ x;
				if (temp > maxi) {
					maxi = temp;
					y = dq[j];
				}
			}
			cout << y << '\n';
			break;
		case 3:
			cin >> k;
			while (k--) dq.pop_back();
			break;
		case 4:
			cin >> l >> r >> x;
			cnt = 0;
			for (int j = l-1; j < r; j++) {
				if (dq[j] <= x) cnt++;
			}
			cout << cnt << '\n';
			break;
		case 5:
			cin >> l >> r >> k;
			memset(arr, 0, sizeof(arr));
			int idx = 0;
			for (int j = l - 1; j < r; j++) {
				arr[idx++] = dq[j];
			}
			sort(arr, arr + idx);
			cout << arr[k - 1] << '\n';
			break;
		}
	}
}