#include<iostream>
using namespace std;
int T, t, k, a[4][8], ind, dir;
void Rotate(int order) {
	int temp = a[order][7];
	for (int i = 7; i > 0; i--) a[order][i] = a[order][i - 1];
	a[order][0] = temp;
}
void ReverseRotate(int order) {
	int temp = a[order][0];
	for (int i = 0; i < 7; i++) a[order][i] = a[order][i + 1];
	a[order][7] = temp;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> k;
		//톱니바퀴 정보 입력
		for (int i = 0; i < 4; i++)
			for(int j=0; j<8; j++)	cin >> a[i][j];

		//명령 전달
		for (int i = 0; i < k; i++) {
			cin >> ind >> dir;
			int impo[3] = { 0, };
			//명령전달받고 먼저 2번째 톱니와 6번째 톱니를 비교하여
			//회전이 가능한지를 판단
			for (int j = 0; j < 3; j++) 
				if (a[j][2] != a[j + 1][6]) impo[j] = 1;
			ind -= 1;
			int left = ind, right = ind;
			//기준 톱니바퀴의 방향에 따라 다른 톱니바퀴의 방향도 미리 정한다.
			int odd = ind % 2, dirs[4], rotateCheck[4] = { 0, };
			for (int j = 0; j < 4; j++) {
				if (j % 2 == odd) dirs[j] = dir;
				else dirs[j] = -dir;
			}
			//해당 톱니바퀴는 무조건 돌린다.
			if (dir == 1) Rotate(ind);
			else ReverseRotate(ind);
			rotateCheck[ind] = true;

			//index기준으로 왼쪽으로 연쇄
			for (left; left > 0; left--) {
				if (impo[left - 1] == 1) {
					if (dirs[left] == 1) {
						if (rotateCheck[left - 1] == false) {
							ReverseRotate(left - 1);
							rotateCheck[left - 1] = true;
						}
					}
					else {
						if (rotateCheck[left - 1] == false) {
							Rotate(left - 1);
							rotateCheck[left-1] = true;
						}
					}
				}
				else break;
			}
			//index기준으로 오른쪽으로 연쇄
			for (right; right < 3; right++) {
				if (impo[right] == 1) {
					if (dirs[right] == 1) {
						if (rotateCheck[right + 1] == false) {
							ReverseRotate(right + 1);
							rotateCheck[right + 1] = true;
						}
					}
					else {
						if (rotateCheck[right + 1] == false) {
							Rotate(right + 1);
							rotateCheck[right + 1] = true;
						}
					}
				}
				else break;
			}
		}
		int ans = 0;
		for (int i = 0; i < 4; i++) 
			if (a[i][0] == 1) ans += (1 << i);
		cout << '#' << t << ' ' << ans << '\n';
	}
}