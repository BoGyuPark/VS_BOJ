/*BOJ 1373 2진수 8진수*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str, ans = "";
	cin >> str;
	int lack_cnt = 0;
	if (str.size() % 3 != 0) {
		lack_cnt = 3 - str.size() % 3;
		while (lack_cnt--) {
			str = "0" + str;
		}
	}
	for(int i=0; i<str.size(); i+=3){
		int result = (str[i] - '0') * 4 + 
			(str[i+1] - '0') * 2 + (str[i+2] - '0') * 1;
		ans += to_string(result);
	}
	cout << ans;
}