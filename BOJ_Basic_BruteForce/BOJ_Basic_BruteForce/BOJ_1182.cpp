#include<iostream>
using namespace std;
int n, s, arr[21], ans = 0;
void go(int sum, int index) {
	if (sum == s && index == n) {
		ans++; return;
	}
	if (index == n && sum != s) return;
	go(sum + arr[index], index + 1);
	go(sum, index + 1);
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	go(0, 0);
	if (s == 0) ans--;
	cout << ans;
	return 0;
}