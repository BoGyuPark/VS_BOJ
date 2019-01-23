#include<iostream>
using namespace std;
int n, T[16], P[15], ans = 0;
void go(int day, int sum) {
	if (day > n) return;
	if (day == n) {
		if (ans < sum)
			ans = sum;
		return;
	}
	go(day + T[day], sum + P[day]);
	go(day + 1, sum);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)		cin >> T[i] >> P[i];
	go(0, 0);	cout << ans;
	return 0;
}