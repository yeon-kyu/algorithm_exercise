#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k;
vector<string> words;
bool visited[26];
int maxi = 0;

string removeDup(string temp) {
	string str = "";
	int size = temp.size();
	for (int i = 0; i < size; i++) {
		bool flag = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == temp[i]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			str = str + temp[i];
		}
	}
	return str;
}

void checkMaxCount() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		int size = words[i].size();
		for (int j = 0; j < size; j++) {
			if (visited[words[i][j] - 'a'] == false) {//배울 수 없는 단어
				flag = true;
				break;
			}
		}
		if (flag == false) {
			cnt++;
		}
	}
	if (cnt > maxi) {
		maxi = cnt;
	}
}

void checkAllAlphabet(int pos,int cnt) {

	if (cnt == k) {
		checkMaxCount();
		return;
	}

	for (int i = pos; i < 26; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			checkAllAlphabet(i,cnt+1);
			visited[i] = false;
		}
	}

}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		temp = temp.substr(4, temp.length() - 8);

		temp = removeDup(temp);
		
		words.push_back(temp);
	}
	for (int i = 0; i < 26; i++) {
		visited[i] = false;
	}
	//5개의 글자 배움
	visited['a' - 'a'] = true;
	visited['c' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['n' - 'a'] = true;

	if (k < 5) {
		cout << 0;
		return 0;
	}
	k -= 5;

	//알파뱃 어떤걸 허용할지 체크
	checkAllAlphabet(0,0);

	cout << maxi;
		


}