#include <iostream>
#include<string>
using namespace std;

int main(void) {
	string s;
	string str = "", num = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char t = s[i];
		if (t>='0' && t <= '9') num += t;
		else str += t;
	}
	
	if (str.size() != num.size()) cout << "error";
	else {
		for (int i = 0; i < num.size(); i++) {
			cout << str[i];
			if (num[i] - '0' > 1) cout << num[i];
		}
	}
	return 0;
}