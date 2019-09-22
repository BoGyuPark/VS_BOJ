/*BOJ 9935 문자열 폭발*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s, pivot;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> pivot;
	char p = pivot[pivot.size() - 1];
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		int jumpCnt = 0;
		int endIdx = v.size() - 1;
		//폭발 문자열과 같다면
		if (v.size() != 0 && c == p) {

			//남은 문자열이 같은지 체크
			for (int j = 0; j < pivot.size() - 1; j++) {
				int Idx = endIdx - pivot.size() + 2 + j;
				if (Idx >= 0 && pivot[j] == v[Idx]) jumpCnt++;
				else break;
			}

			//폭발시킬 문자열 찾음
			if (jumpCnt == pivot.size() - 1) {
				for (int j = 0; j < jumpCnt; j++)	v.pop_back();
			}
			else v.push_back(c);
		}
		else if (c == p && pivot.size() == 1) continue;
		else v.push_back(c);
	}


	if (v.size() == 0) cout << "FRULA";
	else {
		for (auto i : v) cout << i;
	}
}