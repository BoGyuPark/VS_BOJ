/*BOJ 16196 중국 신분증 번호*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
string s;
int n;
vector<string> strlist;
int maxDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool isleapYear(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strlist.push_back(temp);
	}

	//추출
	string local, birth, order, checkSum;
	local = s.substr(0, 6);
	birth = s.substr(6, 8);
	order = s.substr(14, 3);
	checkSum = s.substr(17, 1);
	//cout << local << ", " << birth << ", " << order << ", " << checkSum;

	//지역번호 맞는지
	int local_flag = false;
	for (int i = 0; i < strlist.size(); i++) {
		if (strlist[i] == local) {
			local_flag = true;
			break;
		}
	}

	if (!local_flag) {
		cout << "I";
		return 0;
	}

	//생일코드
	string year, month, days;
	year = birth.substr(0, 4);
	month = birth.substr(4, 2);
	days = birth.substr(6, 2);
	//cout << year << ' ' << month << ' ' << days << '\n';
	int birth_flag = false;
	if (year<"1900" || year > "2011") birth_flag = true;
	if (birth_flag) {
		cout << "I";
		return 0;
	}
	if (month < "01" || month > "12") birth_flag = true;
	if (birth_flag) {
		cout << "I";
		return 0;
	}
	// *************윤년과 각 달의 일 체크 해주자.*******************
	if (days < "01" || days > "31") birth_flag = true;
	if (birth_flag) {
		cout << "I";
		return 0;
	}
	int m = stoi(month);
	int d = stoi(days);
	if (isleapYear(stoi(year))) {
		maxDays[2]++;
		if (maxDays[m] < d) birth_flag = true;
	}
	else {
		if (maxDays[m] < d) birth_flag = true;
	}

	if (birth_flag) {
		cout << "I";
		return 0;
	}

	//순서 코드
	if (order == "000") {
		cout << "I";
		return 0;
	}

	//checkSumCode
	long long value = 0;
	for (int i = 0; i < 17; i++) {
		value += (s[i]-'0') * pow(2.0, 17 - i);
		value %= 11;
		//cout << value << '\n';
	}
	int possibleCheckSum;

	if (value == 2) {
		if (checkSum != "X") {
			cout << "I";
			return 0;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if ((value + i) % 11 == 1) {
				if (checkSum != to_string(i)) {
					cout << "I";
					return 0;
				}
			}
		}
	}
	int num = stoi(order);
	if (num % 2 == 0) cout << "F";
	else cout << "M";

	return 0;
}