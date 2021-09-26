#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
int X, Y;
int K;

int mat[21][21];

struct Dice {
	int above = 0;
	int below = 0;
	int left = 0;
	int right = 0;
	int front = 0;
	int back = 0;
};
Dice d;

void rotate_right(){
	int newAbove = d.left;
	int newRight = d.above;
	int newLeft = d.below;
	int newBelow = d.right;

	d.above = newAbove;
	d.right = newRight;
	d.left = newLeft;
	d.below = newBelow;
}

void rotate_left() {
	int newAbove = d.right;
	int newRight = d.below;
	int newLeft = d.above;
	int newBelow = d.left;

	d.above = newAbove;
	d.right = newRight;
	d.left = newLeft;
	d.below = newBelow;
}

void rotate_down() {
	int newAbove = d.back;
	int newFront = d.above;
	int newBelow = d.front;
	int newBack = d.below;

	d.above = newAbove;
	d.front = newFront;
	d.below = newBelow;
	d.back = newBack;
}

void rotate_up() {
	int newAbove = d.front;
	int newFront = d.below;
	int newBelow = d.back;
	int newBack = d.above;

	d.above = newAbove;
	d.front = newFront;
	d.below = newBelow;
	d.back = newBack;
}

void copy_and_paste() {
	if (mat[X][Y] == 0) {
		mat[X][Y] = d.below;
	}
	else {
		d.below = mat[X][Y];
		mat[X][Y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;

		if (dir == 1) { //동쪽
			if (Y + 1 < M) { //오른쪽으로 갈 수 있을때
				rotate_right();
				Y++;
				copy_and_paste();
				cout << d.above << endl;
			}
		}
		else if (dir == 2) { //서쪽
			if (Y - 1 >= 0) {
				rotate_left();
				Y--;
				copy_and_paste();
				cout << d.above << endl;
			}
		}
		else if (dir == 3) { //북쪽
			if (X - 1 >= 0) {
				rotate_up();
				X--;
				copy_and_paste();
				cout << d.above << endl;
			}
		}
		else if (dir == 4) { //남쪽
			if (X + 1 < N) {
				rotate_down();
				X++;
				copy_and_paste();
				cout << d.above << endl;
			}
		}
	}
}