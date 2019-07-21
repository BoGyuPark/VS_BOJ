/*BOJ 12871 무한 문자열*/
#include<iostream>
#include<string>
using namespace std;
string str1, str2;
int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> str1 >> str2;
	int str1_len = str1.size();
	int str2_len = str2.size();
	if (str1_len == str2_len) {
		cout << (str1 == str2);
	}
	else {
		int lcm = str1_len * str2_len / gcd(str1_len, str2_len);
		string str1_temp = str1;
		string str2_temp = str2;
		while (str1.size() != lcm) {
			str1 += str1_temp;
		}
		while (str2.size() != lcm) {
			str2 += str2_temp;
		}
		cout << (str1 == str2);
	}
}
