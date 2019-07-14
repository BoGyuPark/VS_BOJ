/*BOJ 1212 8진수 2진수*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str, ans = "";
	cin >> str;
	if (str == "0") cout << 0;
	else {
		for (int i = str.size() - 1; i >= 0; i--) {
			int num = str[i] - '0';
			int cnt = 0;
			while (num != 0) {
				ans += to_string(num % 2);
				num /= 2;
				cnt++;
			}
			if (i != 0) {
				for (int j = cnt; j < 3; j++) {
					ans += "0";
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
}
///*BOJ 1212 8진수 2진수*/
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	string str;
//	cin >> str;
//	if (str == "0") {
//		cout << 0;
//	}
//	else {
//		stack<int> s;
//		for (int i = str.size() - 1; i >= 0; i--) {
//			int num = str[i] - '0';
//			int cnt = 0;
//			while (num != 0) {
//				s.push(num % 2);
//				num /= 2;
//				cnt++;
//			}
//			if (i != 0) {
//				for (int j = cnt; j < 3; j++) {
//					s.push(0);
//				}
//			}
//		}
//		while (!s.empty()) {
//			cout << s.top();
//			s.pop();
//		}
//	}
//	
//}