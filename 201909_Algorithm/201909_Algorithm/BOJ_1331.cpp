/*BOJ 13310 나이트 투어*/
#include<iostream>
#include<string>
using namespace std;
int map[6][6], check[6][6];
int dx[] = { -2,-2,-1,1,2,2,1,-1 };
int dy[] = { -1,1,2,2,1,-1,-2,-2 };
bool isPossible(int x, int y, int dest_x, int dest_y) {
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6) continue;
		if (!check[dest_x][dest_y] && nx == dest_x && ny == dest_y) return true;
	}
	return false;
}
int main() {
	string s,t;
	cin >> s;
	int first_r, first_c;
	int pre_r = 6 - (s[1] - '0') , pre_c = s[0] - 'A';
	first_r = pre_r, first_c = pre_c;
	for (int i = 1; i < 36; i++) {
		cin >> t;
		int now_r = 6 - (t[1] - '0'), now_c = t[0] - 'A';
		if (!isPossible(pre_r, pre_c, now_r, now_c)) {
			cout << "Invalid";
			return 0;
		}
		pre_r = now_r, pre_c = now_c;
		check[now_r][now_c] = true;
	}
	//마지막 지점에서 시작점으로 돌아오는 지 아닌지
	if (!isPossible(pre_r, pre_c, first_r, first_c)) {
		cout << "Invalid";
		return 0;
	}else cout << "Valid";
}