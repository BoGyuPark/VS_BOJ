//BOJ_10814_SortAge
#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int order;
	int age;
	string name;
}info;

bool cmp(const info &a, const info &b)
{
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		return a.order > b.order;
	}
	else {
		return false;
	}
}

info in[100001];
int main() {
	int n; cin >> n;
	int i = 0, size = n;
	while (n--) {
		int t; string s;
		cin >> t >> s;
		in[i].order = n;
		in[i].age = t;
		in[i].name = s;
		i++;
	}
	sort(in, in + size, cmp);
	for (int i = 0; i < size; i++)
		cout << in[i].age << ' ' << in[i].name << "\n";
	return 0;
}