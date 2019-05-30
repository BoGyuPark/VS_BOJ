#include<iostream>
#include<string>
using namespace std;
int main() {
	string s, temp;
	while (getline(cin, temp)) {
		s += temp;
		s += '\n';
	}
	s[s.size() - 1] = '\0';
	cout << s << "\n\n";

	int music = 0, image = 0, movie = 0, other = 0;
	
	string subS;
	int idx = 0 , prevIdx = 0;

	while (idx != s.size() - 1) {
		prevIdx = idx;

		idx = s.find("\n", prevIdx + 1);
		if (idx == -1) {
			subS = s.substr(prevIdx + 1);
			idx = s.size() - 1;
		}
		else {
			subS = s.substr(prevIdx + 1, idx - prevIdx - 1);
		}
		//subString을 처리한다.
		int subDot, subEmpty, subB;
		subDot = subS.find_last_of(".");
		subEmpty = subS.find_last_of(" ");
		subB = subS.find_last_of("b");

		string extension = subS.substr(subDot + 1, subEmpty - subDot - 1);
		string value = subS.substr(subEmpty + 1, subB - subEmpty - 1);
		//cout << extension << ' ' << value << '\n';

		if (extension == "mp3" || extension == "aac" || extension == "flac") {
			music += stoi(value);
		}
		else if (extension == "jpg" || extension == "bmp" || extension == "gif") {
			image += stoi(value);
		}
		else if (extension == "mp4" || extension == "avi" || extension == "mkv") {
			movie += stoi(value);
		}
		else {
			other += stoi(value);
		}
		//cout << idx << ' ' << subS << '\n';
	}
	string cata[] = { "music ", "images ", "movies ", "other " };
	int arr[] = { music,image, movie,other };
	string ans = "";
	for (int i = 0; i < 4; i++) {
		ans += cata[i];
		ans += to_string(arr[i]);
		ans += "b\n";
	}
	cout << ans;
}