#include<iostream>
#include<string>
using namespace std;
int p[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int main() {
	int n;	string s; cin >> n >> s;
	for (int i = 0; i < 7; i++) {
		if (i == 2 || i == 5) continue;
		if (i == 0 || i == 3 || i == 6) {
			for (char c : s) {
				int num = c - '0';
				cout << ' ';
				if (p[num][i] == 0) { for (int j = 0; j < n; j++) cout << ' '; }
				else { for (int j = 0; j < n; j++) cout << '-'; }
				cout << ' ';
				cout << ' ';
			}
			cout << '\n';
		}
		else {
			for (int q = 0; q < n; q++) {
				for (char c : s) {
					int num = c - '0';
					if (p[num][i] == 0) cout << ' ';
					else cout << '|';
					for (int j = 0; j < n; j++) cout << ' ';
					if (p[num][i + 1] == 0) cout << ' ';
					else cout << '|';
					cout << ' ';
				}
				cout << '\n';
			}		
		}
	}
}