#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s, now = ""; getline(cin, s);
	vector<string> vs;
	for (char c : s) {
		if (c == ' ' || c == ',' || c == ';') {
			if (now.size() > 0) {
				vs.push_back(now);
				now = "";
			}
		}
		else now += c;
	}
	string b = vs[0];
	for (int i = 1; i < vs.size(); i++) {
		string t = b;
		string x = "";
		for (int j = vs[i].size() - 1; j >= 0; j--) {
			char ct = vs[i][j];
			if ((ct >= 'a' && ct <= 'z') || (ct >= 'A' && ct <= 'Z')) x = ct + x;
			else {
				if (ct == ']') t += '[';
				else if (ct == '[') t += ']';
				else t += ct;
			}
		}
		cout << t << ' ' << x <<';'<< '\n';
	}
}