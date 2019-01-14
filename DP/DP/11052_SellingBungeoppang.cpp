//BOJ_11052_SellingBungeoppang
//¹®Á¦ º¯ÇüµÊ
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int d[1001],p[1001];
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		d[i] = p[i];
		for (int j = 1; j <= i; j++) {
			if (d[i] < d[i - j] + p[j])
				d[i] = d[i - j] + p[j];
		}
	}
	cout << d[n];
	return 0;
}