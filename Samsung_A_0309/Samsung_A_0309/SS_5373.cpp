#include<iostream>
#include<string>
using namespace std;
int tc, a[12][9], cpy[12][9], n;
void copy() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 9; j++) cpy[i][j] = a[i][j];
	}
}
void oricopy() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 9; j++) a[i][j] = cpy[i][j];
	}
}
void prinT() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 9; j++) cout << a[i][j] << ' ';
		cout << '\n';
	}
}
void roUp() {
	copy();
	cpy[3][3] = a[5][3]; cpy[4][3] = a[5][4]; cpy[5][3] = a[5][5];
	cpy[3][4] = a[4][3]; cpy[4][4] = a[4][4]; cpy[5][4] = a[4][5];
	cpy[3][5] = a[3][3]; cpy[4][5] = a[3][4]; cpy[5][5] = a[3][5];
	
	cpy[3][6] = a[2][3]; cpy[4][6] = a[2][4]; cpy[5][6] = a[2][5];
	cpy[6][3] = a[3][6]; cpy[6][4] = a[4][6]; cpy[6][5] = a[5][6];
	cpy[3][2] = a[6][3]; cpy[4][2] = a[6][4]; cpy[5][2] = a[6][5];
	cpy[2][3] = a[5][2];  cpy[2][4] = a[4][2]; cpy[2][5] = a[3][2];
	oricopy();
}

void roUm() {
	copy();
	cpy[3][3] = a[3][5]; cpy[4][3] = a[3][4]; cpy[5][3] = a[3][3];
	cpy[3][4] = a[4][5]; cpy[4][4] = a[4][4]; cpy[5][4] = a[4][3];
	cpy[3][5] = a[3][5]; cpy[4][5] = a[3][4]; cpy[5][5] = a[3][3];

	cpy[3][6] = a[6][5]; cpy[4][6] = a[6][4]; cpy[5][6] = a[6][3];
	cpy[6][3] = a[3][2]; cpy[6][4] = a[4][2]; cpy[6][5] = a[5][2];


	cpy[3][6] = a[2][3]; cpy[4][6] = a[2][4]; cpy[5][6] = a[2][5];
	cpy[6][3] = a[3][6]; cpy[6][4] = a[4][6]; cpy[6][5] = a[5][6];
	cpy[3][2] = a[6][3]; cpy[4][2] = a[6][4]; cpy[5][2] = a[6][5];
	cpy[2][3] = a[5][2];  cpy[2][4] = a[4][2]; cpy[2][5] = a[3][2];
	oricopy();
}


int main() {
	cin >> tc;
	//기본 큐브 만들기
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 9; j++) {
			if (i >= 0 && i < 3 && j >= 3 && j < 6) a[i][j] = 1;
			else if (i >= 3 && i < 6) {
				if (j < 3) a[i][j] = 3;
				else if (j >= 6) a[i][j] = 2;
			}
			else if (i < 9) {
				if (j >= 3 && j < 6) a[i][j] = 4;
			}
			else {
				if (j >= 3 && j < 6) a[i][j] = 5;
			}
		}
	}
	roUp();
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (s[0] == 'U') {
				if (s[1] == '+') {

				}
				else {

				}
			}
			else if (s[0] == 'D') {

			}
			else if (s[0] == 'F') {

			}
			else if (s[0] == 'B') {

			}
			else if (s[0] == 'L') {

			}
			else if (s[0] == 'R') {

			}
		}
	}

	//답
}