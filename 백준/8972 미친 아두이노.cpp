#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
char mat[101][101];

struct Pos {
	int y;
	int x;
};

vector<Pos> crazy;
Pos I;

void moveI(int dir) {
	if (dir == 5) {
		//stay
	}
	else if (dir == 1) {
		I.y += 1;
		I.x -= 1;
	}
	else if (dir == 2) {
		I.y += 1;
	}
	else if (dir == 3) {
		I.y += 1;
		I.x += 1;
	}
	else if (dir == 4) {
		I.x -= 1;
	}
	else if (dir == 6) {
		I.x += 1;
	}
	else if (dir == 7) {
		I.y -= 1;
		I.x -= 1;
	}
	else if (dir == 8) {
		I.y -= 1;
	}
	else if (dir == 9) {
		I.y -= 1;
		I.x += 1;
	}
}

void showMat() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			mat[i][j] = '.';
		}
	}

	mat[I.y][I.x] = 'I';
	for (Pos pos : crazy) {
		mat[pos.y][pos.x] = 'R';
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}

}

void play(string move) {
	int size = move.size();
	for (int i = 0; i < size; i++) {
		int dir = move[i] - '0';

		// stage 1
		moveI(dir);

		// stage 2
		// check if meet crazy
		for (Pos pos : crazy) {
			if (pos.y == I.y && pos.x == I.x) {
				cout << "kraj " << i + 1;
				return;
			}
		}

		// stage 3
		// move crazy
		for (Pos& pos : crazy) {
			if (pos.y != I.y) {
				if (I.y - pos.y > 0) {
					pos.y++;
				}
				else {
					pos.y--;
				}
			}
			if (pos.x != I.x) {
				if (I.x - pos.x > 0) {
					pos.x++;
				}
				else {
					pos.x--;
				}
			}
		}

		// stage 4
		// check if meet crazy
		for (Pos pos : crazy) {
			if (pos.y == I.y && pos.x == I.x) {
				cout << "kraj " << i + 1;
				return;
			}
		}

		// stage 5
		// explode crazy
		vector<int> v;
		int visited[10001] = { 0 };
		for (Pos pos : crazy) {
			int n = pos.y * C + pos.x;
			if (visited[n] != 0) {
				v.push_back(n);
			}
			visited[n]++;
		}
		
		int cSize = crazy.size();
		for (int k = 0; k < cSize; k++) {
			int n = crazy[k].y * C + crazy[k].x;
			if (visited[n] >= 2) {
				//cout << "erase " << n << endl;
				crazy.erase(crazy.begin() + k);
				cSize--;k--;
			}
		}
	}
	showMat();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			mat[i][j] = str[j];

			if (mat[i][j] == 'I') {
				I.y = i;
				I.x = j;
			}
			else if (mat[i][j] == 'R') {
				crazy.push_back({ i, j });
			}
		}
	}

	string move;
	cin >> move;

	play(move);
}