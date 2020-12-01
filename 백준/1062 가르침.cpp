#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int maxx = 0;
bool alpha[26] = { false };
vector<char> v[50]; //anta와 tica를 제외한 문자들만 넣은것


void push_extra() { //단어를 입력받고 중복되는 단어와 a,n,t,i,c를 제외하여 v에 넣음
	string words[50];
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		int len = words[i].size();
		words[i].erase(len - 4, 4);
		words[i].erase(0, 4);
		
		int new_len = words[i].size();
		vector<char>::iterator it;
		for (int j = 0; j < new_len; j++) {
			char c = words[i][j]; //c : 현재 보는 단어의 해당 문자
			if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') {
				continue;
			}

			it = find(v[i].begin(), v[i].end(), c);
			if (it == v[i].end()) { //해당 문자가 없는거면
				v[i].push_back(words[i][j]);
			}
		}
	}
}

void countwords() { //배울수 있는 최대 단어 계산

	int cnt = 0;

	for (int i = 0; i < n; i++) {//각 단어들에 대해
		bool possible = true;
		int size = v[i].size();
		for (int j = 0; j < size; j++) { //각 단어의 글자들에 대해
			if (alpha[v[i][j] - 'a'] == false) {//하나라도 배운거로 외울수없는 단어면
				possible = false;
			}
		}
		if (possible == true) {
			cnt++;
		}
	}

	//cout << cnt << endl;
	if (cnt > maxx) {
		maxx = cnt;
	}
}

void check_all_alphabet(int cnt,int cur) {
	
	if (cnt == k) { //알파벳 수가 k만큼 됬으면-> 배울수 있는 최대단어 계산
		countwords();
		return;
	}
	else { //알파벳을 더 배워야하면
		for (int i = cur; i < 26; i++) { //사전 순 현재 보고있는 알파벳(cur)이후의 알파벳들 관찰
			if (alpha[i] == false) { //알파벳을 이전에 선택 하지 않았다면
				alpha[i] = true;
				check_all_alphabet(cnt + 1, i); //재귀로 관찰하는 알파벳들을 넣었을때를 생각
				alpha[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> k;

	if (k < 5) {
		cout << 0 << " ";
		return 0;
	}
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	push_extra();
	k -= 5;
	check_all_alphabet(0,0);
	cout << maxx;
}