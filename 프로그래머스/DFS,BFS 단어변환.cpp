#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v[52];
int wordLen;
int WordsSize;
int dest = -1;
bool visited[52] = { false };

bool compareStr(string a, string b) {
	int cnt = 0;
	for (int i = 0; i<wordLen; i++) {
		if (a[i] != b[i]) {
			cnt++;
		}
	}
	if (cnt == 1)
		return true;
	else {
		return false;
	}
}
int doDFS(int pos) {
	if (pos == dest) {
		return 1;
	}
	int res = 0;
	visited[pos] = true;
	int s = v[pos].size();
	for (int i = 0; i<s; i++) {
		if (visited[v[pos][i]] == false) {
			int temp = doDFS(v[pos][i]);
			if (temp > 0) {
				if (res == 0) {
					res = temp + 1;
				}
				else {
					if (res >= temp + 1)
						res = temp + 1;
				}
			}
			//visited[v[pos][i]] = false;
		}
	}
	return res;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	wordLen = begin.size();
	WordsSize = words.size();

	for (int k = 0; k<WordsSize; k++) {
		if (compareStr(begin, words[k])) {
			v[0].push_back(k + 1);
		}
		if (words[k] == target) {
			dest = k + 1;
			cout << "dest : " << dest << endl;
		}
	}
	if (dest == -1) {
		return 0;
	}

	for (int i = 0; i<WordsSize; i++) {
		string temp = words[i];
		for (int k = 0; k<WordsSize; k++) {
			if (i == k) {}
			else {
				if (compareStr(temp, words[k])) {
					v[i + 1].push_back(k + 1);
				}
			}
		}
	}
	for (int i = 0; i <= WordsSize; i++) {
		int s = v[i].size();
		for (int k = 0; k<s; k++) {
			cout << v[i][k];
			cout << ' ';
		}
		cout << endl;
	}

	answer = doDFS(0); //0번 노드부터 출발
	if (answer > 1) {
		answer--;
	}

	return answer;
}