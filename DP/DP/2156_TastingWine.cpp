//BOJ_2156_TastingWine
#include<bits/stdc++.h>
using namespace std;
long long d[10001][3];
long long D[10001];
int a[10001];
//두번째 풀이
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	D[0] = 0; D[1] = a[1]; D[2] = D[1] + a[2];
	for (int i = 3; i <= n; i++) {
		D[i] = max(D[i - 1], max(D[i - 2] + a[i], D[i - 3] + a[i - 1] + a[i]));
	}
	cout << D[n];
	return 0;
}


//첫번째 풀이
//int main() {
//	int n; cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	d[0][0] = d[0][1] = d[0][2] = 0;
//	for (int i = 1; i <= n; i++) {
//		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
//		d[i][1] = d[i - 1][0] + a[i];
//		d[i][2] = d[i - 1][1] + a[i];
//	}
//	cout << max(d[n][0], max(d[n][1], d[n][2]));
//	return 0;
//}