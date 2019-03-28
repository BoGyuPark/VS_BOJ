#include<iostream>
#include<math.h>
using namespace std;
int a[1000001], n, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		a[i] -= b; sum += 1;
		if (a[i] > 0)	sum += ceil(a[i] / (double)c);
	}
	cout << sum;
}