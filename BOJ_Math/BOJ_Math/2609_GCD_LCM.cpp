//BOJ_2609_GCD_LCM
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
	int n1, n2; cin >> n1 >> n2;
	int g = gcd(n1, n2);
	cout << g << '\n' << n1 * n2 / g;
	return 0;
}