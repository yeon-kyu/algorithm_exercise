#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Q;

int n = 1;
int mat[65][65];
bool visited[65][65];
int L[1001];
int sum = 0;

struct posInfo {
	int y, x;
};
int dy[4] = { 1,-1, 0,0 };
int dx[4] = { 0,0,1,-1 };

void init() {
	int N;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		n = n * 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
	}
}

void refresh_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void rotate_part(int row, int col, int len) {
	vector<vector<int>> v;

	for (int i = 0; i < len; i++) {
		vector<int> temp;
		for (int j = 0; j < len; j++) {
			temp.push_back(mat[row + i][col + j]);
		}
		v.push_back(temp);
	}

	//r,c -> c, len-1-r
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			mat[row + i][col + j] = v[len-1-j][i];
		}
	}
}


void rotate(int len) {
	//len : 부분격자의 길이
	int num = n / len; //부분격자의 수
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int row = i * len;
			int col = j * len;
			rotate_part(row, col, len);
		}
	}
}

bool beMelt(int r, int c) {
	if (mat[r][c] > 0) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = r + dy[i];
			int nx = c + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (mat[ny][nx] > 0) {
					cnt++;
				}
			}
		}

		if (cnt <= 2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void fireStorm(int k) {
	int unit = 1; //부분격자의 크기
	for (int i = 0; i < L[k]; i++) {
		unit = unit * 2;
	}

	rotate(unit);

	//melt
	vector<posInfo> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (beMelt(i, j) == true) {
				v.push_back({ i,j });
			}
		}
	}

	for (vector<posInfo>::iterator it = v.begin(); it != v.end(); it++) {
		mat[it->y][it->x]--;
	}
}

void getSumOfIce() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += mat[i][j];
		}
	}
	cout << sum <<'\n';
}

void getBiggestIce(int start_y, int start_x) {

	if (visited[start_y][start_x] == true) {
		return;
	}
	if (mat[start_y][start_x] == 0) {
		return;
	}

	int cnt = 1;
	queue<posInfo> q;
	q.push({ start_y, start_x });
	visited[start_y][start_x] = true;

	while (!q.empty()) {
		posInfo temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (mat[ny][nx] > 0 && visited[ny][nx] == false) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
					cnt++;
				}
			}
		}
	}
	if (cnt > sum) {
		sum = cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//모든 부분 격자 회전
	//파이어스톰 q번 시전

	//남아있는 얼음의 합
	//얼음 중 가장 큰 덩어리가 차지한는 칸의 수

	init();

	for (int i = 0; i < Q; i++) {
		fireStorm(i);
	}
	
	getSumOfIce();

	refresh_visited();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			getBiggestIce(i, j);
		}
	}
	cout << sum;
}