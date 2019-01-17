//BOJ_1934_LCM
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << n1 * n2 / gcd(n1, n2) << '\n';
	}
	return 0;
}