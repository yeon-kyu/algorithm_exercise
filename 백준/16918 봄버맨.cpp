#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int R, C, N;
char m[201][201];
char m2[201][201];
char m3[201][201];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1, -1 };

void calcM2() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			m2[i][j] = 'O';
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m[i][j] == 'O') {
				m2[i][j] = '.';
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
						m2[ny][nx] = '.';
					}
				}
			}
		}
	}
}

void calcM3() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			m3[i][j] = 'O';
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m2[i][j] == 'O') {
				m3[i][j] = '.';
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
						m3[ny][nx] = '.';
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			m[i][j] = str[j];
		}
	}

	calcM2();
	calcM3();

	if (N == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << m[i][j];
			}
			cout << '\n';
		}
	}
	else if (N % 4 == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << m3[i][j];
			}
			cout << '\n';
		}
	}
	else if(N%4 == 3) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << m2[i][j];
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << 'O';
			}
			cout << '\n';
		}
	}
}