/*BOJ 14891 톱니바퀴*/
#include<iostream>
#include<vector>
using namespace std;
int k, wheelNum, dir, idx;
char wheel[4][8];
vector<pair<int,int>> v;
void Rotate(int idx) {
	char temp = wheel[idx][7];
	for (int i = 7; i > 0; i--) wheel[idx][i] = wheel[idx][i - 1];
	wheel[idx][0] = temp;
}

void reverseRotate(int idx) {
	char temp = wheel[idx][0];
	for (int i = 0; i < 7; i++) wheel[idx][i] = wheel[idx][i + 1];
	wheel[idx][7] = temp;
}

//해당 톱니바퀴에 따라 인접한 톱니바퀴를 회전시킬지 말지 판단.
// index 2와 6으로 비교
//연쇄적인 반응
void simulate() {
	v.clear();
	int index = wheelNum;
	int indexDir = dir;
	int left = index - 1;
	//left
	while (left >= 0) {
		if (wheel[left][2] != wheel[index][6]) {
			indexDir = -indexDir;
			v.push_back({ left , indexDir });
			left--;
			index--;
		}
		else break;		
	}

	//right
	index = wheelNum;
	indexDir = dir;
	int right = index + 1;
	while (right<=3) {
		if (wheel[index][2] != wheel[right][6]) {
			indexDir = -indexDir;
			v.push_back({ right , indexDir });
			right++;
			index++;
		}
		else break;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 1) Rotate(v[i].first);
		else reverseRotate(v[i].first);
	}
	//default로 무조건 해당 톱니바퀴는 회전
	if (dir == 1) Rotate(wheelNum);
	else reverseRotate(wheelNum);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 8; j++) cin >> wheel[i][j];
		
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> wheelNum >> dir;
		wheelNum--;
		simulate();
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == '1') sum += (1 << i);
	}
	cout << sum;
}