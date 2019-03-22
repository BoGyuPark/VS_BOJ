#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void inorder(char arr[], string &s, int start) {
	if (start <= 101 && arr[start] != '\0') {
		inorder(arr, s, start * 2);
		s += arr[start];
		inorder(arr, s, start * 2 + 1);
	}
}
int main() {
	for (int tc = 1; tc <= 1; tc++) {
		int n; cin >> n; cin.ignore();
		char arr[101] = { 0, };
		for (int i = 1; i <= n; i++) {
			string s; getline(cin, s);
			char t[101] = { 0, };
			for (int j = 0; j < s.size(); j++) t[j] = s[j];
			char *ptr = strtok(t, " ");
			ptr = strtok(NULL, " ");
			int first = true;
			while (ptr != NULL) {
				if (first) {
					arr[i] = *ptr;
					first = false;
				}
				ptr = strtok(NULL, " ");
			}
		}
		string str = "";
		inorder(arr,str, 1);
		cout << '#' << tc << ' ' << str << '\n';
		for (int i = 0; i < 101; i++) arr[i] = 0;
	}
}