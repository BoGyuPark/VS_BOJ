#include<iostream>
#include<vector>
#include<string>
using namespace std;
int k, i, j, num[11], visited[11];
string mini, maxi;
char arr[10];
vector<string> sum;
vector<int> selected;
bool check(int n1, int n2, char bu) {
	if (bu == '<')
		return (n1 < n2 ? true : false);
	if(bu=='>')
		return (n1 > n2 ? true : false);
}

void go(int index) {
	if (index == k + 1) {
		string temp = "";
		for (int i = 0; i < selected.size(); i++)
			temp += to_string(selected[i]);
		sum.push_back(temp);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		if (index == 0 || check(selected[index - 1], i, arr[index - 1])) {
			visited[i] = true;
			selected.push_back(i);
			go(index + 1);
			selected.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	cin >> k;
	for (i = 0; i < k; i++)	cin >> arr[i];
	for (i = 0; i < 10; i++) num[i] = i;
	go(0);
	mini = maxi = sum[0];
	for (i = 1; i < sum.size(); i++) {
		if (maxi < sum[i])	maxi = sum[i];
		if (mini > sum[i])	mini = sum[i];
	}
	cout << maxi << "\n" << mini;
}