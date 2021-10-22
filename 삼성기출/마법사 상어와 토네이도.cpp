#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int mat[500][500];

int y, x;
int ans = 0;

//왼,아래,오른,위
int dx[4] = { -1, 0, 1,0 };
int dy[4] = { 0,1,0, -1 };

// 7 7 10 10 1 1 2 2 5 a 순서
int xdx[4][10] = { {0,0,-1,-1,1,1,0,0,-2,-1},
					{-1,1,-1,1,-1,1,-2,2,0,0},
					{0,0,1,1,-1,-1,0,0,2,1},
					{1,-1,1,-1,1,-1,2,-2,0,0} };

int ydy[4][10] = { {-1,1,-1,1,-1,1,-2,2,0,0},
					{0,0,1,1,-1,-1,0,0,2,1},
					{1,-1,1,-1,1,-1,2,-2,0,0},
					{0,0,-1,-1,1,1,0,0,-2,-1} };

int per[9] = { 7,7,10,10,1,1,2,2,5 };


void moveTonado(int dir) {
	//dir 0:왼쪽, 1:아래, 2:오른쪽, 3:위
	x += dx[dir];
	y += dy[dir];
	int send = mat[y][x];
	mat[y][x] = 0;

	int added = 0;
	
	for (int i = 0; i < 9; i++) {
		int nx = x + xdx[dir][i];
		int ny = y + ydy[dir][i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			mat[ny][nx] += send * per[i] / 100;
			added += send * per[i] / 100;
		}
		else {
			ans += send * per[i] / 100;
			added += send * per[i] / 100;
		}
	}
	int nx = x + xdx[dir][9];
	int ny = y + ydy[dir][9];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
		mat[ny][nx] += send - added;
	}
	else {
		ans += send - added;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	x = y = N / 2;
	int dir = 0;
	int cnt = 1;

	while (true) {
		bool flag = false;
		for (int i = 0; i < cnt; i++) {
			if (x == 0 && y == 0) {
				flag = true;
				break;
			}
			moveTonado(dir);
		}
		dir = (dir + 1) % 4;

		for (int i = 0; i < cnt; i++) {
			if (x == 0 && y == 0) {
				flag = true;
				break;
			}
			moveTonado(dir);
		}
		dir = (dir + 1) % 4;
		cnt++;

		if (flag == true) {
			break;
		}
	}

	cout << ans;
	
}