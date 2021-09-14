#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
int S[21][21];

int min_diff = 987654321;

void getDiff(vector<int> A, vector<int> B) {
	int a_score = 0;
	int b_score = 0;
	for (int i = 0; i < n; i++) {
		bool a_flag = false;
		if (find(A.begin(), A.end(), i) != A.end()) {
			a_flag = true;
		}

		for (int j = 0; j < n; j++) {
			if (find(A.begin(), A.end(), j) != A.end()) { // A에 있다
				if (a_flag) {
					a_score += S[i][j];
				}
				
			}
			else { //B에 있다.
				if (a_flag == false) {
					b_score += S[i][j];
				}

			}
		}
	}
	int diff = a_score - b_score;
	if (diff < 0) {
		diff = diff * -1;
	}

	min_diff = min(min_diff, diff);
}

void brute(int pos, vector<int> A, vector<int> B) {
	if (A.size() == n / 2) { //종결조건 1
		for (int i = pos; i < n; i++) {
			B.push_back(i);
		}
		getDiff(A, B);
		return;
	}
	if (B.size() == n / 2) { //종결조건 2
		for (int i = pos; i < n; i++) {
			A.push_back(i);
		}
		getDiff(A, B);
		return;
	}

	B.push_back(pos);
	brute(pos + 1, A, B); // A팀에 안넣는 경우

	A.push_back(pos);
	B.erase(B.end() - 1);
	brute(pos + 1, A, B); // A팀에 넣는 경우	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> S[i][j];
		}
	}
	vector<int> v;
	brute(0, v, v);
	
	cout << min_diff;
}