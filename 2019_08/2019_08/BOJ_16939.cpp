/*BOJ 16939 2x2x2 큐브*/
#include<iostream>
using namespace std;
int cube[25], changeCube[14][25];

int pos[6][8] = { 
	{1,3,5,7,9,11,24,22},
	{2,4,6,8,10,12,23,21},
	{13,14,5,6,17,18,21,22},
	{15,16,7,8,19,20,23,24},
	{3,4,17,19,10,9,16,14},
	{1,2,18,20,12,11,15,13}
};

void Rotate(int idx, int row) {
	for (int i = 0; i < 8; i++)
		changeCube[row][pos[idx][i]] = cube[pos[idx][(i + 2) % 8]];
}

void reverseRotate(int idx, int row) {
	for (int i = 0; i < 8; i++)
		changeCube[row][pos[idx][(i + 2) % 8]] = cube[pos[idx][i]];
}

bool checkCube(int row) {
	int color = -1;
	for (int i = 1; i < 25; i++) {
		if (i % 4 == 1) color = changeCube[row][i];
		else {
			if (color != changeCube[row][i]) return false;
		}
	}
	return true;
}

bool findAns() {
	for (int i = 1; i < 13; i++) {
		if (checkCube(i)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 25; i++) cin >> cube[i]; 

	//맵 복사	//0번째는 원본
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 25; j++) changeCube[i][j] = cube[j];
	}

	//큐브 회전
	int row = 1;
	for (int i = 0; i < 6; i++) {
		Rotate(i, row);
		reverseRotate(i, row + 1);
		row += 2;
	}
	cout << findAns();
	return 0;
}