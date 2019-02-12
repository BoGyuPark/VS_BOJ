#include<iostream>
#include<algorithm>
using namespace std;
long long d[101], n, i, j;
int main() {
	cin >> n;
	d[1] = 1; d[2] = 2; d[3] = 3;
	for (i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		for (j = 1; j <= i - 3; j++) {
			if (d[i] < d[i - (j + 2)] * (j + 1))
				d[i] = d[i - (j + 2)] * (j + 1);
		}
	}
	cout << d[n];
}