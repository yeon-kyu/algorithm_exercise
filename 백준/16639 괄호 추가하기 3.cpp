#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N;
int maxi[20][20];
int mini[20][20];

int calc(int a, int b, char c) {
	if (c == '+') {
		return a + b;
	}
	if (c == '-') {
		return a - b;
	}
	if (c == '*') {
		return a * b;
	}
	cout << endl << "Impossible : " << c << endl;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string str;
	cin >> str;

	for (int i = 0; i < N; i += 2) {
		for (int j = 0; j < N; j += 2) {
			maxi[i][j] = INT_MAX;
			mini[i][j] = INT_MIN;
		}
	}

	for (int i = 0; i < N; i += 2) {
		maxi[i][i] = str[i] - '0';
		mini[i][i] = str[i] - '0';
	}

	for (int i = 2; i < N; i += 2) {
		for (int j = 0; j + i < N; j += 2) {
			maxi[j][j + i]; // 구하고자 하는 것
			mini[j][j + i]; // 다음 연산을 위해 구해놓는것

			int curMax = INT_MIN;
			int curMin = INT_MAX;
			for (int k = 0; k < i; k += 2) {
				int temp = calc(maxi[j][j + k], maxi[j + k + 2][j + i], str[j + k + 1]);
				curMax = max(curMax, temp);
				curMin = min(curMin, temp);

				temp = calc(mini[j][j + k], maxi[j + k + 2][j + i], str[j + k + 1]);
				curMax = max(curMax, temp);
				curMin = min(curMin, temp);

				temp = calc(maxi[j][j + k], mini[j + k + 2][j + i], str[j + k + 1]);
				curMax = max(curMax, temp);
				curMin = min(curMin, temp);

				temp = calc(mini[j][j + k], mini[j + k + 2][j + i], str[j + k + 1]);
				curMax = max(curMax, temp);
				curMin = min(curMin, temp);
			}
			maxi[j][j + i] = curMax;
			mini[j][j + i] = curMin;
		}
	}

	cout << maxi[0][N - 1];
}