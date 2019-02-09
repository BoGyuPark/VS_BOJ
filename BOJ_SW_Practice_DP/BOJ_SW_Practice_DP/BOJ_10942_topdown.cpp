#include<iostream>
#include<cstring>
using namespace std;
int n, m, d[2001][2001];
int arr[2001];
int go(int i, int j) {
	if (i == j) return 1;
	if (i + 1 == j) {
		if (arr[i] == arr[j]) return 1;
		else return 0;
	}
	if (d[i][j] >= 0) return d[i][j];
	if (arr[i] != arr[j]) return d[i][j] = 0;
	else return d[i][j] = go(i + 1, j - 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 	cin >> arr[i];
	memset(d, -1, sizeof(d));
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << go(s,e) << '\n';
	}
}