#include<iostream>
using namespace std;
int n, m, a[51][51], maxi;
int Find(int x, int y) {
	int area = 0;
	for (int i = 0; i < maxi; i++) {
		if (x + i >= n || y + i >= m) continue;
		if (a[x][y] == a[x][y + i] && a[x][y] == a[x + i][y] && a[x][y] == a[x + i][y + i]){
			if (area < ((i + 1)*(i + 1)))	area = (i + 1)*(i + 1);
		}
	}
	return area;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	int ans = 1;
	maxi = (n > m ? m : n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = Find(i, j);
			if (ans < temp) ans = temp;
		}
	}
	cout << ans;
}