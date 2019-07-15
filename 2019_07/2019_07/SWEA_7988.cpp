#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int T, tc, k, idx;
map<string, int> m;
string ans;
bool find_overlap(int s, int target, vector<vector<int>> &tempV) {
	for (int i = 0; i < tempV[s].size(); i++) {
		if (tempV[s][i] == target) {
			return true;
		}
	}
	return false;
}

void cal(vector<vector<int>> &tempV) {
	bool flag;
	for (int i = 1; i <= idx; i++) {
		for (int j = 0; j < tempV[i].size(); j++) {
			for (int z = j + 1; z < tempV[i].size(); z++) {
				flag = find_overlap(tempV[i][j], tempV[i][z], tempV);
				// ½Ã³ÊÁö x
				if (flag == false) continue;
				ans = "No";
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> k;
		idx = 1;
		vector<vector<int>> v(k * 3);
		for (int i = 0; i < k; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m[s1] == 0) {
				m[s1] = idx;
				idx++;
			}
			if (m[s2] == 0) {
				m[s2] = idx;
				idx++;
			}
			v[m[s1]].push_back(m[s2]);
			v[m[s2]].push_back(m[s1]);
		}
		ans = "Yes";
		cal(v);
		cout << "#" << tc << " " << ans << '\n';
		m.clear();
	}
}