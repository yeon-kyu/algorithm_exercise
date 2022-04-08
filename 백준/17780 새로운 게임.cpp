#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, K;
int color[12][12];
struct Hourse {
	int y;
	int x;
	int dir;
};
vector<int> mat[12][12];
vector<Hourse> hourse;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

bool endFlag = false;

void goToWhite(int y, int x, int ny, int nx) {
	vector<int> v = mat[y][x];

	int size = v.size();
	for (int i = 0; i < size; i++) {
		hourse[v[i]].y = ny;
		hourse[v[i]].x = nx;

		mat[ny][nx].push_back(v[i]);
	}
	mat[y][x].clear();

	if (mat[ny][nx].size() >= 4) {
		endFlag = true;
	}
}

void goToRed(int y, int x, int ny, int nx) {
	vector<int> v = mat[y][x];

	int size = v.size();
	for (int i = 0; i < size; i++) {
		hourse[v[i]].y = ny;
		hourse[v[i]].x = nx;

		mat[ny][nx].push_back(v[size - 1 - i]);
	}
	mat[y][x].clear();

	if (mat[ny][nx].size() >= 4) {
		endFlag = true;
	}
}

void goToBlue(int y, int x, int ny, int nx) {

	// 그 반대 칸도 파란색이라면 제자리. 아니라면 이동
	if (ny >= N || ny < 0 || nx >= N || nx < 0 || color[ny][nx] == 2) {
		return;
	}
	
	// 이동
	if (color[ny][nx] == 0) {
		goToWhite(y, x, ny, nx);
	}
	else if (color[ny][nx] == 1) {
		goToRed(y, x, ny, nx);
	}
}

void execute() {
	for (int i = 0; i < K; i++) { //각 말들에 대해 진행
		int y = hourse[i].y;
		int x = hourse[i].x;
		int dir = hourse[i].dir;

		if(mat[y][x][0] != i) { //가장 아래에 있는 말이 아니라면 스킵
			continue;
		}

		int ny = y + dy[dir - 1];
		int nx = x + dx[dir - 1];

		if (ny >= N || ny < 0 || nx >= N || nx < 0 || color[ny][nx] == 2) {
			// 방향 전환
			if (dir == 1)
				dir = 2;
			else if (dir == 2)
				dir = 1;
			else if (dir == 3)
				dir = 4;
			else if (dir == 4)
				dir = 3;

			ny = y + dy[dir - 1];
			nx = x + dx[dir - 1];

			hourse[i].dir = dir;
			goToBlue(y, x, ny, nx);
		}

		else if (color[ny][nx] == 0) { // White
			goToWhite(y, x, ny, nx);
		}
		else if (color[ny][nx] == 1) { // Red
			goToRed(y, x, ny, nx);
		}

		if (endFlag) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		y--; x--;
		hourse.push_back({ y, x, dir });
		mat[y][x].push_back(i);
	}

	int answer = -1;
	for (int i = 1; i <= 1000; i++) {
		execute();
		if (endFlag) {
			answer = i;
			break;
		}
	}
	cout << answer;
}