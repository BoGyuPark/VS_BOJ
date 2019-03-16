#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int tc = 2;
	vector<string> v1, v2;
	while (tc--) {
		int n;
		cin >> n; 
		// \때문에
		string remainder;
		getline(cin, remainder);

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			if (tc == 1) v1.push_back(s);
			else v2.push_back(s);
		}
	}
	string he = v1[0] + ' ';
	sort(v1.begin(), v1.end());

	int f = false;
	for (int i = 2; i<v2[0].size(); i++) {
		if (f == false) {
			if (v2[0][i] == ' ')	f = true;
		}
		else he += v2[0][i];
	}

	vector<string> ans;
	ans.push_back(he);
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size() - 1; i++) {
		string temp = v1[i]+" ";
		string id = "";
		for (int j = 0; j < v1[i].size(); j++) {
			if (v1[i][j] == ' ') break;
			else id += v1[i][j];
		}

		int found = false;
		for (int z = 0; z < v2.size() - 1; z++) {
			string fk = "";
			for (int x = 0; x < v2[z].size(); x++) {
				if (v2[z][x] == ' ') break;
				else fk += v2[z][x];
			}
			if (id.compare(fk) == 0) {
				found = true;
				int flag = false;
				for (int x = 0; x < v2[z].size(); x++) {
					//헤더가 중복이 될수있다?
					if (flag == false) {
						if (v2[z][x] == ' ') flag = true;
					}
					else temp += v2[z][x];
				}
			}
		}
		//NULL입력
		if (!found) temp += "NULL NULL";
		
		ans.push_back(temp);
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
	return 0;
}