/*BOJ 2866 문자열 잘라내기 Other*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, cnt, ans;
char arr[1001][1001];
vector<string> v;
void Cutting() {
	//벡터에 시작 string을 저장
	for (int col = 0; col < m; col++) {
		string s = "";
		for (int row = n-1; row > 0; row--) s += arr[row][col];
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	//뒤에서 부터 최대 중복인것을 카운트한다.
	for (int i = 0; i < m - 1; i++) {
		int cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			if (v[i][j] == v[i + 1][j]) {
				cnt++;
			}
			else break;
		}
		ans = max(ans, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
	Cutting();
	cout << n - ans - 1;
}