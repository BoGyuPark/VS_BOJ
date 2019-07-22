/*BOJ 2866 문자열 잘라내기*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int n, m, cnt;
char arr[1001][1001];
vector<string> v;
void Cutting() {
	map<string, int> mp;
	//벡터에 시작 string을 저장
	for (int col = 0; col < m; col++) {
		string s = "";
		for (int row = 0; row < n; row++) {
			s += arr[row][col];
		}
		v.push_back(s);
		mp[s]++;
	}

	while (true) {
		//벡터를 돌면서 string의 첫 글자를 없애고
		//다시 저장 + map으로 체크하자.
		for (int i = 0; i < v.size(); i++) {
			string temp = v[i].substr(1);
			if (mp[temp] != 0) return;
			else mp[temp]++;
			v[i] = temp;
		}
		cnt++;
		if (v[0].size() == 1) break;
		mp.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	Cutting();
	cout << cnt;
}