#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
vector<string> answer;

void checkValid(string str) {
	int a = 0; //모음 a e i o u
	int b = 0; //자음
	for (int i = 0; i < L; i++) {
		char temp = str[i];
		if ((temp == 'a') || (temp == 'e') || (temp == 'i') || (temp == 'o') || (temp == 'u')) {
			a++;
		}
		else {
			b++;
		}
	}
	if (a >= 1 && b >= 2) {
		sort(str.begin(), str.end());
		answer.push_back(str);
	}
}

void brute(int pos, int cnt, string str) {
	if (cnt == L) {
		checkValid(str);
		return;
	}
	if (pos == C) {
		return;
	}
	//포함 시키는 경우
	brute(pos + 1, cnt + 1, str + v[pos]);
	//포함 안시키는 경우
	brute(pos + 1, cnt, str);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char temp;
		cin >> temp;
		v.push_back(temp);
	}

	brute(0, 0,"");
	sort(answer.begin(), answer.end());
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	
	return 0;
}