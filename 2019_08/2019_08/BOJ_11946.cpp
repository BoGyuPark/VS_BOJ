/*BOJ 11946 ¶ß°Å¿î ºØ¾î»§*/
#include<iostream>
using namespace std;
int n, m;
char map[11][11];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >=0; j--) cout<<map[i][j];
		cout << '\n';
	}
	return 0;
}