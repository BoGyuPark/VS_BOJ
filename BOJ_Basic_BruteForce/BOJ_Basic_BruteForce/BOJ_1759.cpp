#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<char> v;
int L, C;
bool check(string st) {
	int ja = 0, mo = 0;
	for (int i = 0; i < st.size(); i++) {
		char c = st[i];
		if (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i') {
			mo++;
		}
		else
			ja++;
	}
	if (mo >= 1 && ja >= 2) {
		return true;
	}
	else
		return false;
}

void go(string nowPw, int index) {
	if (nowPw.size() == L) {
		if (check(nowPw)) {
			cout << nowPw << "\n";
			return;
		}
	}
	if (index == C) return;
	go(nowPw + v[index], index + 1);
	go(nowPw, index + 1);
}


int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char temp; cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	go("", 0);
	return 0;
}