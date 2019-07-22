/*BOJ 2866 ���ڿ� �߶󳻱�*/
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
	//���Ϳ� ���� string�� ����
	for (int col = 0; col < m; col++) {
		string s = "";
		for (int row = 0; row < n; row++) {
			s += arr[row][col];
		}
		v.push_back(s);
		mp[s]++;
	}

	while (true) {
		//���͸� ���鼭 string�� ù ���ڸ� ���ְ�
		//�ٽ� ���� + map���� üũ����.
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