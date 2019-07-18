/*BOJ 4574 스도미노쿠*/
#include<iostream>
#include<string>
using namespace std;
int n, map[9][9], cpy[9][9];
void printMap() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int u, v;
			string lu, lv;
			cin >> u >> lu >> v >> lv;
			map[lu[0] - 'A'][lu[1] - '0' - 1 ] = u;
			map[lv[0] - 'A'][lv[1] - '0' - 1] = v;
		}
		for (int i = 1; i <= 9; i++) {
			string s; cin >> s;
			map[s[0] - 'A'][s[1] - '0' - 1] = i;
		}

		printMap();
	}
}