//BOJ_1373_ConversionBtoO
#include<bits/stdc++.h>
using namespace std;
//BOJ풀이
int main()
{
	string s; cin >> s;
	int n = s.size();
	if (n % 3 == 1)
		cout << s[0] - '0';
	else if (n % 3 == 2) {
		cout << (s[0] - '0') * 2 + (s[1] - '0');
	}
	for (int i = n % 3; i < n; i += 3)
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	return 0;
}

//나의 풀이
//int main()
//{
//	string s; cin >> s;
//	string a = "";
//	int ans = 0, temp = 1, cnt = 0;
//	for (int i = s.size() - 1; i >= 0; i--) {
//		if (cnt!= 0 && cnt % 3 == 0) {
//			a += (char)(ans + '0');
//			ans = 0;
//			temp = 1;
//		}
//		ans += temp * (s[i] - '0');
//		temp *= 2;
//		cnt++;
//	}
//	a += (char)(ans + '0');
//	reverse(a.begin(), a.end());
//	cout << a;
//	return 0;
//}