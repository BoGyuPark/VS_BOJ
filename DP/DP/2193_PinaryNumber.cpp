//BOJ_2193_PinaryNumber
#include<bits/stdc++.h>
using namespace std;
//두번째 풀이
int main() {
	int n; cin >> n;
	long long d[91][2];
	d[1][0] = 0;	d[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[n][0] + d[n][1];
	return 0;
}

//첫번째 풀이
//int main() {
//	int n; cin >> n;
//	long long d[100];	d[1] = d[2] = 1;
//	for (int i = 3; i <= n; i++)	d[i] = d[i - 1] + d[i - 2];
//	cout << d[n];
//	return 0;
//}