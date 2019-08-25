/*BOJ 16638 괄호 추가하기 2*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, sel[20], ans = -2147483647;
string s;
vector<string> v, temp;	//연산식
vector<int> num;	
vector<char> op;
int calc(char oper, int t1, int t2) 
{
	switch (oper)
	{
	case '+':
		return t1 + t2;
	case '-':
		return t1 - t2;
	case '*':
		return t1 * t2;
	}
}

void setExpression() 
{
	int opIdx = 0, numIdx = 0;
	int calFlag = false;
	for (opIdx = 0; opIdx < op.size(); opIdx++) {
		if (sel[opIdx] == 0) {
			if(!calFlag) v.push_back(to_string(num[numIdx]));
			v.push_back(string(1, op[opIdx]));
			numIdx++;
			calFlag = false;
		}
		else {
			int t1 = num[numIdx];
			int t2 = num[numIdx + 1];
			int result = calc(op[opIdx], t1, t2);
			v.push_back(to_string(result));
			numIdx++;
			calFlag = true;
		}
	}
	if(!calFlag) v.push_back(to_string(num[numIdx]));
}

void multiCal() 
{
	string prev = v[0];
	temp.push_back(prev);
	for (int i = 1; i < v.size(); i++) 
	{
		if (v[i] == "*") 
		{
			temp.pop_back();
			int t1 = stoi(prev);
			int result = calc(v[i][0], t1, stoi(v[i + 1]));
			i++;
			prev = to_string(result);
			temp.push_back(prev);
		}
		else
		{
			if(v[i]!="+" && v[i]!="-") prev = v[i];
			temp.push_back(v[i]);
		}
	}
}

void solve() 
{
	int sum = stoi(temp[0]);
	for (int i = 1; i < temp.size(); i += 2) {
		sum = calc(temp[i][0], sum, stoi(temp[i + 1]));
	}
	if (ans < sum) ans = sum;
}

void go(int index) {
	if (index == op.size()) {

		//sel이 1인경우 해당 op는 괄호로 계산
		setExpression();
	
		//곱하기 우선 계산
		multiCal();

		//순서대로 계산, temp로 연산
		solve();
		
		v.clear();
		temp.clear();
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (index != 0) {
			if (i == 1 && sel[index - 1] == 1) continue;
			sel[index] = i;
			go(index + 1);
		}
		else {
			sel[index] = i;
			go(index + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//input
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) num.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}
	
	go(0);
	cout << ans;
}