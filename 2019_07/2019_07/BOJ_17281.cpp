/*BOJ 17281 具备傍(?)*/
#include<iostream>
#include<cstring>
using namespace std;
int n, inning_striker_value[51][9];
int check[9], sel[9], striker_order[9];
int cnt = 0;
int last_striker_num, ans;
int baseman[4];

int moveBase(int cnt) {
	bool temp[10] = { 0, };
	int num = 0;
	//林磊 眉农
	for (int i = 1; i <= 3; i++) {
		if (baseman[i] == true) {
			if (i + cnt >= 4) num++;
			temp[i + cnt] = true;
		}
	}
	for (int i = 1; i <= 3; i++) {
		baseman[i] = temp[i];
	}
	return num;
}

void cal_score() {
	int outCnt = 0;
	int now_striker_num = 0;
	int score = 0;
	memset(baseman, 0, sizeof(baseman));
	int inning = 0;
	while (true)
	{
		switch (inning_striker_value[inning][striker_order[now_striker_num]])
		{
		case 1:
			score += moveBase(1);	
			baseman[1] = true;
			break;
		case 2:
			score += moveBase(2);
			baseman[2] = true;
			break;
		case 3:
			score += moveBase(3);
			baseman[3] = true;
			break;
		case 4:
			for (int i = 1; i <= 3; i++) {
				if (baseman[i] == true) score++;
			}
			score++;
			memset(baseman, 0, sizeof(baseman));
			break;
		case 0:
			outCnt++;
			break;
		}

		if (outCnt == 3) {
			inning++;
			outCnt = 0;
			memset(baseman, 0, sizeof(baseman));
		}
		now_striker_num = (now_striker_num + 1) % 9;

		if (inning == n) break;
	}
	if (ans < score) ans = score;
}

void dfs(int index) {
	if (index == 8) {
		for (int j = 0; j < 8; j++) {
			if (j < 3)	striker_order[j] = sel[j];
			else striker_order[j + 1] = sel[j];
		}
		cal_score();		
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (check[i] == true) continue;
		sel[index] = i;
		check[i] = true;
		dfs(index + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	striker_order[3] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> inning_striker_value[i][j];
		}
	}
	dfs(0);
	cout << ans;
}