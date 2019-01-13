//BOJ_11655_ROT13
#include<bits/stdc++.h>
using namespace std;
int main()
{
	// A = 65 , Z=90
	// a = 97, z = 122
	string s;
	getline(cin, s);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		char temp;
		//대문자인경우
		if (s[i] <= 'Z' && s[i]>='A') {
			if (s[i] + 13 <= 'Z') {
				temp = s[i] + 13;
				cout << temp;
			}
			else {
				temp = s[i] - 13;
				cout << temp;
			}
		}
		else if (s[i] <= 'z' && s[i] >= 'a') {
			if (s[i] + 13 <= 'z') {
				temp = s[i] + 13;
				cout << temp;
			}
			else {
				temp = s[i] - 13;
				cout << temp;
			}
		}
		else
			cout << s[i];
	}
	return 0;
}