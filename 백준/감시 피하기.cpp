#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
char mat[6][6];
vector<pair<int, int>> emptySpace;

bool isAvoidable(int a, int b, int c) {
	int y1 = emptySpace[a].first;
	int x1 = emptySpace[a].second;
	mat[y1][x1] = 'O';
	int y2 = emptySpace[b].first;
	int x2 = emptySpace[b].second;
	mat[y2][x2] = 'O';
	int y3 = emptySpace[c].first;
	int x3 = emptySpace[c].second;
	mat[y3][x3] = 'O';

	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1, -1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == 'T') {
				// 각각의 4방향에 대해 S를 만나는지 확인
				for (int k = 0; k < 4; k++) {
					int y = i;
					int x = j;
					int cnt = 0;
					while (true) {
						cnt++;
						y += dy[k];
						x += dx[k];
						if (y == N || y < 0 || x == N || x < 0) {
							break;
						}
						if (mat[y][x] == 'O') {
							break;
						}
						else if (mat[y][x] == 'S') {
							mat[y1][x1] = 'X';
							mat[y2][x2] = 'X';
							mat[y3][x3] = 'X';
							return false;
						}
					}
				}
			}
		}
	}

	mat[y1][x1] = 'X';
	mat[y2][x2] = 'X';
	mat[y3][x3] = 'X';

	return true;
}

bool brute() {
	int size = emptySpace.size();
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				if (isAvoidable(i, j, k)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 선생님 T, 학생 S, 장애물 O
	// 3개의 장애물.

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'X') {
				emptySpace.push_back(make_pair(i, j));
			}
		}
	}

	if (brute()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}