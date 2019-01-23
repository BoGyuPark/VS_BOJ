#include<iostream>
#include<limits.h>
using namespace std;
int t1, t2, t3, t4, arr[12], n, mmax = INT_MIN, mmin = INT_MAX;
void go(int index, int cal, int plus, int minus, int mul, int div) {
	if (index == n) {
		if (mmax < cal)	mmax = cal;
		if (mmin > cal)	mmin = cal;
		return;
	}
	if (plus > 0)
		go(index + 1, cal + arr[index], plus - 1, minus, mul, div);
	if (minus > 0)
		go(index + 1, cal - arr[index], plus, minus - 1, mul, div);
	if (mul > 0)
		go(index + 1, cal * arr[index], plus, minus, mul - 1, div);
	if (div > 0)
		go(index + 1, cal / arr[index], plus, minus, mul, div - 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> t1 >> t2 >> t3 >> t4;
	go(1, arr[0], t1, t2, t3, t4);
	cout << mmax << '\n' << mmin;
	return 0;
}