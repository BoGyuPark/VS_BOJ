/*BOJ 16939 2x2x2 큐브*/
#include<iostream>
using namespace std;
int cube[25], cpy[25], origin[25];
int pos[6][8] = { 
	{1,3,5,7,9,11,24,22},
	{2,4,6,8,10,12,23,21},
	{13,14,5,6,17,18,21,22},
	{15,16,7,8,19,20,23,24},
	{3,4,17,19,10,9,16,14},
	{1,2,18,20,12,11,15,13}
};

void Rotate(int idx) {

	for (int i = 0; i < 8; i++)
		cube[pos[idx][i]] = cpy[pos[idx][(i + 2) % 8]];

	for (int i = 1; i < 25; i++)
		cpy[i] = cube[i];
}

bool checkCube() {
	int color = -1;
	for (int i = 1; i < 25; i++) {
		if (i % 4 == 1) color = cube[i];
		else {
			if (color != cube[i]) return false;
		}
	}
	return true;
}
void printMap() {
	for (int i = 1; i < 25; i++) cout << cube[i] << ' ';
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 25; i++) { 
		cin >> cube[i]; 
		cpy[i] = cube[i]; 
		origin[i] = cube[i];
	}
	int ans = checkCube();	//초기
	//printMap();
	if (ans == 0) {

		for (int i = 0; i < 6; i++) {
			for (int i = 1; i < 25; i++) cube[i] = cpy[i] = origin[i];
			Rotate(i);
			//printMap();
			if (checkCube()) {
				cout << 1;
				return 0;
			}
			
			Rotate(i);
			Rotate(i);
			//reverseRotate(i);
			//printMap();
			if (checkCube()) {
				cout << 1;
				return 0;
			}
		}
		cout << 0;
	}
	else cout << 1;
	return 0;
}