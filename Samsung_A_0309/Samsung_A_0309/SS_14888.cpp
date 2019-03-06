#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[11], mini = 2147483647, maxi = -2147483645;
vector<int> op;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= 4; i++) {
		int temp; cin >> temp;
		while (temp--) {op.push_back(i);}
	}
	do {
		int sum = a[0];
		for (int i = 0; i < op.size(); i++) {
			int state = op[i];
			if (state == 1)	sum += a[i + 1];
			else if (state == 2) sum -= a[i + 1];	
			else if (state == 3) sum *= a[i + 1];
			else sum /= a[i + 1];
		}
		if (sum < mini) mini = sum;
		if (sum > maxi) maxi = sum;
	} while (next_permutation(op.begin(), op.end()));
	cout << maxi << '\n' << mini;
}