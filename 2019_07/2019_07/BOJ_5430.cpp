/*BOJ 5430 AC*/
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int T, n;
string order, numList;
deque<int> dq;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> order >> n >> numList;
		string s = "";
		if (n != 0) {
			for (int j = 1; j < numList.size(); j++) {
				if (numList[j] != ',' && numList[j] != ']') {
					s += numList[j];
				}
				else {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}
		
		//명령어대로 시뮬레이션
		bool flag = false;
		int reverseFlag = 0;
		for (int j = 0; j < order.size(); j++) {
			//1일때는 뒤집기
			if (order[j] == 'R') {
				reverseFlag = (reverseFlag + 1) % 2;
			}
			else {
				if (dq.size() == 0) {
					cout << "error" << '\n';
					flag = true;
					break;
				}
				else {
					if (reverseFlag == true) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		if (reverseFlag == true) {
			reverse(dq.begin(), dq.end());
		}
		if (flag == false) {
			cout << '[';
			for (int j = 0; j < dq.size(); j++) {
				if (j != dq.size() - 1)	cout << dq[j] << ',';
				else cout << dq[j];
			}
			cout << "]\n";
		}
		dq.clear();
	}
}