//BOJ_11726_2XN_Tiling
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int *d = new int[n + 1];
	d[0] = d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n];
	delete[] d;
	return 0;
}