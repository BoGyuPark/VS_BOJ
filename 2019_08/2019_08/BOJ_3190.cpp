/* BOJ 3190 πÏ*/
#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int n, k, map[101][101], l, x, y, t;
char c;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
deque<pair<int, int>> snake;
queue<pair<int, char>> q;	//πÏ¿« πÊ«‚ ¿¸»Ø
void simulate() {
	snake.push_back({ 0,0 });	//πÏ ∏”∏Æ √ ±‚»≠
	map[0][0] = 2;		//πÏ¿« ∏ˆ
	int dir = 1;	//ø¿∏•¬ 
	t = 0;			//Ω√∞£
	while (true) {

		int x = snake.front().first, y = snake.front().second;
		int nx = x + dx[dir], ny = y + dy[dir];
		//¡æ∑·, ∫Æ
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) return;

		if (map[nx][ny] == 1) {
			snake.push_front({ nx,ny });
			map[nx][ny] = 2;
		}
		else {
			//πÏ ¿⁄Ω≈¿« ∏ˆø° ∫Œµ˙»˜¥¬¡ˆ
			if (map[nx][ny] == 2) return;

			//∏”∏Æ
			map[nx][ny] = 2;
			snake.push_front({ nx,ny });

			//≤ø∏Æ
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		t++;
		if (!q.empty() &&q.front().first == t) {
			if (q.front().second == 'D') dir = (dir + 1) % 4;
			else dir = (dir + 3) % 4;
			q.pop();
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x - 1][y - 1] = 1;	//ªÁ∞˙ ¡¬«•
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> t >> c;
		q.push({ t,c });
	}
	simulate();
	cout << t + 1;
}