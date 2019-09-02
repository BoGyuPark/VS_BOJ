/* BOJ 2549 루빅의 사각형*/
#include<iostream>
using namespace std;
int map[4][4], cpy[4][4];
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
		}
	}

}