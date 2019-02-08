#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
char puzzle[3][3];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	string s = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> puzzle[i][j];
			if (puzzle[i][j] == '0')
				puzzle[i][j] = '9';
			s += puzzle[i][j];
		}
	}
	map<string, int> m;
	queue<string> q;
	q.push(s);
	m[s] = 0;
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		int pos = now.find('9');
		int x = pos / 3;
		int y = pos % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				if (m.count(next) == 0) {
					m[next] = m[now] + 1;
					q.push(next);
				}
			}
		}
	}
	if (m.count("123456789") == 0) cout << -1;
	else cout << m["123456789"];
}