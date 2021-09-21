#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct dir_info {
	int time;
	char dir;
};
struct pos_info {
	int row;
	int col;
};

int N, K, L;
int mat[101][101];
vector<dir_info> dir;
int cur_dir = 1; // 1: 오른쪽, 2: 아래, 3: 왼쪽, 4: 위
int cur_time = 0;

int head_r = 0;
int head_c = 0;

vector<pos_info> pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = 0; //빈 공간 세팅
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		mat[a - 1][b - 1] = 1; //사과의 공간 세팅
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		dir.push_back({ X,C }); //뱀의 방향 정보 저장
	}

	pos.push_back({ 0,0 }); //뱀의 첫 위치 저장

	while (true) {
		//시간 경과
		cur_time++;

		//머리 움직임
		if (cur_dir == 1) {
			head_c++;
		}
		else if (cur_dir == 2) {
			head_r++;
		}
		else if (cur_dir == 3) {
			head_c--;
		}
		else if (cur_dir == 4) {
			head_r--;
		}
		pos.push_back({ head_r, head_c });

		//움직인 자리가 어떤지 파악
		// 1. 벽인 경우
		if (head_r >= N || head_r < 0 || head_c >= N || head_c < 0) {
			break;
		}
		// 2. 자기 자신인 경우
		else if (mat[head_r][head_c] == -1) {
			break;
		}
		// 3. 사과인 경우
		else if (mat[head_r][head_c] == 1) {
			mat[head_r][head_c] = -1;
			//pos.push_back({ head_r, head_c });
		}
		// 4. 그냥 빈 공간인 경우
		else if (mat[head_r][head_c] == 0) {
			mat[head_r][head_c] = -1;
			//pos.push_back({ head_r, head_c });

			int tail_r = pos[0].row;
			int tail_c = pos[0].col;
			mat[tail_r][tail_c] = 0;

			pos.erase(pos.begin());
			//cout << head_r << "행" << head_c << "열에서 짤리는 꼬리 : " << tail_r << ' ' << tail_c << endl;
		}

		//방향 전환
		if (dir.size() == 0) {
			continue;
		}
		else if (dir[0].time == cur_time) {
			char C = dir[0].dir;
			if (C == 'D') {
				cur_dir++;
				if (cur_dir == 5) {
					cur_dir = 1;
				}
			}
			else if (C == 'L') {
				cur_dir--;
				if (cur_dir == 0) {
					cur_dir = 4;
				}
			}

			dir.erase(dir.begin());
		}
	}
	cout << cur_time;
}