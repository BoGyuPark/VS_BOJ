#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int num[12];
vector<int> op;
int main() {
	int n, min = INT_MAX, max = INT_MIN, cal = 0; cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int j = 0; j < 4; j++) {
		int temp; cin >> temp;
		while (temp--) {
			op.push_back(j);
		}
	}
	do {
		cal = num[0];
		for (int i = 1; i <= op.size(); i++) {
			int state = op[i - 1];
			switch (state){
			case 0 :
				cal += num[i];
				break;
			case 1:
				cal -= num[i];
				break;
			case 2:
				cal *= num[i];
				break;
			case 3:
				cal /= num[i];
				break;
			}
		}
		if (min > cal)	min = cal;
		if(max < cal)	max = cal;
	} while (next_permutation(op.begin(), op.end()));
	cout << max << '\n' << min;
	return 0;
}