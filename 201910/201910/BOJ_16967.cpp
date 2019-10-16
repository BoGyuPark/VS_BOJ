/*BOJ 16967 배열 복원하기*/
#include<iostream>
using namespace std;
int n, m, X, Y, B[601][601];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> X >> Y;
	for (int i = 0; i < n + X; i++) for (int j = 0; j < m + Y; j++) cin >> B[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			B[i + X][j + Y] -= B[i][j];
			cout << B[i][j] << ' ';
		}
		cout << '\n';
	}
}