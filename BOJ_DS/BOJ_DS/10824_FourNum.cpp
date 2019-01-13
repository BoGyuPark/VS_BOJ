//BOJ_10824_FourNum
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	cout << stoll(n1 + n2) + stoll(n3 + n4);
	return 0;
}
//int main()
//{
//	string num1, num2, num3, num4;
//	cin >> num1 >> num2 >> num3 >> num4;
//	num1 += num2;	num3 += num4;
//	stack<char> s1, s2, ans;
//	int num1Len = num1.length(), num3Len = num3.length();
//	for (int i = 0; i < num1Len; i++) {
//		s1.push(num1[i]);
//	}
//	for (int i = 0; i < num3Len; i++) {
//		s2.push(num3[i]);
//	}
//	int maxLen = max(num1Len, num3Len);
//	char t1, t2, carr = 0, result;
//	for (int j = 0; j < maxLen; j++) {
//		if (!s1.empty()) {
//			t1 = s1.top() - '0';
//			s1.pop();
//		}
//		else {
//			t1 = 0;
//		}
//		if (!s2.empty()) {
//			t2 = s2.top() - '0';
//			s2.pop();
//		}
//		else {
//			t2 = 0;
//		}
//
//		if (t1 + t2 + (carr) >= 10) {
//			result = t1 + t2 - 10 + carr;
//			carr = 1;
//		}
//		else {
//			result = t1 + t2 + carr;
//			carr = 0;
//		}
//		ans.push(result + '0');
//		if (j == maxLen - 1 && carr == 1)
//			ans.push('1');
//
//	}
//
//	while(!ans.empty()){
//		char c = ans.top();
//		cout << c;
//		ans.pop();
//	}
//	return 0;
//}