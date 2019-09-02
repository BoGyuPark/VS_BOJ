/* BOJ 2607 비슷한 단어*/
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int n, pivotNumCnt[27], cmpNumCnt[27], ans;
string s;
vector<string> s_list;
int isPossible() {
	int difCnt = 0, cnt = 0;
	int remainCnt = 0, lackCnt = 0;
	for (int j = 0; j < 26; j++) {
		if (pivotNumCnt[j] != cmpNumCnt[j]) {
			difCnt = pivotNumCnt[j] - cmpNumCnt[j];
			if (difCnt > 1) return -1;
			else if (difCnt == 1) lackCnt++;
			else if (difCnt == -1) remainCnt++;
		}
	}
	
	if (lackCnt == 1 && remainCnt == 1) return 2;
	if (lackCnt == 1 && remainCnt == 0 || 
		lackCnt == 0 && remainCnt == 1) return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		string t = ""; cin >> t;
		s_list.push_back(t);
	}

	//첫번째 문자의 알파벳과 갯수를 파악
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		pivotNumCnt[c - 'A']++;
	}

	//나머지 문자들과 첫번째 문자의 알파벳과 갯수를 비교
	for (int i = 0; i < n - 1; i++) {
		string t = s_list[i];

		//길이가 2이상 차이나는 경우
		if (abs((int)s.size() - (int)t.size()) > 1) continue;

		//비교할 문자 알파벳과 갯수 카운트
		memset(cmpNumCnt, 0, sizeof(cmpNumCnt));
		for (int j = 0; j < t.size(); j++) {
			char c = t[j];
			cmpNumCnt[c - 'A']++;
		}

		//문자의 길이가 같을때, 문자 바꾸기
		if (s.size() == t.size()) {
			if (isPossible() == 2) ans++;	
		}
		//문자의 길이 차이가 1인 경우, 문자 추가 or 빼기
		else {
			if (isPossible() == 1) ans++;
		}
	}
	cout << ans;
}