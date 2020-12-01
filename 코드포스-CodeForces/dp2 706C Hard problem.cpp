#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
int c[100001];
vector<string> s;
vector<string> s_r;//reverse
long long e[100001][2] = { 0 }; //total energy
								//string s[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	string temp;
	string reverse;
	s.push_back("");
	s_r.push_back("");
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		reverse = temp;
		s.push_back(temp);
		int size = temp.size();
		for (int z = 0; z < size; z++) {
			reverse[z] = temp[size - 1 - z];
		}
		s_r.push_back(reverse);
	}
	e[1][0] = 0; e[1][1] = c[1];
	long long cs[4];
	for (int i = 2; i <= n; i++) {

		//원본-원본
		if (s[i - 1] <= s[i] && e[i - 1][0] >= 0) {
			cs[0] = e[i - 1][0];
		}
		else cs[0] = -1;
	
		//원본-거꾸로
		if (s[i - 1] <= s_r[i] && e[i - 1][0] >= 0) {
			cs[1] = e[i - 1][0] + c[i];
		}
		else cs[1] = -1;
		
		//거꾸로-원본
		if (s_r[i - 1] <= s[i] && e[i - 1][1] >= 0) {
			cs[2] = e[i - 1][1];
		}
		else cs[2] = -1;

		//거꾸로-거꾸로
		if (s_r[i - 1] <= s_r[i] && e[i - 1][1] >= 0) {
			cs[3] = e[i - 1][1] + c[i];
		}
		else cs[3] = -1;

		//i번째를 원본으로 했을 때
		e[i][0] = min(cs[0], cs[2]);
		if (e[i][0] == -1) {
			e[i][0] = max(cs[0], cs[2]);
		}

		//i번째를 거꾸로했을때
		e[i][1] = min(cs[1], cs[3]);
		if (e[i][1] == -1) {
			e[i][1] = max(cs[1], cs[3]);
		}
		//cout << cs[0] << " " << cs[1] << " " << cs[2] << " " << cs[3] << endl;
		//cout << e[i][0]<<" "<< e[i][1] << endl;;
	}
	long long ans = min(e[n][0], e[n][1]);
	if (ans == -1) ans = max(e[n][0], e[n][1]);
	cout << ans;
}