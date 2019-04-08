#include<iostream>
#include<vector>
using namespace std;
int T, tc, n, a[12][12];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
pair<int, int> ans;		//코어수, 전선수
typedef struct info {
	int row, col, dirsSum;
};
vector<info> v;
int PatchLine(int i, int j, int d, int value) {
	int cnt = 0, pivot;
	if (d == 1) pivot = abs(n - 1 - j);
	else if (d == 2) pivot = j;
	else if (d == 3) pivot = i;
	else pivot = abs(n - 1 - i);
	int nx = i + dx[d], ny = j + dy[d];
	while ((nx >= 0 && ny >= 0 && nx < n && ny < n) && (a[nx][ny] == 0)) {
		a[nx][ny] = value;
		cnt++;
		nx += dx[d]; ny += dy[d];
	}
	if (cnt == pivot) return cnt;
	else return 0;
}
void FindDirs(int i, int j) {
	int dirs = 1;
	for (int z = 1; z <= 4; z++) {
		int cnt = 0, pivot;
		if (z == 1) pivot = abs(n - 1 - j);
		else if (z == 2) pivot = j;
		else if (z == 3) pivot = i;
		else pivot = abs(n - 1 - i);

		int nx = i + dx[z], ny = j + dy[z];
		while ((nx >= 0 && ny >= 0 && nx < n && ny < n) && (a[nx][ny] == 0)) {
			cnt++;
			nx += dx[z]; ny += dy[z];
		}
		if (cnt == pivot) dirs += (1 << z);
	}
	if(dirs!=1) v.push_back({ i,j,dirs });
}

void dfs(int index, int insertCnt, int LineCnt) {

	if (index == v.size()) {
		if (insertCnt > ans.first) {
			ans.first = insertCnt;
			ans.second = LineCnt;
		}
		else if(insertCnt == ans.first){
			if (LineCnt < ans.second)	ans.second = LineCnt;
		}
		return;
	}

	//index에 해당하는 코어에서 dir방향으로 
	//라인을 추가한다.
	//추가하는 중에 라인이 "밖"까지 이어지지 않으면 return한다.
	for (int i = 1; i <= 5; i++) {
		if (v[index].dirsSum & (1 << i)) {
			if (i == 0) dfs(index + 1, insertCnt, LineCnt);
			else {
				//임시 저장
				int temp[20] = { 0, };
				if (i == 1 || i == 2) {	for (int j = 0; j < n; j++) temp[j] = a[v[index].row][j];}
				else {for (int j = 0; j < n; j++) temp[j] = a[j][v[index].col];}
				
				int t = PatchLine(v[index].row, v[index].col, i, 2);
				if (t > 0) dfs(index + 1, insertCnt + 1, LineCnt + t);
				
				//원상복귀
				if (i == 1 || i == 2) {	for (int j = 0; j < n; j++) a[v[index].row][j] = temp[j];}
				else {for (int j = 0; j < n; j++) a[j][v[index].col] = temp[j];}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {}
					//해당 코어에 전선을 설치할수 있는 방향을 찾아 입력
					else FindDirs(i, j);
				}
			}
		}
		ans.first = 0;
		ans.second = 2147483647;
		dfs(0, 0, 0);
		cout << '#' << tc << ' ' << ans.second << '\n';
		v.clear();
	}
}